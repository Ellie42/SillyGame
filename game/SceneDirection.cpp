//
// Created by Sophie Gauthier on 08/01/2018.
//

#include <memory>
#include "SceneDirection.h"
#include "scenes/TestScene.h"

std::shared_ptr<Scene> SceneDirection::getScene()
{
    return std::make_shared<TestScene>();
}
