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
IncludeDir["Glad"] = "LWDviz/vendor/Glad/include"
IncludeDir["ImGui"] = "LWDviz/vendor/imgui"
IncludeDir["glm"] = "LWDviz/vendor/glm"

include "LWDviz/vendor/GLFW"
include "LWDviz/vendor/Glad"
include "LWDviz/vendor/imgui"

project "LWDviz"
	location "LWDviz"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lwpch.h"
	pchsource "LWDviz/src/lwpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/sandbox/\"")
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
  			"LW_PLATFORM_WINDOWS",
			"LW_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "LW_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "LW_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "LW_DIST"
		runtime "Release"
		optimize "on"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

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
		"LWDviz/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"LWDviz"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
  			"LW_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "LW_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "LW_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "LW_DIST"
		runtime "Release"
		optimize "on"