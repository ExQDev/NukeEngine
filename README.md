# NukeEngine

NukeEngine is a free, cross-platform modular engine. This project is an engine shared library.

## Get it

Just create anywhere a new folder for NukeEngine projects, where will be all other projects, relating to NukeEngine, and just clone this perository into it.

Then, do

```
git submodule init
git submodule update --recursive
```

Then, go to `deps/assimp`, build it and install, if you have not it already installed.

And this should be all done.


## Building

The build system, used by project, is `qmake`, so you can just use Qt Creator to build it, or even simple qmake, if you have qt tools.

If you see next errors:
`error: cannot find -lglut`
or the same, you need to install development files of needed libraries(e.g. `freeglut`, or `glew` for this case).

If you see smth like this:
```.../projects/NE/NukeEngine/API/Model/Include.h:3: error: boost/container/list.hpp: No such file or directory
 #include <boost/container/list.hpp>
          ^~~~~~~~~~~~~~~~~~~~~~~~~~
```
You need to install boost libraries sources.
