#pragma once

#include <string>

#include "../IShapeStrategy.h"

class TriangleStrategy : public IShapeStrategy {
   public:
    TriangleStrategy(double x1, double y1, double x2, double y2, double x3, double y3)
        : _X1(x1), _Y1(y1), _X2(x2), _Y2(y2), _X3(x3), _Y3(y3) {};

    void Draw(gfx::ICanvas& canvas) const override {
        canvas.MoveTo(_X1, _Y1);
        canvas.LineTo(_X2, _Y2);
        canvas.LineTo(_X3, _Y3);
        canvas.LineTo(_X1, _Y1);
    }

    std::string GetTypeName() const override { return "Triangle"; }

    std::string GetParametersInfo() const override {
        return (std::to_string(_X1) + " " + std::to_string(_Y1) + " " + std::to_string(_X2) + " " +
                std::to_string(_Y2) + " " + std::to_string(_X3) + " " + std::to_string(_Y3));
    }

    std::unique_ptr<IShapeStrategy> Clone() const override {
        return std::make_unique<TriangleStrategy>(*this);
    }

   private:
    double _X1;
    double _Y1;
    double _X2;
    double _Y2;
    double _X3;
    double _Y3;
};
