//
// Created by Sophie Gauthier on 03/01/2018.
//

#include <scene/Director.h>
#include "GameObject.h"

GameObject::GameObject()
{

}

void GameObject::setMesh(Mesh* t_mesh)
{
    setMesh(std::shared_ptr<Mesh>(t_mesh));
}

void GameObject::setMesh(std::shared_ptr<Mesh> t_mesh)
{
    m_mesh = t_mesh;
}

void GameObject::setMaterial(std::shared_ptr<Material> t_material)
{
    m_material = t_material;
}

std::shared_ptr<Material> GameObject::getMaterial()
{
    return m_material;
}

std::shared_ptr<Mesh> GameObject::getMesh()
{
    return m_mesh;
}

Transform* GameObject::getTransform()
{
    return &m_transform;
}
