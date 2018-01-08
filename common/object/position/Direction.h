//
// Created by Sophie Gauthier on 08/01/2018.
//

#ifndef SILLYGAME2_DIRECTION_H
#define SILLYGAME2_DIRECTION_H

#include <object/position/Vector3.h>

struct Direction{
    Vector3<> up = Vector3<>(0, 1, 0);
    Vector3<> forward = Vector3<>(0, 0, 1);
    Vector3<> right = Vector3<>(-1, 0, 0);
};

#endif //SILLYGAME2_DIRECTION_H
