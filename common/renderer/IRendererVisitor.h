//
// Created by Sophie Gauthier on 09/01/2018.
//

#ifndef SILLYGAME2_IRENDERERVISITOR_H
#define SILLYGAME2_IRENDERERVISITOR_H

class MeshRenderer;
class TextRenderer;

class IRendererVisitor
{
public:
    virtual void visit(MeshRenderer* t_renderer) = 0;
    virtual void visit(TextRenderer* t_renderer) = 0;
};

#endif //SILLYGAME2_IRENDERERVISITOR_H
