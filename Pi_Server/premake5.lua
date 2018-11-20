workspace "Pi_Server"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "Pi_Server"
	location "Pi_Server"
	kind "SharedLib"
	
	language "C++"
	language "C"
	
	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs 
	{
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
	defines
	{
		"PIS_PLATFORM_WINDOWS",
		"PIS_BUILD_DLL"
	}
		
	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}
		
	filter "configurations:Debug"
		defines "PIS_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "PIS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PIS_DIST"
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
		"Pi_Server/vendor/spdlog/include",
		"Pi_Server/src"
	}
	
	links
	{	
	 	"Pi_Server"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
		"PIS_PLATFORM_WINDOWS",
		}
		
		
	filter "configurations:Debug"
		defines "PIS_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "PIS_REALEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PIS_DIST"
		optimize "On"	