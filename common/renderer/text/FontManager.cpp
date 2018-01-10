//
// Created by Sophie Gauthier on 09/01/2018.
//


#include "FontManager.h"
#include <iostream>
#include <Game.h>
#include <vector>

FontManager::FontManager()
{
    m_windowDimensions = Game::instance()->getWindow()->getDimensions();
}

void FontManager::init()
{
    auto error = FT_Init_FreeType(&m_library);

    if (error)
    {
        std::cerr << "Failed to initialise font library" << std::endl;
        return;
    }

    loadFont("default", m_defaultFont);
    renderCharacters("default");
}

void FontManager::loadFont(std::string t_name, std::string t_path)
{
    FT_Face face;
    auto error = FT_New_Face(m_library, t_path.c_str(), 0, &face);

    if (error)
    {
        std::string reason;

        switch (error)
        {
            case FT_Err_Cannot_Open_Resource:
                reason = "Cannot open file";
                break;
            default:
                reason = "Error Code " + std::to_string(error);
        }

        std::cerr << "Failed to load font face " << t_name << ": " << reason << std::endl;
        return;
    }

    error = FT_Set_Char_Size(
            face,
            0,
            16 * 64,
            (FT_UInt) m_windowDimensions->width,
            (FT_UInt) m_windowDimensions->height
    );

    if (error)
    {
        std::cerr << "Failed to set character size data" << std::endl;
        return;
    }

    m_loadedFonts[t_name] = face;
}

FT_Bitmap FontManager::renderString(std::string t_string, const std::string& t_font = "default")
{
//    FT_Error error;
//
//    auto font = m_loadedFonts[t_font];
//
//    for (char& i : t_string)
//    {
//        auto glyphIndex = FT_Get_Char_Index(font, (FT_ULong) i);
//
//        error = FT_Load_Glyph(font, glyphIndex, FT_LOAD_DEFAULT);
//
//        if (error)
//        {
//            continue;
//        }
//
//        error = FT_Render_Glyph(font->glyph, FT_RENDER_MODE_NORMAL);
//
//        if (error)
//        {
//            continue;
//        }
//
//        auto charBitmap = font->glyph->bitmap;
//
//        for(int j = 0; j < sizeof(charBitmap.buffer) / sizeof(unsigned char); j++){
//            bitmap.push_back(charBitmap.buffer[j]);
//        }
//
//        continue;
//    }
}

void FontManager::renderCharacters(std::string t_font)
{
    std::vector<unsigned char> bitmap(1024);

    for(int i = 0; i < 128; i++){

    }
}
