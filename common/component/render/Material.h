//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_MATERIAL_H
#define SILLYGAME2_MATERIAL_H


#include <string>
#include <renderer/texture/Texture2d.h>
#include <vector>
#include <map>
#include "Shader.h"

class Material
{
private:
    Shader m_shader;
    std::map<int, std::shared_ptr<Texture>> m_textures;
public:
    void setShader(std::string);

    void setShader(unsigned int);

    void setTexture(int t_index, std::shared_ptr<Texture> t_texture);

    std::shared_ptr<Texture> getTexture(int t_index);

    Shader* getShader();
};


#endif //SILLYGAME2_MATERIAL_H
