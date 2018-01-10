//
// Created by Sophie Gauthier on 09/01/2018.
//

#include "MeshRenderer.h"
#include <renderer/IRendererVisitor.h>

std::shared_ptr<Mesh> MeshRenderer::getMesh()
{
    return m_mesh;
}

void MeshRenderer::setMesh(std::shared_ptr<Mesh> t_mesh)
{
    m_mesh = t_mesh;
}

std::shared_ptr<Material> MeshRenderer::getMaterial()
{
    return m_material;
}

void MeshRenderer::setMaterial(std::shared_ptr<Material> t_material)
{
    m_material = t_material;
}

void MeshRenderer::accept(IRendererVisitor* t_renderer)
{
    t_renderer->visit(this);
}
