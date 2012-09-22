-- resolve script paths
do
  ScriptPrefix = Hax.ScriptEngine:getSingletonPtr():getScriptPathPrefix()
  package.path = ScriptPrefix .. "/?.lua;" .. package.path
  ModulePrefix = Hax.ScriptEngine:getSingletonPtr():getModulePathPrefix()
  package.cpath = ModulePrefix .. "/?.so;" .. package.cpath

  print("Scripts path: " .. ScriptPrefix .. "\nModule path: " .. ModulePrefix)
end

require("Hax")

if not Intro then Intro = {} end

Hax.Log("HERE")

require("Intro/Intro")
-- require("Intro/Simulation")
require("Intro/Bindings")
