workspace "SailorEngine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "SailorEngine"
	location "SailorEngine"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"SE_PLATFORM_WINDOWS",
			"SE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "SE_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "SE_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "SE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
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
		"SailorEngine/vendor/spdlog/include",
		"SailorEngine/src"
	}

	links
	{
		"SailorEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"SE_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "SE_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "SE_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "SE_DIST"
		optimize "On"