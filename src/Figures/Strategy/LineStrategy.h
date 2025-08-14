#pragma once

#include <string>

#include "../IShapeStrategy.h"

class LineStrategy : public IShapeStrategy {
   public:
    LineStrategy(double x1, double y1, double x2, double y2)
        : _X1(x1), _Y1(y1), _X2(x2), _Y2(y2) {}

    void Draw(gfx::ICanvas& canvas) const override {
        canvas.MoveTo(_X1, _Y1);
        canvas.LineTo(_X2, _Y2);

        
    }

    void Move(double dx, double dy) override { _X1 += dx; _Y1 += dy; _X2 += dx; _Y2 += dy; }

    std::string GetTypeName() const override { return "Line"; }

    std::string GetParametersInfo() const override {
        return (std::to_string(_X1) + " " + std::to_string(_Y1) + " " + std::to_string(_X2) + " " +
                std::to_string(_Y2));
       
    }

    std::unique_ptr<IShapeStrategy> Clone() const override {
        return std::make_unique<LineStrategy>(_X1, _Y1, _X2, _Y2);
    }

   private:
    double _X1;
    double _Y1;
    double _X2;
    double _Y2;
};