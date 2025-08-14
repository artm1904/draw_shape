#pragma once

#include <string>

#include "../../Canvas/Color.h"
#include "../../Figures/IShapeStrategy.h"
#include "../../Shape/Picture.h"
#include "../../Shape/Shape.h"
#include "../ICommand.h"

class MovePictureCommand : public ICommand {
   public:
    MovePictureCommand(Picture& picture, double dx, double dy)
        : _Picture(picture), _Dx(dx), _Dy(dy) {}

    void Execute() override { _Picture.MovePicture(_Dx, _Dy); }

   private:
    Picture& _Picture;

    double _Dx;
    double _Dy;
};
