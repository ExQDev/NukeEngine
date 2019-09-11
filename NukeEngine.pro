#-------------------------------------------------
#
# Project created by QtCreator 2019-01-15T13:24:52
#
#-------------------------------------------------

QT       -= core gui

CONFIG -= qt
CONFIG += console c++14

TARGET = NukeEngine
TEMPLATE = lib

DEFINES += NUKEENGINE_LIBRARY GLM_ENABLE_EXPERIMENTAL

macx{
LIBS += -L/System/Library -L/Library -L~/Library -L/usr/local/lib -lboost_thread-mt -lboost_system -lboost_filesystem -llua -lassimp -lGLEW -lGLUT -framework OpenGL -framework GLUT -framework Cocoa -framework CoreFoundation
}
!macx{
LIBS += -L/usr/local/lib -lglut -lGL -lGLU -lGLEW -pthread -lboost_thread -lboost_system -lboost_filesystem -llua -ldl -lassimp
}

INCLUDEPATH += deps/imgui \
    deps/LuaBridge/Source \
    deps/glm

macx{
INCLUDEPATH += /usr/local/include
}
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deps/imgui/imgui.cpp \
    deps/imgui/imgui_demo.cpp \
    deps/imgui/imgui_draw.cpp \
    API/Model/Vector.cpp \
    deps/lodepng/lodepng_util.cpp \
    deps/lodepng/lodepng.cpp \
    deps/ImGuizmo/ImGuizmo.cpp \
    deps/ImGuizmo/ImSequencer.cpp

HEADERS += \
    backend/lua.h \
    deps/glm/glm/common.hpp \
    deps/glm/glm/exponential.hpp \
    deps/glm/glm/ext.hpp \
    deps/glm/glm/fwd.hpp \
    deps/glm/glm/geometric.hpp \
    deps/glm/glm/glm.hpp \
    deps/glm/glm/integer.hpp \
    deps/glm/glm/mat2x2.hpp \
    deps/glm/glm/mat2x3.hpp \
    deps/glm/glm/mat2x4.hpp \
    deps/glm/glm/mat3x2.hpp \
    deps/glm/glm/mat3x3.hpp \
    deps/glm/glm/mat3x4.hpp \
    deps/glm/glm/mat4x2.hpp \
    deps/glm/glm/mat4x3.hpp \
    deps/glm/glm/mat4x4.hpp \
    deps/glm/glm/matrix.hpp \
    deps/glm/glm/packing.hpp \
    deps/glm/glm/trigonometric.hpp \
    deps/glm/glm/vec2.hpp \
    deps/glm/glm/vec3.hpp \
    deps/glm/glm/vec4.hpp \
    deps/glm/glm/vector_relational.hpp \
    deps/imgui/imconfig.h \
    deps/imgui/imgui.h \
    deps/imgui/imgui_internal.h \
    deps/imgui/stb_rect_pack.h \
    deps/imgui/stb_textedit.h \
    deps/imgui/stb_truetype.h \
    deps/LuaBridge/Source/LuaBridge/detail/CFunctions.h \
    deps/LuaBridge/Source/LuaBridge/detail/ClassInfo.h \
    deps/LuaBridge/Source/LuaBridge/detail/Constructor.h \
    deps/LuaBridge/Source/LuaBridge/detail/dump.h \
    deps/LuaBridge/Source/LuaBridge/detail/FuncTraits.h \
    deps/LuaBridge/Source/LuaBridge/detail/Iterator.h \
    deps/LuaBridge/Source/LuaBridge/detail/LuaException.h \
    deps/LuaBridge/Source/LuaBridge/detail/LuaHelpers.h \
    deps/LuaBridge/Source/LuaBridge/detail/LuaRef.h \
    deps/LuaBridge/Source/LuaBridge/detail/Namespace.h \
    deps/LuaBridge/Source/LuaBridge/detail/Stack.h \
    deps/LuaBridge/Source/LuaBridge/detail/TypeList.h \
    deps/LuaBridge/Source/LuaBridge/detail/TypeTraits.h \
    deps/LuaBridge/Source/LuaBridge/detail/Userdata.h \
    deps/LuaBridge/Source/LuaBridge/LuaBridge.h \
    deps/LuaBridge/Source/LuaBridge/RefCountedObject.h \
    deps/LuaBridge/Source/LuaBridge/RefCountedPtr.h \
    editor/editorui.h \
    gui/gui.h \
    input/keyboard.h \
    input/mouse.h \
    render/opengl/nukeogl.h \
    render/irender.h \
    config.h \
    API/Model/Camera.h \
    API/Model/Clock.h \
    API/Model/Collider.h \
    API/Model/Color.h \
    API/Model/Component.h \
    API/Model/Game.h \
    API/Model/GameObject.h \
    API/Model/ID.h \
    API/Model/Include.h \
    API/Model/Layers.h \
    API/Model/Light.h \
    API/Model/Material.h \
    API/Model/Math.h \
    API/Model/Mesh.h \
    API/Model/MeshRenderer.h \
    API/Model/Module.h \
    API/Model/Package.h \
    API/Model/Resource.h \
    API/Model/Scene.h \
    API/Model/Script.h \
    API/Model/Shader.h \
    API/Model/Texture.h \
    API/Model/Time.h \
    API/Model/Transform.h \
    API/Model/Vector.h \
    interface/EditorMenu/MenuItem.h \
    interface/EditorMenu/MenuStrip.h \
    interface/EditorInstance.h \
    interface/NUKEEInteface.h \
    interface/Modular.h \
    interface/AppInstance.h \
    import/assimporter.h \
    API/Model/resdb.h \
    deps/lodepng/lodepng_util.h \
    deps/lodepng/lodepng.h \
    deps/ImGuizmo/ImGuizmo.h \
    deps/ImGuizmo/ImSequencer.h \
    API/Model/ray.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}


CONFIG(debug, debug|release) {
    DESTDIR = debug
} else {
    DESTDIR = release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui
