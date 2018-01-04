//
// Created by Sophie Gauthier on 03/01/2018.
//

#include <iostream>
#include <scene/Director.h>
#include "TestScene.h"
#include "../objects/Triangle/Triangle.h"
#include "../objects/Cube/Cube.h"

void TestScene::onLoad()
{
    for (int x = -5; x < 6; x++)
    {
        for (int y = -5; y < 6; y++)
        {
            std::shared_ptr<GameObject> object;

            if (x % 2 == 0 || y % 2 == 0)
            {
                object = std::make_shared<Triangle>();

//                float a, b, c;
//
//                a = getRandomColour();
//                b = getRandomColour();
//                c = getRandomColour();
//
//                object->getMesh()->setVertColours(std::vector<float>{
//                        a, b, c,
//                        a, b, c,
//                        a, b, c,
//                });
            } else
            {
                object = std::make_shared<Cube>();
            }

            object->getTransform()->setPosition(x * 2, y * 2, 0);

            Director::instance()->addObject(object);
        }
    }
}

float TestScene::getRandomColour()
{
    return (float) (rand() % 100) / 100;
}

void TestScene::onUpdate()
{
    Scene::onUpdate();
}
