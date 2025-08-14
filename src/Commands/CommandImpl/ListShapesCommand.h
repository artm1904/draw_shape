#pragma once

#include <iostream>

#include "../../Canvas/Color.h"
#include "../../Figures/IShapeStrategy.h"
#include "../../Shape/Picture.h"
#include "../../Shape/Shape.h"
#include "../ICommand.h"

class ListCommand : public ICommand {
   public:
    ListCommand(const Picture& picture) : _Picture(picture) {}

    void Execute() override { _Picture.ListShapes(); }

   private:
    const Picture& _Picture;
};
