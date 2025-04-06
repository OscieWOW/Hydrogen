workspace "Hydrogen"
    architecture "x64"

    configurations{
        "Debug",
        "Release",
        "Dist"
    }

outputDir = "%{cfg.system}/%{cfg.architecture}/%{cfg.buildcfg}"

project "Hydrogen"
    location "Hydrogen"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {

    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "on"
        systemversion "latest"
        buildoptions "/MDd"
        
        defines {
            "PLATFORM_WINDOWS",
            "BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputDir.."/ExampleApplication")
        }
    
    filter "configurations:Debug"
        defines "H_RELEASE"
        symbols "on"
    
    filter "configurations:Release"
        defines "H_RELEASE"
        optimize "on"
    
    filter "configurations:Dist"
        defines "H_DIST"
        optimize "on"

project "ExampleApplication"
    location "ExampleApplication"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Hydrogen/src"
    }

    links {
        "Hydrogen"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "on"
        systemversion "latest"
        buildoptions "/MDd"

        defines {
            "PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "H_RELEASE"
        symbols "on"

    filter "configurations:Release"
        defines "H_RELEASE"
        optimize "on"

    filter "configurations:Dist"
        defines "H_DIST"
        optimize "on"
