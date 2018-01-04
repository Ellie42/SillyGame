//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_CUBE_H
#define SILLYGAME2_CUBE_H


#include <object/GameObject.h>

class Cube : public GameObject
{
public:
    Cube();

    void onUpdate() override;
};


#endif //SILLYGAME2_CUBE_H
