include "Dependencies.lua"

function includeGLFW()
  includedirs "%{wks.location}/Rai/vendor/glfw/include"
end

function linkGLFW()
  libdirs "%{wks.location}/Rai/vendor/glfw/lib"

  filter "kind:not StaticLib"
    links
    {
      "glfw3",
      "Cocoa.framework",
      "IOKit.framework"
    }
  filter {}
end

function useRai()
  includedirs 
  {
    "%{wks.location}/Rai/src",
    "%{wks.location}/Rai/vendor/spdlog/include"
  }

  links "Rai"

  linkGLFW()
end

workspace "Rai"
  architecture "x64"
  startproject "RaiEditor"

  configurations
  {
    "Debug",
    "Release"
  }

  flags
  {
    "MultiProcessorCompile"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
  include "vendor/premake"

include "Rai"
include "RaiEditor"
