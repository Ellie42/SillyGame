//
// Created by Sophie Gauthier on 03/01/2018.
//

#include "ShaderManager.h"
#include <fstream>
#include <GL/glew.h>
#include <iostream>
#include <vector>

ShaderManager* ShaderManager::instance()
{
    static ShaderManager i;

    return &i;
}

unsigned int ShaderManager::loadShaderGroup(const std::string& t_name)
{
    //TODO add shader to cache
    std::cout << "Loading shader " << t_name << std::endl;

    auto vertexId = compileShader(t_name, GL_VERTEX_SHADER);
    auto fragmentId = compileShader(t_name, GL_FRAGMENT_SHADER);

    auto programId = glCreateProgram();

    glAttachShader(programId, vertexId);
    glAttachShader(programId, fragmentId);

    glLinkProgram(programId);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // Check the program
    glGetProgramiv(programId, GL_LINK_STATUS, &Result);
    glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &InfoLogLength);

    if (InfoLogLength > 0)
    {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(programId, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }

    glDetachShader(programId, vertexId);
    glDetachShader(programId, fragmentId);

    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);

    return programId;
}

unsigned int ShaderManager::compileShader(const std::string& t_name, const GLenum t_type)
{
    std::string fileName;

    switch (t_type)
    {
        case GL_FRAGMENT_SHADER:
            fileName = "fragment";
            break;
        case GL_VERTEX_SHADER:
        default:
            fileName = "vertex";
            break;
    }

    auto path = m_basePath + "/" + t_name + "/" + fileName + ".glsl";
    auto source = loadShaderSource(path);
    auto cSource = source.c_str();

    auto shaderId = glCreateShader((GLenum) t_type);

    auto length = (GLint) strlen(cSource);

    glShaderSourceARB(shaderId, 1, &cSource, &length);

    glCompileShaderARB(shaderId);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0)
    {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(shaderId, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        printf("%s\n", &VertexShaderErrorMessage[0]);
    }

    return shaderId;
}

std::string ShaderManager::loadShaderSource(const std::string& vertexPath)
{
    std::ifstream stream(vertexPath, std::ios::in);
    std::string source = "";

    if (!stream)
    {
        throw std::runtime_error("Failed to open shader " + vertexPath);
    }

    std::string line = "";
    while (getline(stream, line))
        source += "\n" + line;
    stream.close();

    return source;
}
