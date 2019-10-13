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

### Windows

It is highly recommended to use Visual Studio 2019 (or up) with [vcpkg](https://github.com/Microsoft/vcpkg).
We suggest to install all dependecies that are submodules via `vcpkg`, to avoid a lot of confilcts and asspain.
Thus, you should install boost libaraies via `vcpkg`. You can install not whole library, just subs, like `boost-thread` and others.
If some dependencies could not be resolved, `Visual Studio` will automatically suggest to install it via `vcpkg`.
In other cases, generate dependency projects as told in their READMEs and chack links to them in solution.
Whih dependecies are higly recommended to install via vcpkg?:
* assimp
* glfw
* glm
* lua
* freeglut
* glew

Unfortunately, bgfx, bimg and bx are not avaliable via vcpkg, and you need to build them with your own. Just initialize submodules, then generate Visual Studio projects for them. Also, you can fix broken links to them on NukeEngine solution, if this happened.
So, try to build it!

> Note: It would be better to clone NukeEngine Editor nearby NukeEngine root directory.

> The best hierarchy scheme for solution:
+ [NE]
  + [NukeEngine] (repo)
    + .... (files)
  + [NukeEngine-Editor] (repo)
    + .... (files)

### Linux
The build system, used by project, is `qmake`, so you can just use Qt Creator to build it, or even simple qmake, if you have qt tools.

If you see next errors:
`error: cannot find -lglut`
or the same, you need to install development files of needed libraries(e.g. `freeglut`, or `glew` for this case).

If you see smth like this:
```
.../projects/NE/NukeEngine/API/Model/Include.h:3: error: boost/container/list.hpp: No such file or directory
 #include <boost/container/list.hpp>
          ^~~~~~~~~~~~~~~~~~~~~~~~~~
```
You need to install boost libraries sources.

#### Building the assimp:
Int the project dir, goto `deps/assimp`, then:

```
cmake CMakeLists.txt
make -j4 install
```

j4 means that you will use 4 threads for building.


### MacOS [Attention!!!]

You will need to do some preparations for building NukeEngine on Mac:

+ Install XQuartz - required by freeglut
+ Install homebrew - required for next
+ Install freeglut via brew
+ Install glew via brew
+ Install glfw via brew
+ Install boost via brew
+ Install assimp via brew (you should better build it own and install build into system, its always fresh)
+ Install other via brew if you cannot install it in another way
