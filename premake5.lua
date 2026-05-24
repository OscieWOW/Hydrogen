workspace "Hydrogen"
    architecture "x64"

    configurations{
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.system}/%{cfg.architecture}/%{cfg.buildcfg}"

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Hydrogen/vendor/GLFW/include"
IncludeDir["GLAD"] = "%{wks.location}/Hydrogen/vendor/GLAD/include"
IncludeDir["GLM"] = "%{wks.location}/Hydrogen/vendor/GLM"

include "Hydrogen/vendor/GLFW"
include "Hydrogen/vendor/GLAD"

project "Hydrogen"
    location "Hydrogen"
    kind "StaticLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
      "%{IncludeDir.GLAD}",
      "%{wks.location}/Hydrogen/vendor/GLFW/include",
      "%{IncludeDir.GLM}"
    }
    cppdialect "C++20"

    filter "system:windows"
    	links {
            "GLFW",
            "GLAD",
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
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.."/ExampleApplication")
        }

    filter "system:linux"
    	links {
		"GLAD",
		"glfw",
		"GL",
		"dl",
		"pthread"
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
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Hydrogen/src",
        "%{wks.location}/Hydrogen/vendor/GLFW/include",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.GLM}"
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
	    "dl",
	    "pthread"
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
