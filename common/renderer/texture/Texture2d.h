//
// Created by Sophie Gauthier on 04/01/2018.
//

#ifndef SILLYGAME2_TEXTURE2D_H
#define SILLYGAME2_TEXTURE2D_H


#include <string>
#include "Texture.h"

class Texture2d : public Texture
{
public:
    Texture2d(std::string t_path);
    void load() override;
};


#endif //SILLYGAME2_TEXTURE2D_H
