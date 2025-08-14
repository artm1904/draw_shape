#pragma once

#include <string>

#include "../../Canvas/Color.h"
#include "../../Figures/IShapeStrategy.h"
#include "../../Shape/Picture.h"
#include "../../Shape/Shape.h"
#include "../ICommand.h"

class DeleteShapeCommand : public ICommand {
   public:
    DeleteShapeCommand(Picture& picture, std::string id) : _Picture(picture), _Id(std::move(id)) {}

    void Execute() override { _Picture.DeleteShape(_Id); }

   private:
    Picture& _Picture;
    std::string _Id;
};
