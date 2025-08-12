#pragma once

#include <string>

#include "IShapeStrategy.h"

class RectangleStrategy : public IShapeStrategy {
   public:
    RectangleStrategy(double x, double y, double width, double height)
        : _X(x), _Y(y), _Width(width), _Height(height) {}

    void Draw(gfx::ICanvas& canvas) const override {
        canvas.DrawRectangle(_X, _Y, _Width, _Height);
    }

    std::string GetTypeName() const override { return "Rectangle"; }

    std::string GetParametrsInfo() const override {
        return (std::to_string(_X) + " " + std::to_string(_Y) + " " + std::to_string(_Width) + " " +
                std::to_string(_Height));
    }

    std::unique_ptr<IShapeStrategy> Clone() const override {
        return std::make_unique<RectangleStrategy>(_X, _Y, _Width, _Height);
    }

   private:
    double _X;
    double _Y;
    double _Width;
    double _Height;
};