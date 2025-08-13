#pragma once

#include "../Canvas/ICanvas.h"
#include "../Shape/Picture.h"
#include "ICommand.h"

class DrawPictureCommand : public ICommand {
   public:
    DrawPictureCommand(const Picture& picture,  gfx::ICanvas& canvas)
        : _Picture(picture), _Canvas(canvas) {}

    void Execute() override { _Picture.DrawPicture(_Canvas); }

   private:
    const Picture& _Picture;
    gfx::ICanvas& _Canvas;
};