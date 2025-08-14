#pragma once

#include <functional>
#include <istream>
#include <map>
#include <memory>
#include <string>

#include "IShapeStrategy.h"

class ShapeFactory {
   public:
    ShapeFactory();

    std::unique_ptr<IShapeStrategy> CreateShape(const std::string& description, std::istream& args);

   private:
    using StrategyFactory = std::function<std::unique_ptr<IShapeStrategy>(std::istream& args)>;
    std::map<std::string, StrategyFactory> _StrategyFactories;
};
