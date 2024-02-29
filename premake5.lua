
workspace "OpenGL-Mini-Engine"
    configurations {"Debug", "Release"}
    location "build"

    filter "system:windows"
        architecture "x86_64"
    filter {}

    files {
        "src/**.cpp",
        "vendor/src/ImGui/**.cpp"
    }

    includedirs {
        "include",
        "vendor/include",
        "vendor/include/ImGui",
        "resources"
    }

    newaction {
        trigger     = "resources",
        description = "Copy resources into the bin folder",
        execute = function ()
            if os.host() == "windows" then
                os.execute("xcopy /s resources\\* build\\bin\\Release\\")
            else
                os.execute("cp -r resources/* build/bin/Release/")
            end
        end
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
