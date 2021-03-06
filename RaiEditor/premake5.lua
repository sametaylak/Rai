project "RaiEditor"
  kind "ConsoleApp"
  language "C++"
  cppdialect "C++17"
  staticruntime "off"

  targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
  objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "src/**.h",
    "src/**.cpp"
  }

  useRai()

  filter "configurations:Debug"
    defines "RAI_DEBUG"
    runtime "Debug"
    symbols "on"

  filter "configurations:Release"
    defines "RAI_RELEASE"
    runtime "Release"
    optimize "on"
