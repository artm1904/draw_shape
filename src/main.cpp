#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
    // 1. Создаем окно
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Shapes Program");

    // 2. Готовим объекты для рисования
    // Окружность (можно сделать эллипсом, меняя масштаб)
    sf::CircleShape circle(50.f);
    circle.setPosition(100, 100);
    circle.setFillColor(sf::Color::Green);

    // Линия (рисуется как массив из двух вершин)
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(300, 300)),
        sf::Vertex(sf::Vector2f(500, 550))
    };
    line[0].color = sf::Color::Red;
    line[1].color = sf::Color::Red;

    // Текст
    sf::Font font;
    // Важно: SFML нужен файл шрифта. Скачайте любой .ttf, например, Arial.
    // Теперь путь стал простым и надежным, так как CMake копирует папку fonts
    // в директорию с исполняемым файлом.
    if (!font.loadFromFile("fonts/monogram.ttf"))
    {
        // обработка ошибки
        return -1;
    }
    sf::Text text("Hello, SFML!", font, 24);
    text.setPosition(400, 50);
    text.setFillColor(sf::Color::Yellow);


    // 3. Главный цикл программы (работает, пока окно открыто)
    while (window.isOpen())
    {
        // Обработка событий (нажатия клавиш, закрытие окна)
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            // Сохраняем скриншот по нажатию на 'S'
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
            {
                sf::Texture texture;
                texture.create(window.getSize().x, window.getSize().y);
                texture.update(window);
                if (texture.copyToImage().saveToFile("screenshot.png"))
                {
                    std::cout << "Screenshot saved to screenshot.png" << std::endl;
                }
            }
        }

        // 4. Отрисовка
        window.clear(sf::Color::Black); // Очищаем окно черным цветом

        window.draw(circle);
        window.draw(line, 2, sf::Lines);
        window.draw(text);

        window.display(); // Показываем нарисованное
    }

    return 0;
}
