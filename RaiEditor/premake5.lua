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

  includedirs
  {
    "%{wks.location}/Rai/src",
    "%{wks.location}/Rai/vendor",
    "%{wks.location}/Rai/vendor/spdlog/include",
  }

  links
  {
    "Rai"
  }

  filter "configurations:Debug"
    defines "RAI_DEBUG"
    runtime "Debug"
    symbols "on"

  filter "configurations:Release"
    defines "RAI_RELEASE"
    runtime "Release"
    optimize "on"
