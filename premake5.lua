
workspace "OpenGL-Mini-Engine"
    configurations {"Release", "Debug"}
    location "build"
    language "C++"
    cppdialect "C++17"

    filter "system:windows"
        architecture "x86_64"
    filter {}

    newaction {
        trigger     = "resources",
        description = "Copy resources into the bin folder",
        execute = function ()
            if os.host() == "windows" then
                os.execute("xcopy /s /i resources\\* build\\app\\bin\\Release\\")
                os.execute("xcopy /s /i resources\\* build\\app\\bin\\Debug\\")
            else
                os.execute("cp -nr resources/* build/app/bin/Release/")
                os.execute("cp -nr resources/* build/app/bin/Debug/")
            end
        end
    }

    newaction {
        trigger     = "docs",
        description = "Generate documentation with Doxygen",
        execute     = function()
            os.execute("doxygen Doxyfile")
        end
    }

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    filter "configurations:Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

project "Lib"
    kind "StaticLib"
    location "build/lib"
    
    files {
        "src/**.cpp",
        "vendor/src/ImGui/**.cpp",
        "vendor/src/glad/glad.c",
        "vendor/src/stb_image/stb_image.cpp"
    }

    includedirs {
        "src",
        "vendor/include",
        "vendor/include/ImGui",
    }

project "App"
    kind "ConsoleApp"
    location "build/app"
    targetname "Engine"

    files "main.cpp"
    includedirs "src"

    dependson "Lib"
    links "Lib:static"
    filter "configurations:Debug"
        libdirs "build/lib/bin/Debug/"
    filter "configurations:Release"
        libdirs "build/lib/bin/Release"

    -- Link GLFW
    filter "system:windows"
        libdirs "vendor/lib/GLFW"
        links "glfw3.lib"
    filter "system:linux"
        libdirs "/lib"
        links "glfw"

project "Test"
    kind "ConsoleApp"
    location "build/test"
    
    files "test/**.cpp"
    includedirs {
        "src",
        "vendor/include",
        "vendor/include/ImGui"
    }
    
    dependson "Lib"
    links "Lib:static"
    filter "configurations:Debug"
        libdirs "build/lib/bin/Debug/"
    filter "configurations:Release"
        libdirs "build/lib/bin/Release"
