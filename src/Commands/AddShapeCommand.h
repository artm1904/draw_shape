#pragma once

#include "../Canvas/ICanvas.h"
#include "../Shape/Picture.h"
#include "ICommand.h"

class AddShapesCommand : public ICommand {
   public:
    AddShapesCommand(const Picture& picture, gfx::ICanvas& canvas) : _Picture(picture), _Canvas(canvas) {}

    void Execute() override {
        return;
        //_Picture.AddShape();
    }

   private:
    const Picture& _Picture;
    gfx::ICanvas& _Canvas;
};