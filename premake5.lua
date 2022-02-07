include "Dependencies.lua"

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
