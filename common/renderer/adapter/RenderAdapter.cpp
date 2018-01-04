//
// Created by Sophie Gauthier on 03/01/2018.
//

#include "RenderAdapter.h"
#include <window/Window.h>
#include <Game.h>
#include <glm/gtc/matrix_transform.hpp>

glm::mat4 RenderAdapter::getPerspectiveMatrix()
{
    WindowDimensions* winDimension = Game::instance()->getWindow()->getDimensions();

    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    glm::mat4 Projection = glm::perspective(glm::radians(70.0f),
                                            (float) winDimension->width / (float) winDimension->height, 0.1f, 100.0f);

//    glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

    return Projection;
}

glm::mat4 RenderAdapter::getCameraMatrix()
{
    glm::mat4 View = glm::lookAt(
            glm::vec3(0, 0, 4), // Camera is at (4,3,3), in World Space
            glm::vec3(0, 0, 0), // and looks at the origin
            glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
    return View;
}
