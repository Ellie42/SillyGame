//
// Created by Sophie Gauthier on 03/01/2018.
//

#include <utility>
#include <vector>
#include "Mesh.h"

void Mesh::setVerts(const std::vector<float>& t_verts)
{
    m_verts = t_verts;
}

std::vector<float>* Mesh::getVerts()
{
    return &m_verts;
}

unsigned long Mesh::getVertCount()
{
    return m_verts.size() / 3;
}

int Mesh::getVertBufferId()
{
    return m_vertBufferId;
}

void Mesh::setVertBufferId(int t_id)
{
    m_vertBufferId = t_id;
}

std::vector<float> Mesh::getVertColours()
{
    return m_vertColours;
}

void Mesh::setVertColours(std::vector<float> t_colours)
{
    m_vertColours = t_colours;
}

int Mesh::getColourBufferId()
{
    return m_colourBufferId;
}

void Mesh::setColourBufferId(int t_id)
{
    m_colourBufferId = t_id;
}

void Mesh::setUvs(const std::vector<float>& t_uvs)
{
    m_uvs = t_uvs;
}

std::vector<float>* Mesh::getUvs()
{
    return &m_uvs;
}

int Mesh::getUvBufferId()
{
    return m_uvBufferId;
}

void Mesh::setUvBufferId(int t_id)
{
    m_uvBufferId = t_id;
}
