//
// Created by Sophie Gauthier on 03/01/2018.
//

#include "Material.h"
#include "Shader.h"

void Material::setShader(std::string t_name)
{
    m_shader.name = std::move(t_name);
}

void Material::setShader(unsigned int t_programId)
{
    m_shader.id = t_programId;
}

Shader* Material::getShader()
{
    return &m_shader;
}

void Material::setTexture(int t_index, std::shared_ptr<Texture> t_texture)
{
    m_textures[t_index] = t_texture;
}

std::shared_ptr<Texture> Material::getTexture(int t_index)
{
    if (m_textures.empty())
    {
        return std::shared_ptr<Texture>(nullptr);
    }

    return m_textures[t_index];
}

