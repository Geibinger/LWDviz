workspace "LWDviz"
	architecture "x64"
	startproject "sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "LWDviz/vendor/GLFW/include"

include "LWDviz/vendor/GLFW"

project "LWDviz"
	location "LWDviz"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lwpch.h"
	pchsource "LWDviz/src/lwpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
  			"LV_PLATFORM_WINDOWS",
			"LV_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "LV_DEBUG"
		runtime "Debug"
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "LV_RELEASE"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "LV_DIST"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"LWDviz/vendor/spdlog/include",
		"LWDviz/src"
	}

	links
	{
		"LWDviz"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
  			"LV_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "LV_DEBUG"
		runtime "Debug"
		buildoptions "/MDd"
		symbols "on"

	filter "configurations:Release"
		defines "LV_RELEASE"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"

	filter "configurations:Dist"
		defines "LV_DIST"
		runtime "Release"
		buildoptions "/MD"
		optimize "on"