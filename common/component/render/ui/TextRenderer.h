//
// Created by Sophie Gauthier on 09/01/2018.
//

#ifndef SILLYGAME2_TEXTRENDERER_H
#define SILLYGAME2_TEXTRENDERER_H


#include <component/render/IRendererComponent.h>
#include <string>
#include <freetype/ftimage.h>

class TextRenderer : public IRendererComponent
{
protected:
    std::string m_text;
public:
    void accept(IRendererVisitor* t_renderer) override;

    void setText(std::string t_text);

    std::string getText();

    FT_Bitmap getBitmap();
};


#endif //SILLYGAME2_TEXTRENDERER_H
