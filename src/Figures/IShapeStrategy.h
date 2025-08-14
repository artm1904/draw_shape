#pragma once

#include <string>
#include <memory>

#include "../Canvas/ICanvas.h"

class IShapeStrategy {
   public:
    virtual ~IShapeStrategy() = default;

    virtual void Draw(gfx::ICanvas& canvas) const = 0;
    virtual void Move(double dx, double dy) = 0;
    virtual std::string GetTypeName() const = 0;
    virtual std::string GetParametersInfo() const = 0;
    virtual std::unique_ptr<IShapeStrategy> Clone() const = 0;


   private:
};