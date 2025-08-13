#pragma once

#include <string>
#include <vector>

#include "Shape.h"

class Picture {
   public:
    void AddShape(shapes::Shape shape) { _Shapes.push_back(std::move(shape)); }

    void MoveShape(const std::string& id, double dx, double dy) {
        for (auto& shape : _Shapes) {
            if (shape.GetId() == id) {
                //shape.Move(dx, dy);
                break;
            }
        }
    }

    void MovePicture(double dx, double dy) {
        for (auto& shape : _Shapes) {
            //shape.Move(dx, dy);
        }
    }

    void DeleteShape(const std::string& id) {
        _Shapes.erase(
            std::remove_if(_Shapes.begin(), _Shapes.end(),
                           [id](const shapes::Shape& shape) { return shape.GetId() == id; }),
            _Shapes.end());
    }

    void ListShapes() const {
        for (const auto& shape : _Shapes) {
            std::cout << shape.GetParametersInfo() << std::endl;
        }
    }

    void DrawPicture(gfx::ICanvas& canvas) const {
        for (const auto& shape : _Shapes) {
            shape.Draw(canvas);
        }
    }

   private:
    std::vector<shapes::Shape> _Shapes;
};