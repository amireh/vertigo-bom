-- resolve script paths
do
  ScriptPrefix = Hax.ScriptEngine:getSingletonPtr():getScriptPathPrefix()
  package.path = ScriptPrefix .. "/?.lua;" .. package.path
  ModulePrefix = Hax.ScriptEngine:getSingletonPtr():getModulePathPrefix()
  package.cpath = ModulePrefix .. "/?.so;" .. package.cpath

  print("Scripts path: " .. ScriptPrefix .. "\nModule path: " .. ModulePrefix)
end

require "Shared/Helpers"
require "Shared/Globals"
require "Shared/Dispatcher"
require "Shared/Cyclable"
require "Shared/Input"
require "Shared/UI"
require "Shared/Fx"

function arbitrary(name, ...)
  -- construct the method pointer
  local _p = _G
  for word in list_iter(all_words(name)) do
    _p = _p[word]
    if not _p then
      return error("attempting to call an invalid arbitrary method: " .. name)
    end
  end

  return _p(unpack(arg))
end

WantUpdates = {}
Hax.doUpdateMe = function(inCallback)
	table.insert(WantUpdates, inCallback)
end

Hax.dontUpdateMe = function(inCallback)
	local i = 1
	for method in list_iter(WantUpdates) do
	  if method == inCallback then
	    table.remove(WantUpdates, i)
			break
	  end
	  i = i+1
	end
end

Hax.update = function(dt)
	for callback in list_iter(WantUpdates) do
		callback(dt)
	end
end

-- this should be called once during the client's lifetime
-- for state bootstrapping, see State.onEnter
local isSetup = false
Hax.onEnter = function()
  if isSetup then return true end

  Hax.registerGlobals()
  require "Shared/Aliases"

  Dispatcher.setup()
  Hax.UI.setup()
  Input.setup()
  Fx.setup()

  isSetup = true
  return true
end

-- this should be called only when a shutdown is performed
-- for state cleanups, see State.onExit
Hax.onExit = function()
  Fx.cleanup()
  Input.cleanup()
  Hax.UI.cleanup()
  Dispatcher.cleanup()
end
