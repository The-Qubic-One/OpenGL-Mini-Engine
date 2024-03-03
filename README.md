# OpenGL Mini Engine

A simplistic OpenGL 3D graphics engine written in C++ with the help of premake build system.

__Compatible with Linux AND Windows!__

## Dependencies:

> All dependencies besides the build tools are already included in the `vendor` directory and don't have to be installed.

__Build system__:
- premake5
- make and g++ or visual studio

__Graphics API__:
- GLFW3 3.3.8
- Glad for C/C++ with Core OpenGL 3.3

__Miscellaneous__:
- Boost 1.80.0
- GLM 0.9.8.5
- Stb Image
- Dear ImGui

# Compile & run:

Simply run the premake5 executable with the action that suits you, and then compile this action in the `build` directory.
I've also attatched two examples of how I'd do it with Visual Studio and Make:

> note that the premake5 resources action in necessary to do only once

__Visual Studio (Windows)__:
```powershell
premake5 vs2022
MSBuild .\build\OpenGL-Mini-Engine.sln -p:Configuration=Release
premake5 resources

# you can now run the app!
.\build\app\bin\Release\Engine.exe
```

__Make (Linux)__:
```bash
premake5 gmake2
make -C build App
premake5 resources

# you can now run the app!
./build/app/bin/Release/Engine
```

Afterwards, all project files are available in the `build/app/bin/Release/` directory, you can safely move it and use wherever you want.
If you encounter some problems, look into `log.txt` in `%APPDATA$\OpenGL-Mini-Engine` (Windows) or `~/.config/OpenGL-Mini-Engine` (Linux).

# Documentation

The project has configured support for doxygen, so you can easily generate documentation using:
```bash
premake5 docs
```
which you can access by opening `build/html/index.html` in your browser.
