QT += core
QT -= gui

CONFIG += c++11

TARGET = qt57
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11 -lglut -lGL -lGEW -lGLU -lfreeimage
LIBS += -lglut -lGL -lGLEW -lGLU -lfreeimage

INCLUDEPATH += "../Sources"
#INCLUDEPATH += "../SDKs/OpenGL/include"

SOURCES = $$files(../Sources/*.cpp, true)


DISTFILES += \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderDiffuse.ps \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderDiffuseSpecular.ps \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderEarth.ps \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderRoad.ps \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderSand.ps \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderTask02Cube.ps \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderTask02Cylinder.ps \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderUnlit.ps \
    ../Sources/GraphicsEngine/Shaders/DX11/ShaderDiffuse.fx \
    ../Sources/GraphicsEngine/Shaders/DX11/ShaderEarth.fx \
    ../Sources/GraphicsEngine/Shaders/DX11/ShaderRoad.fx \
    ../Sources/GraphicsEngine/Shaders/DX11/ShaderSand.fx \
    ../Sources/GraphicsEngine/Shaders/DX11/ShaderTask02Cube.fx \
    ../Sources/GraphicsEngine/Shaders/DX11/ShaderTask02Cylinder.fx \
    ../Sources/GraphicsEngine/Shaders/DX11/ShaderUnlit.fx \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderDiffuse.vs \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderDiffuseSpecular.vs \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderEarth.vs \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderRoad.vs \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderSand.vs \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderTask02Cube.vs \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderTask02Cylinder.vs \
    ../Sources/GraphicsEngine/Shaders/DX9/ShaderUnlit.vs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderDiffuse.fs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderDiffuse.vs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderEarth.fs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderEarth.vs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderRoad.fs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderRoad.vs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderSand.fs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderSand.vs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderTask02Cube.fs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderTask02Cube.vs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderTask02Cylinder.fs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderTask02Cylinder.vs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderUnlit.fs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderUnlit.vs \
    ../Sources/GraphicsEngine/Shaders/GL20/ShaderMorphingCube.vs \

HEADERS = $$files(../Sources/*.h, true)
