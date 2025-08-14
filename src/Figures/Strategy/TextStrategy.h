#pragma once

#include <string>

#include "../IShapeStrategy.h"

class TextStrategy : public IShapeStrategy {
   public:
    TextStrategy(double x, double y, double font, std::string text)
        : _X(x), _Y(y), _FontSize(font), _Text(std::move(text)) {}

    void Draw(gfx::ICanvas& canvas) const override { canvas.DrawText(_X, _Y, _FontSize, _Text); }

    std::string GetTypeName() const override { return "Text"; }

    std::string GetParametersInfo() const override {
        return (std::to_string(_X) + " " + std::to_string(_Y) + " " + std::to_string(_FontSize) +
                " " + std::to_string(_Text));
    }

    std::unique_ptr<IShapeStrategy> Clone() const override {
        return std::make_unique<TextStrategy>(_X, _Y, _FontSize, _Text);
    }

   private:
    double _X;
    double _Y;
    double _FontSize;
    std::string _Text;
};