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

# Qt 5.3 and lower doesn't recognize "c++14". Use c++11 and then replace
# the compiler flags with c++14.
contains(QT_MAJOR_VERSION, 5):lessThan(QT_MINOR_VERSION, 4) {
    CONFIG += c++11
    QMAKE_CXXFLAGS_CXX11 = $$replace(QMAKE_CXXFLAGS_CXX11, "std=c\+\+11", "std=c++1y")
    QMAKE_CXXFLAGS_CXX11 = $$replace(QMAKE_CXXFLAGS_CXX11, "std=c\+\+0x", "std=c++1y")
}

# Qt 4 doesn't even know about C++11, so just add c++14 directly.
contains(QT_MAJOR_VERSION, 4) {
    QMAKE_CXXFLAGS += -std=c++1y
}

DEFINES += NUKEENGINE_LIBRARY GLM_ENABLE_EXPERIMENTAL

macx{
LIBS += -L/System/Library -L/Library -L~/Library -L/usr/local/lib -lGLFW -lboost_thread-mt -lboost_system -lboost_filesystem -llua -lassimp -lGLEW -lGLUT -framework OpenGL -framework GLUT -framework Cocoa -framework CoreFoundation
}
!macx{
LIBS += -L/usr/local/lib -lglut -lGL -lGLU -lGLEW -pthread -lboost_thread -lboost_system -lboost_filesystem -llua -ldl -lassimp -lbgfx -lglfw -lvulkan
}

INCLUDEPATH += $$PWD/include \
    $$PWD/deps \
    $$PWD/deps/imgui-1.89.1 \
    $$PWD/deps/glm \
#    $$PWD/deps/bgfx/include \
    $$PWD/deps/bx/include
#    $$PWD/deps/glfw/include

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
    deps/imgui-1.89.1/backends/imgui_impl_glfw.cpp \
    deps/imgui-1.89.1/backends/imgui_impl_glut.cpp \
    deps/imgui-1.89.1/backends/imgui_impl_opengl2.cpp \
    deps/imgui-1.89.1/backends/imgui_impl_opengl3.cpp \
    deps/imgui-1.89.1/backends/imgui_impl_vulkan.cpp \
    deps/imgui-1.89.1/imgui.cpp \
    deps/imgui-1.89.1/imgui_demo.cpp \
    deps/imgui-1.89.1/imgui_draw.cpp \
    deps/imgui-1.89.1/imgui_tables.cpp \
    deps/imgui-1.89.1/imgui_widgets.cpp \
    deps/imgui-1.89.1/misc/cpp/imgui_stdlib.cpp \
    deps/imgui-1.89.1/misc/fonts/binary_to_compressed_c.cpp \
    src/NukeEngine.cpp \
    deps/lodepng/lodepng_util.cpp \
    deps/lodepng/lodepng.cpp \
    deps/ImGuizmo/ImGuizmo.cpp \
    deps/ImGuizmo/ImSequencer.cpp \
    src/API/Model/Camera.cpp \
    src/API/Model/Clock.cpp \
    src/API/Model/Collider.cpp \
    src/API/Model/Color.cpp \
    src/API/Model/Component.cpp \
    src/API/Model/Game.cpp \
    src/API/Model/GameObject.cpp \
    src/API/Model/ID.cpp \
    src/API/Model/Layers.cpp \
    src/API/Model/Light.cpp \
    src/API/Model/Material.cpp \
    src/API/Model/Math.cpp \
    src/API/Model/Mesh.cpp \
    src/API/Model/MeshRenderer.cpp \
    src/API/Model/Module.cpp \
    src/API/Model/Package.cpp \
    src/API/Model/Resource.cpp \
    src/API/Model/Scene.cpp \
    src/API/Model/Script.cpp \
    src/API/Model/Shader.cpp \
    src/API/Model/Texture.cpp \
    src/API/Model/Time.cpp \
    src/API/Model/Transform.cpp \
    src/API/Model/Vector.cpp \
    src/API/Model/ray.cpp \
    src/API/Model/resdb.cpp \
    src/API/iGUI.cpp \
    src/backend/lua.cpp \
    src/config.cpp \
    src/gui/gui.cpp \
    src/import/assimporter.cpp \
    src/input/keyboard.cpp \
    src/input/mouse.cpp \
    src/interface/AppInstance.cpp \
    src/interface/EditorInstance.cpp \
    src/interface/EditorMenu/MenuItem.cpp \
    src/interface/EditorMenu/MenuStrip.cpp \
    src/interface/Modular.cpp \
    src/interface/NUKEEInteface.cpp \
    src/render/irender.cpp \
    src/render/opengl/nukeogl.cpp \
    src/render/universal/nukebgfx.cpp

