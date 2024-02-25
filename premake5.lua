
workspace "OpenGL-Mini-Engine"
    configurations {"Debug", "Release"}
    location "build"

    filter "system:windows"
        architecture "x86_64"
    filter {}

    files {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs {
        "src",
        "vendor/include"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

project "Engine"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    location "build"
    
    files {
        "main.cpp",
        "vendor/src/glad/glad.c",
        "vendor/src/stb_image/stb_image.cpp"
    }
    
    -- Link GLFW
    filter "system:windows"
        libdirs "vendor/lib/GLFW"
        links "glfw3.lib"
    
    filter "system:linux"
        libdirs "/lib"
        links "glfw"
