//
// Created by Sophie Gauthier on 09/01/2018.
//

#ifndef SILLYGAME2_IRENDERERCOMPONENT_H
#define SILLYGAME2_IRENDERERCOMPONENT_H

class IRendererVisitor;

class IRendererComponent
{
public:
    virtual void accept(IRendererVisitor* t_renderer) = 0;
};


#endif //SILLYGAME2_IRENDERERCOMPONENT_H
