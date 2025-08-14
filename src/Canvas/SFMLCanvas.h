#pragma once

#include <SFML/Graphics.hpp>

#include "ICanvas.h"

namespace gfx {

class SFMLCanvas : public ICanvas {
   public:
    // Конструктор принимает цель для рисования (окно) и шрифт
    SFMLCanvas(sf::RenderTarget& target, const sf::Font& font) : m_target(target), m_font(font) {}

    void SetColor(Color c) override {
        // Используем неявное преобразование gfx::Color в sf::Color
        m_currentColor = c;
    }

    void MoveTo(double x, double y) override {
        m_currentPosition.x = static_cast<float>(x);
        m_currentPosition.y = static_cast<float>(y);
    }

    void LineTo(double x, double y) override {
        sf::Vertex line[] = {
            sf::Vertex(m_currentPosition, m_currentColor),
            sf::Vertex(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), m_currentColor)};
        m_target.draw(line, 2, sf::Lines);
        MoveTo(x, y);
    }

    void DrawEllipse(double cx, double cy, double rx, double ry) override {
        sf::CircleShape ellipse(1.0f);
        ellipse.setOrigin(1.0f, 1.0f);
        ellipse.setPosition(static_cast<float>(cx), static_cast<float>(cy));
        ellipse.setScale(static_cast<float>(rx), static_cast<float>(ry));
        ellipse.setFillColor(m_currentColor);
        m_target.draw(ellipse);
    }

    void DrawText(double left, double top, double fontSize, const std::string& text) override {
        sf::Text sfText(text, m_font, static_cast<unsigned int>(fontSize));
        sfText.setPosition(static_cast<float>(left), static_cast<float>(top));
        sfText.setFillColor(m_currentColor);
        m_target.draw(sfText);
    }

   private:
    sf::RenderTarget& m_target;
    const sf::Font& m_font;
    sf::Color m_currentColor = sf::Color::Black;
    sf::Vector2f m_currentPosition{0, 0};
};

}  // namespace gfx
