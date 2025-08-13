#pragma once

#include <iostream>

#include "../Canvas/ICanvas.h"
#include "../Shape/Picture.h"
#include "ICommand.h"

class ListCommand : public ICommand {
   public:
    ListCommand(const Picture& picture) : _Picture(picture) {}

    void Execute() override { _Picture.ListShapes(); }

   private:
    const Picture& _Picture;
};
