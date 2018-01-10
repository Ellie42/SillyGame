//
// Created by Sophie Gauthier on 08/01/2018.
//

#include <memory>
#include "Script.h"
#include "scenes/TestScene.h"
#include "scenes/debug/DebugWorld.h"

std::shared_ptr<Scene> Script::getScene()
{
    return std::make_shared<DebugWorld>();
}
