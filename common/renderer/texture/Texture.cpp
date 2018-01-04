//
// Created by Sophie Gauthier on 04/01/2018.
//

#include "Texture.h"

std::string Texture::getPath()
{
    return m_path;
}

bool Texture::isLoaded()
{
    return m_loaded;
}

unsigned int Texture::getTextureId()
{
    return m_textureId;
}

void Texture::setTextureId(unsigned int t_id)
{
    m_textureId = t_id;
}

stbi_uc* Texture::getData()
{
    return m_data;
}

int Texture::getHeight()
{
    return m_height;
}

int Texture::getWidth()
{
    return m_width;
}
