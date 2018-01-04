//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_TRIANGLE_H
#define SILLYGAME2_TRIANGLE_H


#include <object/GameObject.h>

class Triangle : public GameObject
{
public:
    Triangle();

    void onUpdate() override;
};


#endif //SILLYGAME2_TRIANGLE_H
