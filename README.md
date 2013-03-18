Roxlu lib 0.0.0.0.1
-------------------
This is a experimental, personal library used for creative simulations. As 
you can see from the version it's not yet meant to be a stable version and it's
still changing.

Roxlu lib is build around opengl applications using GLFW as a wrapper to setup 
the GL context. Though, it's possible to use this library withouth opengl and
just as e.g. console application or library.  See the /compiler flags/ section
below for more information about this.

I'm using cmake as build system, and I try to make sure that this library
will run w/o making any changes to your CMakelists.txt files on Mac, Windows
and Linux, making roxlu lib really cross platform.

I've tried many different solution to make using this library as easy as possible. 
The easiest solution is to use the cmake files which makes it possible to compile
and run your application on Mac, Linux and Windows withouth making any changes, 
you simple run `build/cmake/run_release.sh` on Linux and Mac, and `build\cmake\run_release.bat`
on Windows.

But some of you will probably use an IDE like XCode or VisualStudio. I've tested
different solutions to create a zero setup solution to enable roxlu lib in your 
project by used `sub projects` which is both possible with Visual Studio and XCode.
Although these solutions look very interesting I found out that it has some 
flaws (e.g. compiler wide preprocessor flags are not possible with subprojects in 
XCode).

Therefore, to use this library you need to set the correct linker flags, preprocessor
flags and include paths manually.


Compiler flags
--------------

- The roxlu lib is prepared to be used with a couple of frameworks. Because the 
  addons all need openGL features we need to include the correct openGL headers and
  enable extensions (through the frameworks). Therefore all code in the lib that needs
  openGL features uses `#include <roxlu/opengl/GL.h>` which includes the correct header
  files to make opengl available. 

  **You should define one of the options below as a   global preprocessor flag**

  - `ROXLU_WITH_GLFW3_AND_GLEW`
  - `ROXLU_WITH_GLFW3_AND_GLXW`
  - `ROXLU_WITH_OPENFRAMEWORKS`
  - `ROXLU_WITH_OSX_NATIVE`


- Some defines are set based on the `ROXLU_WITH_*` define you're using. These are

  - `ROXLU_GL_CORE3`   if you want to target openGL 3.2 core profile, forward compat.
  - `GLEW_STATIC`      when using the cmake files this set for you. when you target < 3.x, make sure to 
                       define this in you preprocessor settings. @todo: this will be set in the GL header
                       depending on the set ROXLU_WITH_* preprocessor flag


Using roxlu lib and the addons
------------------------------
- Preprocessor flags (choose the one which fits your project)
  - `ROXLU_WITH_OPENFRAMEWORKS`
  - `ROXLU_WITH_GLFW3_AND_GLXW`
  - `ROXLU_WITH_OPENFRAMEWORKS`
  - `ROXLU_WITH_OSX_NATIVE`

- Include paths:
  - `roxlu/lib/include/`

- Source files:
  - `roxlu/lib/src/*.cpp`

Dependencies
============
Roxlu lib tries to be as portable as possible so you can develop on you platform of 
choice and compile and deploy on another system. Though some of the addons need system
specific libraries; for example DirectX on windows or libudev on Linux for some addons.

Linux
-----
On linux we depend on a couple of system libraries which you need to install for your 
specific distribution. I test this library on Ubuntu and Arch Linux.

/Install dependencies for Ubuntu/

   - apt-get install libudev-dev
   - apt-get install glu
        

Code Conventions
================
- all saving and loading use load and save functions with a parameter to  
  load/save from the data path `load(std::string filepath, bool datapath = false)` and `save(std::string filepath, bool datapath = false)`


TODO
----
- [ ] Remove all unused #defines and use compiler preprocessor flag if possible:
  -  Eg. opengl/error.h uses ROXLU_DEBUG, use NDEBUG

- `ROXLU_DEBUG:` enable verbose output for e.g. opengl shaders @todo maybe just use NDEBUG