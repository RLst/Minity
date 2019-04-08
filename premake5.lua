workspace "Minity"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

----------------- MINITY ---------------------------
project "Minity"
	location "Minity"	--Put files inside Minity\Minity\
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bimd/" .. outputdir .. "/%{prj.name}")		--so that it is grouped together with bin\

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/dep/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MNT_PLATFORM_WINDOWS",
			"MNT_BUILD_DLL"
			--"_WINDLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} .. /bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "MNT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MNT_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "MNT_DISTRIBUTION"
		optimize "On"

	-- filter { "system:windows", "configurations:Release" }	--example of how to set release configuration on windows to have multithreading
	-- 	buildoptions "/MT"
	
-------------------- SANDBOX ----------------------
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bimd/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/dep/spdlog/include",
		"Minity/src"
	}

	links
	{
		"Minity"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MNT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MNT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MNT_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "MNT_DISTRIBUTION"
		optimize "On"