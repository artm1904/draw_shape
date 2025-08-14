#include <SFML/Graphics.hpp>
#include <atomic>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

#include "Canvas/SFMLCanvas.h"
#include "Commands/CommandParser.h"
#include "Commands/ICommand.h"
#include "Shape/Picture.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Program");

    sf::Font font;
    if (!font.loadFromFile("fonts/monogram.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return -1;
    }

    // Создаем текстуру, на которой будет происходить "накопительное" рисование
    sf::RenderTexture canvasTexture;
    canvasTexture.create(window.getSize().x, window.getSize().y);
    canvasTexture.clear(sf::Color::White);  // Начальный фон - белый

    // Наш холст теперь рисует на текстуре, а не прямо в окне
    gfx::SFMLCanvas canvas(canvasTexture, font);
    Picture picture;
    CommandParser parser(picture, canvas);

    std::queue<std::unique_ptr<ICommand>> commandQueue;
    std::mutex queueMutex;
    std::atomic<bool> done = false;

    // Главный цикл теперь обрабатывает команды из консоли
    std::thread commandThread([&]() {
        std::string line;
        while (!done && std::cout << "> " && std::getline(std::cin, line)) {
            if (line.empty()) continue;

            if (auto command = parser.ParseCommand(line)) {
                std::lock_guard<std::mutex> lock(queueMutex);
                commandQueue.push(std::move(command));
            }
        }
    });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Обрабатываем команды из очереди в главном потоке
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            while (!commandQueue.empty()) {
                auto command = std::move(commandQueue.front());
                commandQueue.pop();
                command->Execute();  // Безопасно выполняем команду здесь
            }
        }

        // Отображаем результат
        window.clear();
        canvasTexture.display();  // Завершаем рисование на текстуре
        sf::Sprite canvasSprite(canvasTexture.getTexture());
        window.draw(canvasSprite);  // Рисуем текстуру в окне

        window.display();
    }
    done = true;
    commandThread.detach();  // В учебном проекте detach допустим для простоты завершения
    return 0;
}
