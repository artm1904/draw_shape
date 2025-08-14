#pragma once

#include <functional>
#include <map>
#include <memory>
#include <sstream>

#include "../Canvas/ICanvas.h"
#include "../Figures/ShapeFactory.h"
#include "AllCommands.h"
#include "ICommand.h"

class CommandParser {
   public:
    CommandParser(Picture& picture, gfx::ICanvas& canvas) : _Picture(picture), _Canvas(canvas) {
        _Commands["List"] = [this](std::istream& input) {
            return std::make_unique<ListCommand>(this->_Picture);
        };

        _Commands["AddShape"] = [this](std::istream& input) -> std::unique_ptr<ICommand> {
            std::string id, colorStr, shapeType;
            if (!(input >> id >> colorStr >> shapeType)) {
                std::cerr << "Error: Not enough arguments for AddShape." << std::endl;
                return nullptr;
            }

            try {
                gfx::Color color = gfx::Color::FromString(colorStr);
                auto strategy = _ShapeFactory.CreateShape(shapeType, input);

                if (!strategy) {
                    std::cerr << "Error: Invalid shape type or parameters for '" << shapeType
                              << "'." << std::endl;
                    return nullptr;
                }
                return std::make_unique<AddShapesCommand>(_Picture, std::move(id), color,
                                                          std::move(strategy));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error parsing AddShape command: " << e.what() << std::endl;
                return nullptr;
            }
        };
        
        _Commands["DrawPicture"] = [this](std::istream& input) {
            return std::make_unique<DrawPictureCommand>(_Picture, _Canvas);
        };
    }

    std::unique_ptr<ICommand> ParseCommand(const std::string& command) {
        std::stringstream ss(command);
        std::string commandName;
        ss >> commandName;

        auto it = _Commands.find(commandName);
        if (it != _Commands.end()) {
            return it->second(ss);
        }
        std::cerr << "Unknown command: " << commandName << std::endl;
        return nullptr;
    }

    using CommandFactory = std::function<std::unique_ptr<ICommand>(std::istream& input)>;

   private:
    Picture& _Picture;
    gfx::ICanvas& _Canvas;
    std::map<std::string, CommandFactory> _Commands;
    ShapeFactory _ShapeFactory;
};