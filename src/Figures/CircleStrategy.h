#pragma once

#include <string>

#include "IShapeStrategy.h"

class CircleStrategy : public IShapeStrategy {
   public:
    CircleStrategy(double x, double y, double radius) : _X(x), _Y(y), _Radius(radius) {}

    void Draw(gfx::ICanvas& canvas) const override { canvas.DrawEllipse(_X, _Y, _Radius, _Radius); }

    std::string GetTypeName() const override { return "Circle"; }

    std::string GetParametersInfo() const override {
        return (std::to_string(_X) + " " + std::to_string(_Y) + " " + std::to_string(_Radius));
    }

    std::unique_ptr<IShapeStrategy> Clone() const override {
        return std::make_unique<CircleStrategy>(_X, _Y, _Radius);
    }

   private:
    double _X;
    double _Y;
    double _Radius;
};