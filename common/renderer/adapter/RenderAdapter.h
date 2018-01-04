//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_RENDERADAPTER_H
#define SILLYGAME2_RENDERADAPTER_H


#include <object/render/Material.h>
#include <object/render/Mesh.h>
#include <object/GameObject.h>

enum RenderData
{
    Vertex = 1,
    VertexColour = 2,
    UV = 3,
};

class RenderAdapter
{
public:
    virtual void init() = 0;

    virtual void useShader(Shader*) = 0;

    virtual void clearShader() = 0;

    virtual void reset() = 0;

    virtual void drawMesh(std::shared_ptr<Mesh> t_mesh) = 0;

    virtual void clear() = 0;

    virtual void setModelMatrix(GameObject* t_obj) = 0;

    virtual void batch(std::shared_ptr<GameObject> t_object) = 0;

    virtual void drawBatch() = 0;

    virtual void useMaterial(std::shared_ptr<Material> t_material) = 0;

    glm::mat4 getPerspectiveMatrix();

    glm::mat4 getCameraMatrix();
};


#endif //SILLYGAME2_RENDERADAPTER_H
