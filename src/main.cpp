#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

#include "Canvas/SFMLCanvas.h"
#include "Figures/CircleStrategy.h"
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

    std::vector<shapes::Shape> picture;

    picture.emplace_back("sh1",
                         gfx::Color::FromString("#FF0000"),  // Красный
                         std::make_unique<CircleStrategy>(200, 200, 50));
    picture.emplace_back("sh2",
                         gfx::Color::FromString("#00FF00"),  // Зеленый
                         std::make_unique<CircleStrategy>(450, 350, 80));

    // Создаем конкретную реализацию холста для SFML
    gfx::SFMLCanvas canvas(window, font);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::Black);
        for (const auto& shape : picture) {
            shape.Draw(canvas);
        }

        // DrawOnAnyCanvas(canvas);

        window.display();
    }

    return 0;
}
