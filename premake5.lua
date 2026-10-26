workspace "Hydrogen"
    architecture "x64"

    configurations{
        "Debug",
        "Release",
        "Dist"
    }

outputDir = "%{cfg.system}/%{cfg.architecture}/%{cfg.buildcfg}"
outputdir = outputDir

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Hydrogen/vendor/GLFW/include"
IncludeDir["GLAD"] = "%{wks.location}/Hydrogen/vendor/GLAD/include"
IncludeDir["GLM"] = "%{wks.location}/Hydrogen/vendor/GLM"
IncludeDir["CoreTrace"] = "%{wks.location}/Hydrogen/vendor/CoreTrace"

include "Hydrogen/vendor/GLFW"
include "Hydrogen/vendor/GLAD"
include "Hydrogen/vendor/GLMpremake5.lua"
include "Hydrogen/vendor/CoreTrace/premake-core.lua"

project "Hydrogen"

    location "Hydrogen"
    kind "StaticLib"
    language "C++"
    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
      "%{IncludeDir.GLAD}",
      "%{wks.location}/Hydrogen/vendor/GLFW/include",
      "%{IncludeDir.GLM}",
      "%{IncludeDir.CoreTrace}"
    }
    cppdialect "C++20"

    filter "system:windows"
    	links {
            "GLFW",
            "GLAD",
	    "CoreTrace",
            "opengl32.lib"
    	}

        staticruntime "on"
        systemversion "latest"
        buildoptions "/MTd"
        
        defines {
            "PLATFORM_WINDOWS",
            "BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputDir.."/ExampleApplication")
        }

    filter "system:linux"
    	links {
		"GLAD",
		"glfw",
		"GL",
		"CoreTrace",
		"dl",
		"pthread"
	}

    filter "configurations:Debug"
        defines "H_DEBUG"
        symbols "on"
    
    filter "configurations:Release"
        defines "H_RELEASE"
        optimize "on"
    
    filter "configurations:Dist"
        defines "H_DIST"
        optimize "on"
    
    filter {}

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
        "Hydrogen/src",
        "%{wks.location}/Hydrogen/vendor/GLFW/include",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.GLM}",
	"%{IncludeDir.CoreTrace}"
    }

    links {
        "Hydrogen"
    }

    cppdialect "C++20"
    filter "system:windows"
        staticruntime "on"
        systemversion "latest"
        buildoptions "/MTd"

        defines {
            "PLATFORM_WINDOWS"
        }
	
    filter "system:linux"
    	linkgroups "On"
    	links {
	    "Hydrogen",
	    "GLAD",
	    "glfw",
	    "GL",
	    "CoreTrace",
	    "dl",
	    "pthread"
	}

    filter "configurations:Debug"
        defines "H_DEBUG"
        symbols "on"

    filter "configurations:Release"
        defines "H_RELEASE"
        optimize "on"

    filter "configurations:Dist"
        defines "H_DIST"
        optimize "on"

    filter {}
