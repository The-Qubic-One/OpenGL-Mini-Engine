function linkGLFW()
    -- filter "system:windows"
    --     libdirs "vendor/lib/GLFW"

    --     Our static lib should not link against GLFW
    --     filter "kind:not StaticLib"
    --         links "glfw3"
        -- filter {}

    -- filter "system:linux"
        libdirs "/lib"
        links "glfw"
    -- filter {}
end

workspace "OpenGL-Mini-Engine"
    configurations {"Debug", "Release"}
    location "build"

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
    location "build/HelloProject"
    files { "main.cpp", "vendor/src/glad/glad.c", "vendor/src/stb_image/stb_image.cpp" }

    linkGLFW()
    
    includedirs {
        "vendor/include/glad"  -- Adjust the path to the directory containing GLAD headers
    }
