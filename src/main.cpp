#include <SFML/Graphics.hpp>
#include <iostream>

#include "Canvas/Color.h" // Подключаем наш заголовочный файл с цветом

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "My Shapes Program");

    // 1. Создаем цвет, используя ваш класс и парсер
    gfx::Color myOrange = gfx::Color::FromString("#FF8C00"); // Темно-оранжевый

    sf::CircleShape circle(50.f);
    circle.setPosition(100, 100);

    // 2. Используем наш объект gfx::Color напрямую с SFML!
    // Компилятор автоматически вызовет оператор преобразования.
    circle.setFillColor(myOrange);



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

 
        window.clear(sf::Color::Black); 

        window.draw(circle);


        window.display();
    }

    return 0;
}
