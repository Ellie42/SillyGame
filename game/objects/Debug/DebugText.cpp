//
// Created by Sophie Gauthier on 08/01/2018.
//

#include <scene/Director.h>
#include <object/ui/Text.h>
#include "DebugText.h"

void DebugText::onInstance()
{
    m_text = std::make_shared<Text>();

    auto textRenderer = dynamic_cast<TextRenderer*>(m_text->getRenderer());

    textRenderer->setText("Hello");

    Director::instance()->addObject(m_text);
}

void DebugText::onUpdate()
{
}
