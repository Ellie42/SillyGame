//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_GAMEOBJECT_H
#define SILLYGAME2_GAMEOBJECT_H


#include <object/render/Mesh.h>
#include <object/render/Material.h>
#include <memory>
#include "object/position/Transform.h"

class GameObject
{
protected:
    Transform m_transform;
    std::shared_ptr<Mesh> m_mesh = nullptr;
    std::shared_ptr<Material> m_material = nullptr;
public:
    GameObject();

    void setMesh(std::shared_ptr<Mesh>);

    void setMesh(Mesh*);

    std::shared_ptr<Mesh> getMesh();

    void setMaterial(std::shared_ptr<Material>);

    std::shared_ptr<Material> getMaterial();

    Transform* getTransform();

    virtual void onUpdate(){};
};


#endif //SILLYGAME2_GAMEOBJECT_H
