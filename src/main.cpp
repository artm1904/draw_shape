#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

#include "Canvas/SFMLCanvas.h"
#include "Commands/CommandParser.h"
#include "Figures/CircleStrategy.h"
#include "Figures/RectangleStrategy.h"
#include "Figures/TriangleStrategy.h"
#include "Shape/Picture.h"
#include "Shape/Shape.h"

void DrawOnAnyCanvas(gfx::ICanvas& canvas) {
    // Рисуем красный прямоугольник с помощью линий
    canvas.SetColor(gfx::Color::FromString("#FF0000"));
    canvas.MoveTo(200, 200);
    canvas.LineTo(400, 200);
    canvas.LineTo(400, 300);
    canvas.LineTo(200, 300);
    canvas.LineTo(200, 200);

    canvas.SetColor(gfx::Color::FromString("#0000FF"));
    canvas.DrawEllipse(500, 400, 80, 40);

    canvas.SetColor(gfx::Color::FromString("#FFFFFF"));
    canvas.DrawText(50, 50, 24, "Drawing via ICanvas interface!");
}

int main() {
    sf::RenderWindow window(
        sf::RenderWindow(sf::VideoMode(800, 600), "Shapes Program - ICanvas Demo"));

    sf::Font font;
    if (!font.loadFromFile("fonts/monogram.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return -1;
    }

    // Создаем конкретную реализацию холста для SFML
    gfx::SFMLCanvas canvas(window, font);
    Picture picture;
    CommandParser parser(picture, canvas);

    // Главный цикл теперь обрабатывает команды из консоли
    std::thread commandThread([&]() {
        std::string line;
        while (std::cout << "> " && std::getline(std::cin, line)) {
            if (auto command = parser.ParseCommand(line); command != nullptr) {
                command->Execute();
            }
        }
    });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::White);

       
        // DrawOnAnyCanvas(canvas);

        window.display();
    }
    commandThread.detach();  // Отсоединяем поток при выходе
    return 0;
}
