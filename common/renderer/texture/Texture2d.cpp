//
// Created by Sophie Gauthier on 04/01/2018.
//

#include "Texture2d.h"

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>

Texture2d::Texture2d(std::string t_path)
{
    m_path = std::move(t_path);
}

void Texture2d::load()
{
    stbi_set_flip_vertically_on_load(1);

    m_data = stbi_load(("textures/" + m_path).c_str(), &m_width, &m_height, &m_channels, STBI_rgb_alpha);

    m_loaded = true;
}

Texture2d::Texture2d(unsigned char* t_bytes, int width, int height)
{
    m_width = width;
    m_height = height;
    m_data = t_bytes;
    m_loaded = true;
}
