cmake_minimum_required(VERSION 3.9)
project(SillyGame2)

set(CMAKE_CXX_STANDARD 17)

add_executable(SillyGame2
        main.cpp
        common/Game.cpp
        common/Game.h
        game/scenes/TestScene.cpp
        game/scenes/TestScene.h
        common/scene/Director.cpp
        common/scene/Director.h
        common/scene/Scene.cpp
        common/scene/Scene.h
        common/window/Window.cpp
        common/window/Window.h
        common/state/GameState.cpp
        common/state/GameState.h
        common/object/GameObject.cpp
        common/object/GameObject.h
        common/object/position/Transform.cpp
        common/object/position/Transform.h
        common/type/Vector3.cpp
        common/type/Vector3.h
        game/objects/Triangle/Triangle.cpp
        game/objects/Triangle/Triangle.h
        common/object/render/Mesh.cpp
        common/object/render/Mesh.h
        common/object/render/Material.cpp
        common/object/render/Material.h
        common/type/Vector3.cpp
        common/type/Vector3.h
        common/state/SceneState.cpp
        common/state/SceneState.h
        common/renderer/Renderer.cpp
        common/renderer/Renderer.h
        common/renderer/adapter/RenderAdapter.cpp
        common/renderer/adapter/RenderAdapter.h
        common/renderer/adapter/OpenGL.cpp
        common/renderer/adapter/OpenGL.h
        common/renderer/shader/ShaderManager.cpp
        common/renderer/shader/ShaderManager.h
        common/object/render/Shader.h
        game/objects/Cube/Cube.cpp
        game/objects/Cube/Cube.h
        common/renderer/texture/Texture2d.cpp
        common/renderer/texture/Texture2d.h
        common/renderer/texture/Texture.cpp
        common/renderer/texture/Texture.h
        lib/stb_image.h common/object/camera/Camera.cpp common/object/camera/Camera.h game/objects/Camera/TopDownCamera.cpp game/objects/Camera/TopDownCamera.h)

find_package(OpenGL REQUIRED)
find_package(Boost REQUIRED filesystem)

include_directories(osx common ${Boost_INCLUDE_DIRS} lib)

target_link_libraries(SillyGame2
        "-framework CoreFoundation"
        freeimage ${Boost_LIBRARIES}
        ${OPENGL_gl_LIBRARY}
        "-framework OpenGL"
        glfw
        glew)

file(GLOB files "game/shaders/**/*.glsl")
foreach (file ${files})
    string(REGEX REPLACE ".*/game/shaders" "" subDirString "${file}")
    configure_file(${file} ${CMAKE_BINARY_DIR}/shaders/${subDirString} COPYONLY)
endforeach ()

file(GLOB files "game/textures/**/*" "game/textures/*")
foreach (file ${files})
    string(REGEX REPLACE ".*/game/textures" "" subDirString "${file}")
    configure_file(${file} ${CMAKE_BINARY_DIR}/textures/${subDirString} COPYONLY)
endforeach ()