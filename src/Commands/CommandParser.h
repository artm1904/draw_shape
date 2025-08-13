#pragma once

#include <functional>
#include <map>
#include <memory>
#include <sstream>

#include "../Canvas/ICanvas.h"
#include "AllCommands.h"
#include "ICommand.h"

class CommandParser {
   public:
    CommandParser(Picture& picture, gfx::ICanvas& canvas) : _Picture(picture), _Canvas(canvas) {
        _Commands["List"] = [this](std::istream& input) {
            return std::make_unique<ListCommand>(_Picture);
        };

        _Commands["AddShape"] = [this](std::istream& input) {
            return std::make_unique<AddShapesCommand>(_Picture, _Canvas);
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
};