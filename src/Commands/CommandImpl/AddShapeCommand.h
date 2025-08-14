#pragma once

#include <memory>
#include <string>

#include "../../Canvas/Color.h"
#include "../../Figures/IShapeStrategy.h"
#include "../../Shape/Picture.h"
#include "../../Shape/Shape.h"
#include "../ICommand.h"

class AddShapesCommand : public ICommand {
   public:
    AddShapesCommand(Picture& picture, std::string id, gfx::Color color,
                     std::unique_ptr<IShapeStrategy> strategy)
        : _Picture(picture),
          _Id(std::move(id)),
          _Color(color),
          _Strategy(std::move(strategy)) {}

    void Execute() override { _Picture.AddShape(shapes::Shape(_Id, _Color, std::move(_Strategy))); }

   private:
    Picture& _Picture;
    std::string _Id;
    gfx::Color _Color;
    std::unique_ptr<IShapeStrategy> _Strategy;
};