HEADERS += \
    deps/imgui-1.89.1/backends/imgui_impl_glfw.h \
    deps/imgui-1.89.1/backends/imgui_impl_glut.h \
    deps/imgui-1.89.1/backends/imgui_impl_opengl2.h \
    deps/imgui-1.89.1/backends/imgui_impl_opengl3.h \
    deps/imgui-1.89.1/backends/imgui_impl_opengl3_loader.h \
    deps/imgui-1.89.1/backends/imgui_impl_vulkan.h \
    deps/imgui-1.89.1/imconfig.h \
    deps/imgui-1.89.1/imgui.h \
    deps/imgui-1.89.1/imgui_internal.h \
    deps/imgui-1.89.1/imstb_rectpack.h \
    deps/imgui-1.89.1/imstb_textedit.h \
    deps/imgui-1.89.1/imstb_truetype.h \
    deps/imgui-1.89.1/misc/cpp/imgui_stdlib.h \
    include/NukeEngine.hpp \
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
    include/API/Model/Camera.h \
    include/API/Model/Clock.h \
    include/API/Model/Collider.h \
    include/API/Model/Color.h \
    include/API/Model/Component.h \
    include/API/Model/Game.h \
    include/API/Model/GameObject.h \
    include/API/Model/ID.h \
    include/API/Model/Layers.h \
    include/API/Model/Light.h \
    include/API/Model/Material.h \
    include/API/Model/Math.h \
    include/API/Model/Mesh.h \
    include/API/Model/MeshRenderer.h \
    include/API/Model/Module.h \
    include/API/Model/Package.h \
    include/API/Model/Resource.h \
    include/API/Model/Scene.h \
    include/API/Model/Script.h \
    include/API/Model/Shader.h \
    include/API/Model/Texture.h \
    include/API/Model/Time.h \
    include/API/Model/Transform.h \
    include/API/Model/Vector.h \
    include/API/Model/ray.h \
    include/API/Model/resdb.h \
    include/API/iGUI.h \
    include/backend/lua.h \
    include/config.hpp \
    include/gui/gui.h \
    include/import/assimporter.h \
    include/input/keyboard.h \
    include/input/mouse.h \
    include/interface/AppInstance.h \
    include/interface/EditorInstance.h \
    include/interface/EditorMenu/MenuItem.h \
    include/interface/EditorMenu/MenuStrip.h \
    include/interface/Modular.h \
    include/interface/NUKEEInteface.h \
    include/render/irender.h \
    include/render/opengl/nukeogl.h \
    include/render/universal/nukebgfx.h \
    deps/lodepng/lodepng_util.h \
    deps/lodepng/lodepng.h \
    deps/ImGuizmo/ImGuizmo.h \
    deps/ImGuizmo/ImSequencer.h

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

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/deps/bgfx/build/osx64_clang/bin/release/ -lbgfx-shared-libDebug
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/deps/bgfx/build/osx64_clang/bin/debug/ -lbgfx-shared-libDebug
#else:unix: LIBS += -L$$PWD/deps/bgfx/.build/linux64_gcc/bin/ -lbgfx-shared-libDebug
#else:macx: LIBS += -L$$PWD/deps/bgfx/build/osx64_clang/bin/ -lbgfx-shared-libDebug

INCLUDEPATH += $$PWD/deps/bgfx/include
DEPENDPATH += $$PWD/deps/bgfx/include

DISTFILES += \
    deps/imgui-1.89.1/LICENSE.txt \
    deps/imgui-1.89.1/backends/vulkan/generate_spv.sh \
    deps/imgui-1.89.1/backends/vulkan/glsl_shader.frag \
    deps/imgui-1.89.1/backends/vulkan/glsl_shader.vert \
    deps/imgui-1.89.1/misc/README.txt \
    deps/imgui-1.89.1/misc/cpp/README.txt \
    deps/imgui-1.89.1/misc/fonts/Cousine-Regular.ttf \
    deps/imgui-1.89.1/misc/fonts/DroidSans.ttf \
    deps/imgui-1.89.1/misc/fonts/Karla-Regular.ttf \
    deps/imgui-1.89.1/misc/fonts/ProggyClean.ttf \
    deps/imgui-1.89.1/misc/fonts/ProggyTiny.ttf \
    deps/imgui-1.89.1/misc/fonts/Roboto-Medium.ttf \
    deps/imgui-1.89.1/misc/freetype/README.md \
    src/batch-rename-h-to-cpp.bat
