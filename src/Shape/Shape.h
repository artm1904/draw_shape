#pragma once

#include <memory>
#include <string>

#include "../Canvas/Color.h"
#include "../Figures/IShapeStrategy.h"

namespace shapes {

class Shape {
   public:
    Shape(std::string id, gfx::Color color, std::unique_ptr<IShapeStrategy> strategy)
        : _Id(id), _Color(std::move(color)), _Strategy(std::move(strategy)) {}

    void Draw(gfx::ICanvas& canvas) const {
        canvas.SetColor(_Color);
        _Strategy->Draw(canvas);
    }

    void SetStrategy(std::unique_ptr<IShapeStrategy> strategy) { _Strategy = std::move(strategy); }

   private:
    std::string _Id;
    gfx::Color _Color;
    std::unique_ptr<IShapeStrategy> _Strategy;
};
}  // namespace shapes