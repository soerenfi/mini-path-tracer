-- premake5.lua
workspace "MiniPathTracer"
   architecture "x64"
   configurations { "Debug", "Release" }
   startproject "MiniPathTracer"
   outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
   
   require "export-compile-commands"
      
   defines {"TRACY_ENABLE"}
   
   -- project "Tracy"
   --    kind "StaticLib"
   --    language "C++"
   --    cppdialect "C++17"
   --    targetdir "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
   --    staticruntime "off"

   --    files { "thirdparty/tracy/public/TracyClient.cpp" }

   --    includedirs
   --    {
   --       "thirdparty/tracy/public"
   --    }

   include "Walnut/WalnutExternal.lua"

   include "MiniPathTracer"
