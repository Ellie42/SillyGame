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

    Vector3(T t_x, T t_y, T t_z)
    {
        x = t_x;
        y = t_y;
        z = t_z;
    }

    operator glm::tvec3<T>()
    {
        return glm::tvec3<T>(x, y, z);
    };

    Vector3<T>& operator*(double t_num)
    {
        x = x * t_num;
        y = y * t_num;
        z = z * t_num;

        return *this;
    }

    Vector3<T>& operator+=(const Vector3<>& t_vec)
    {
        x = x + t_vec.x;
        y = y + t_vec.y;
        z = z + t_vec.z;

        return *this;
    }

    Vector3<T>& operator-=(const Vector3<>& t_vec)
    {
        x = x - t_vec.x;
        y = y - t_vec.y;
        z = z - t_vec.z;

        return *this;
    }

    Vector3<T> operator-(){
        x = -x;
        y = -y;
        z = -z;
        return *this;
    }
};

inline Vector3<> operator+(Vector3<> lhs, const Vector3<>& rhs)
{
    lhs += rhs;
    return lhs;
}

inline Vector3<> operator-(Vector3<> lhs, const Vector3<>& rhs)
{
    lhs -= rhs;
    return lhs;
}

#endif //SILLYGAME2_VECTOR3_H
