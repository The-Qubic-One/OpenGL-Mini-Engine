# OpenGL Mini Engine

A simplistic OpenGL 3D graphics engine written in C++ with the help of premake build system.

__Cross-platform compatible with Linux AND Windows!__

## Dependencies

Note: All dependencies besides the build tools are already included in the `vendor` directory and don't have to be installed.

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

## Compile & run

Simply run the premake5 executable with the action that suits you, and then compile this action in the `build` directory.
I've also attached two examples of how I'd do it with Visual Studio and Make:

Note: On Linux, the `premake5 resources` action will throw a message `cp: target 'build/app/bin/Debug/': No such file or directory`. You can safely disregard it.

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

Afterward, all project files are available in the `build/app/bin/Release/` directory, you can safely move it and use wherever you want.
If you encounter some problems, look into `log.txt` in `%APPDATA$\OpenGL-Mini-Engine` (Windows) or `~/.config/OpenGL-Mini-Engine` (Linux).

## Documentation

The project has configured support for doxygen, so you can easily generate documentation using:
```bash
premake5 docs
```
which you can access by opening `build/html/index.html` in your browser.

## Coding Style

I use chromium auto formatter and apply my custom naming style:

Types:
* __class and enums__: `UpperCamelCase`
* __interfaces__: `IUpperCamelCase` (with preceding `I`)
* __typedefs__: `snake_case_t` (with leading `_t`)

Symbols:
* __functions__: `lowerCamelCase`
* __variables__: `snake_case`
* __enum values and constants__: `UPPER_CASE`

Preprocessor:
* __header guards__: `PACKAGE_FILENAME_H_`
* __macros__: `UPPER_CASE_M` (with leading `_M`)

File system:
* __packages/src directories__: `snake_case`
* __filenames__: `.cpp` and `.h`

Example code:
```cpp
// inside src/core_gameplay/style_maker.h

#ifndef COREGAMEPLAY_STYLEMAKER_H_
#define COREGAMEPLAY_STYLEMAKER_H_

#define MACRO_M "just a macro"

typedef std::string str_t;

class StyleMaker {
  str_t normal_variable;
  const str_t CONSTANT;

 public:
  bool checkStyle(const str_t& good);
};

#endif
```

```cpp
// inside src/core_gameplay/style_maker.cpp

#include "core/style_maker.h"

bool StyleMaker::checkStyle(const str_t& good) {
  if (good == "good") {
    return true;
  } else if (good == "maybe") {
    return true;
  }
  return false;
}

```

## License

This project is released under the GNU Public License v3.
