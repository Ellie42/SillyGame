//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_MESH_H
#define SILLYGAME2_MESH_H


#include <object/position/Vector3.h>
#include <vector>

class Mesh
{
public:
    void setUvs(const std::vector<float>& t_uvs);

    std::vector<float>* getUvs();

    void setVerts(const std::vector<float>& t_verts);

    std::vector<float>* getVerts();

    std::vector<float> getVertColours();

    void setVertColours(std::vector<float> t_colours);

    unsigned long getVertCount();

    int getVertBufferId();

    void setVertBufferId(int t_id);

    int getColourBufferId();

    void setColourBufferId(int t_id);

    int getUvBufferId();

    void setUvBufferId(int t_id);

private:
    std::vector<float> m_verts;
    std::vector<float> m_uvs;
    std::vector<float> m_vertColours;
    int m_vertBufferId = 0;
    int m_uvBufferId = 0;
    int m_colourBufferId = 0;

};


#endif //SILLYGAME2_MESH_H
