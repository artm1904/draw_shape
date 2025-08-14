#pragma once

#include <string>

#include "../../Canvas/Color.h"
#include "../../Figures/IShapeStrategy.h"
#include "../../Shape/Picture.h"
#include "../../Shape/Shape.h"
#include "../ICommand.h"

class MoveShapeCommand : public ICommand {
   public:
    MoveShapeCommand(Picture& picture, std::string id, double dx, double dy)
        : _Picture(picture), _Id(std::move(id)), _Dx(dx), _Dy(dy) {}

    void Execute() override { _Picture.MoveShape(_Id, _Dx, _Dy); }

   private:
    Picture& _Picture;
    std::string _Id;
    double _Dx;
    double _Dy;
};
