#pragma once

#include <string>
#include <memory>

#include "../Canvas/ICanvas.h"

class IShapeStrategy {
   public:
    virtual ~IShapeStrategy() = default;

    virtual void Draw(gfx::ICanvas& canvas) const = 0;
    virtual std::string GetTypeName() const = 0;
    virtual std::string GetParametrsInfo() const = 0;
    virtual std::unique_ptr<IShapeStrategy> Clone() const = 0;


   private:
};