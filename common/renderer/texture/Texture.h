//
// Created by Sophie Gauthier on 04/01/2018.
//

#ifndef SILLYGAME2_TEXTURE_H
#define SILLYGAME2_TEXTURE_H


#include <string>
#include <stb_image.h>

class Texture
{
protected:
    std::string m_path;
    stbi_uc* m_data;
    unsigned int m_textureId = 0;
    bool m_loaded = false;
    int m_height = 0;
    int m_width = 0;
    int m_channels = 0;
public:
    virtual void load() = 0;
    std::string getPath();
    stbi_uc* getData();
    int getHeight();
    int getWidth();
    bool isLoaded();
    unsigned int getTextureId();
    void setTextureId(unsigned int t_id);
};


#endif //SILLYGAME2_TEXTURE_H
