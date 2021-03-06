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
        common/GameState.cpp
        common/GameState.h
        common/object/GameObject.cpp
        common/object/GameObject.h
        common/object/position/Transform.cpp
        common/object/position/Transform.h
        common/object/position/Vector3.cpp
        common/object/position/Vector3.h
        game/objects/Triangle/Triangle.cpp
        game/objects/Triangle/Triangle.h
        common/component/render/Mesh.cpp
        common/component/render/Mesh.h
        common/component/render/Material.cpp
        common/component/render/Material.h
        common/object/position/Vector3.cpp
        common/object/position/Vector3.h
        common/scene/SceneState.cpp
        common/scene/SceneState.h
        common/renderer/Renderer.cpp
        common/renderer/Renderer.h
        common/renderer/adapter/RenderAdapter.cpp
        common/renderer/adapter/RenderAdapter.h
        common/renderer/adapter/OpenGL.cpp
        common/renderer/adapter/OpenGL.h
        common/renderer/shader/ShaderManager.cpp
        common/renderer/shader/ShaderManager.h
        common/component/render/Shader.h
        game/objects/Cube/Cube.cpp
        game/objects/Cube/Cube.h
        common/renderer/texture/Texture2d.cpp
        common/renderer/texture/Texture2d.h
        common/renderer/texture/Texture.cpp
        common/renderer/texture/Texture.h
        lib/stb_image.h
        common/object/camera/Camera.cpp
        common/object/camera/Camera.h
        game/objects/Camera/TopDownCamera.cpp
        game/objects/Camera/TopDownCamera.h
        common/input/Input.cpp
        common/input/Input.h
        common/time/Time.cpp
        common/time/Time.h
        common/object/position/Direction.h
        game/Script.cpp
        game/Script.h
        common/scene/IScript.h
        game/scenes/debug/DebugWorld.cpp
        game/scenes/debug/DebugWorld.h
        common/world/World.cpp
        common/world/World.h
        common/world/terrain/Tile.cpp
        common/world/terrain/Tile.h
        common/object/ui/Text.cpp
        common/object/ui/Text.h
        common/object/Object.cpp
        common/object/Object.h
        common/component/render/Layer.h
        common/component/render/Layer.h
        game/objects/Debug/DebugText.cpp
        game/objects/Debug/DebugText.h
        common/component/render/MeshRenderer.cpp
        common/component/render/MeshRenderer.h
        common/component/render/IRendererComponent.h common/renderer/IRendererVisitor.h common/component/render/ui/TextRenderer.cpp common/component/render/ui/TextRenderer.h common/renderer/text/FontManager.cpp common/renderer/text/FontManager.h)

find_package(OpenGL REQUIRED)
find_package(Boost REQUIRED filesystem)
find_package(Freetype REQUIRED)

include_directories(osx common lib ${Boost_INCLUDE_DIRS} ${FREETYPE_INCLUDE_DIRS})

target_link_libraries(SillyGame2
        "-framework CoreFoundation"
        freeimage ${Boost_LIBRARIES}
        ${FREETYPE_LIBRARIES}
        ${OPENGL_gl_LIBRARY}
        "-framework OpenGL"
        glfw
        pthread
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

file(GLOB files "game/fonts/**/*")
foreach (file ${files})
    string(REGEX REPLACE ".*/game/fonts" "" subDirString "${file}")
    configure_file(${file} ${CMAKE_BINARY_DIR}/fonts/${subDirString} COPYONLY)
endforeach ()