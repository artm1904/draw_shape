#include "ShapeFactory.h"

#include "Strategy/CircleStrategy.h"
#include "Strategy/LineStrategy.h"
#include "Strategy/RectangleStrategy.h"
#include "Strategy/TextStrategy.h"
#include "Strategy/TriangleStrategy.h"

ShapeFactory::ShapeFactory() {
    _StrategyFactories["circle"] = [](std::istream& args) -> std::unique_ptr<IShapeStrategy> {
        double x, y, r;
        if (args >> x >> y >> r) {
            return std::make_unique<CircleStrategy>(x, y, r);
        }
        return nullptr;
    };

    _StrategyFactories["rectangle"] = [](std::istream& args) -> std::unique_ptr<IShapeStrategy> {
        double x, y, w, h;
        if (args >> x >> y >> w >> h) {
            return std::make_unique<RectangleStrategy>(x, y, w, h);
        }
        return nullptr;
    };

    _StrategyFactories["triangle"] = [](std::istream& args) -> std::unique_ptr<IShapeStrategy> {
        double x1, y1, x2, y2, x3, y3;
        if (args >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
            return std::make_unique<TriangleStrategy>(x1, y1, x2, y2, x3, y3);
        }
        return nullptr;
    };

    _StrategyFactories["line"] = [](std::istream& args) -> std::unique_ptr<IShapeStrategy> {
        double x1, y1, x2, y2;
        if (args >> x1 >> y1 >> x2 >> y2) {
            return std::make_unique<LineStrategy>(x1, y1, x2, y2);
        }
        return nullptr;
    };

    _StrategyFactories["text"] = [](std::istream& args) -> std::unique_ptr<IShapeStrategy> {
        double x, y, font;
        std::string text;
        if (args >> x >> y >> font) {
            // Пропускаем пробел после числа и читаем всю оставшуюся часть строки
            std::getline(args >> std::ws, text);
            if (!text.empty()) {
                return std::make_unique<TextStrategy>(x, y, font, text);
            }
        }
        return nullptr;
    };
}

std::unique_ptr<IShapeStrategy> ShapeFactory::CreateShape(const std::string& description,
                                                          std::istream& args) {
    auto it = _StrategyFactories.find(description);
    return (it != _StrategyFactories.end()) ? it->second(args) : nullptr;
}
