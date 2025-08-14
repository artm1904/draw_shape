#pragma once

#include "../../Canvas/Color.h"
#include "../../Figures/IShapeStrategy.h"
#include "../../Shape/Picture.h"
#include "../../Shape/Shape.h"
#include "../ICommand.h"

class DrawPictureCommand : public ICommand {
   public:
    DrawPictureCommand(Picture& picture, gfx::ICanvas& canvas)
        : _Picture(picture), _Canvas(canvas) {}

    void Execute() override {
        // 1. Очищаем холст белым цветом
        _Canvas.Clear(gfx::Color(255, 255, 255));
        // 2. Рисуем все фигуры из текущего состояния модели
        _Picture.DrawPicture(_Canvas);
    }

   private:
    Picture& _Picture;
    gfx::ICanvas& _Canvas;
};