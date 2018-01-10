//
// Created by Sophie Gauthier on 03/01/2018.
//

#ifndef SILLYGAME2_SHADERMANAGER_H
#define SILLYGAME2_SHADERMANAGER_H


#include <component/render/Shader.h>
#include <string>
#include <GL/glew.h>

class ShaderManager
{
private:
    std::string m_basePath = "shaders";
public:
    static ShaderManager* instance();

    unsigned int loadShaderGroup(const std::string& t_name);

    std::string loadShaderSource(const std::string& vertexPath);

    unsigned int compileShader(const std::string& t_name, const GLenum t_type);
};


#endif //SILLYGAME2_SHADERMANAGER_H
