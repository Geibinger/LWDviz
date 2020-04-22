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

project "LWDviz"
	location "LWDviz"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
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
		symbols "on"

	filter "configurations:Release"
		defines "LV_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "LV_DIST"
		runtime "Release"
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
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"LV_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "LV_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "LV_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "LV_DIST"
		runtime "Release"
		optimize "on"