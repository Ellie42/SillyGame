//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_VECTOR3_H
#define SILLYGAME2_VECTOR3_H

#include <glm/glm.hpp>

template<typename T = float>
class Vector3
{
public:
    T x = (T) 0;
    T y = (T) 0;
    T z = (T) 0;

    Vector3() = default;

    Vector3(int t_x, int t_y, int t_z)
    {
        x = (T) t_x;
        y = (T) t_y;
        z = (T) t_z;
    }

    explicit operator glm::tvec3<T>() {
        return glm::tvec3<T>(x, y, z);
    };
};


#endif //SILLYGAME2_VECTOR3_H
