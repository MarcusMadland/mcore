project "mcore"
	kind "StaticLib"
	language "C++"
	cppdialect "C++14"
	exceptionhandling "Off"
	rtti "Off"
	defines "__STDC_FORMAT_MACROS"

	files
	{
		"include/**.hpp",
		"src/**.cpp",
	}

	includedirs
	{
		"include"
	}