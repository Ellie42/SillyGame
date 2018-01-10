//
// Created by Sophie Gauthier on 09/01/2018.
//


#ifndef SILLYGAME2_MESHRENDERER_H
#define SILLYGAME2_MESHRENDERER_H
#include <component/render/Mesh.h>
#include <component/render/Material.h>
#include "IRendererComponent.h"

class MeshRenderer : public IRendererComponent
{
private:
    std::shared_ptr<Mesh> m_mesh;
    std::shared_ptr<Material> m_material;
public:
    std::shared_ptr<Mesh> getMesh();
    void setMesh(std::shared_ptr<Mesh> t_mesh);

    std::shared_ptr<Material> getMaterial();
    void setMaterial(std::shared_ptr<Material> t_material);

    virtual void accept(IRendererVisitor* t_renderer) override;
};


#endif //SILLYGAME2_MESHRENDERER_H
