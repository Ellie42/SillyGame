//
// Created by Sophie Gauthier on 08/01/2018.
//

#ifndef SILLYGAME2_TEXT_H
#define SILLYGAME2_TEXT_H


#include <object/GameObject.h>
#include <component/render/ui/TextRenderer.h>

class Text : public GameObject
{
public:
    Text(){
        setRenderer(std::make_shared<TextRenderer>());
    }
};


#endif //SILLYGAME2_TEXT_H
