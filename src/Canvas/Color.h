#pragma once

#include <SFML/Graphics/Color.hpp>
#include <charconv>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdint>


namespace gfx {

struct Color {
    uint8_t R = 0;
    uint8_t G = 0;
    uint8_t B = 0;

    // Конструктор по умолчанию (создает черный цвет)
    Color() = default;

    // Конструктор для создания цвета из компонентов
    constexpr Color(uint8_t red, uint8_t green, uint8_t blue) : R(red), G(green), B(blue) {}

    // Статический фабричный метод для парсинга строки
    static Color FromString(const std::string& hexColor) {
        if (hexColor.length() != 7 || hexColor[0] != '#') {
            throw std::invalid_argument("Invalid color format. Expected #RRGGBB.");
        }

        uint8_t r_val, g_val, b_val;
        const char* start = hexColor.data() + 1;
        const char* end = hexColor.data() + 7;

        // Используем std::from_chars для эффективного, не выбрасывающего исключения, парсинга
        auto res_r = std::from_chars(start, start + 2, r_val, 16);
        auto res_g = std::from_chars(start + 2, start + 4, g_val, 16);
        auto res_b = std::from_chars(start + 4, end, b_val, 16);

        // Проверяем, что все три компонента были успешно распознаны
        if (res_r.ec != std::errc() || res_g.ec != std::errc() || res_b.ec != std::errc()) {
            throw std::invalid_argument("Invalid hex value in color string.");
        }

        return Color{r_val, g_val, b_val};
    }

    std::string ToString() const {
        std::stringstream ss;
        ss << '#' << std::hex << std::setfill('0')
           << std::setw(2) << static_cast<int>(R)
           << std::setw(2) << static_cast<int>(G)
           << std::setw(2) << static_cast<int>(B);
        return ss.str();
    }

    // Оператор преобразования в sf::Color
    // Позволяет использовать gfx::Color там, где ожидается sf::Color
    operator sf::Color() const { return sf::Color(R, G, B); }
};
}  // namespace gfx