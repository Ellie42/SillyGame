//
// Created by Sophie Gauthier on 09/01/2018.
//

#ifndef SILLYGAME2_FONTMANAGER_H
#define SILLYGAME2_FONTMANAGER_H

#include <ft2build.h>
#include <string>
#include <map>
#include <window/Window.h>
#include FT_FREETYPE_H

class FontManager
{
protected:
    FT_Library m_library;
    std::string m_defaultFont = "fonts/oxygen-mono/OxygenMono-Regular.ttf";
    std::map<std::string, FT_Face> m_loadedFonts;
    WindowDimensions* m_windowDimensions;
public:
    static FontManager* instance()
    {
        static FontManager i;
        return &i;
    }

    FontManager();

    void init();

    void loadFont(std::string t_name,std::string t_path);

    FT_Bitmap renderString(std::string t_string, const std::string& t_font);

    void renderCharacters(std::string t_font);
};


#endif //SILLYGAME2_FONTMANAGER_H
