//
// Created by Sophie Gauthier on 09/01/2018.
//

#include "TextRenderer.h"
#include <renderer/IRendererVisitor.h>

#include <utility>
#include <renderer/text/FontManager.h>

void TextRenderer::accept(IRendererVisitor* t_renderer)
{
    t_renderer->visit(this);
}

void TextRenderer::setText(std::string t_text)
{
    m_text = std::move(t_text);
}

std::string TextRenderer::getText()
{
    return m_text;
}

FT_Bitmap TextRenderer::getBitmap()
{
    FontManager::instance()->renderString(m_text, "default");

}
