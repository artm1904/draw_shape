#pragma once

#include <memory>
#include <string>

#include "../Canvas/Color.h"
#include "../Figures/IShapeStrategy.h"

namespace shapes {

class Shape {
   public:
    Shape(std::string Id, gfx::Color Color, std::unique_ptr<IShapeStrategy> Strategy)
        : _Id(Id), _Color(std::move(Color)), _Strategy(std::move(Strategy)) {}

    void Draw(sfx::ICanvas& canvas) const { _Strategy->Draw(canvas); }

   private:
    std::string _Id;
    gfx::Color _Color;
    std::unique_ptr<IShapeStrategy> _Strategy;
};
}  // namespace shapes