Fx = {}
local isSetup = false
local HighlightEffect = nil
Fx.setup = function()
  if isSetup then return true end

  Hax.Log("Registering spell effects")

  isSetup = true
  return true
end

Fx.cleanup = function()
  FxEngine:unloadAllEffects()
  isSetup = false
end

Fx.highlight = function(rnd)
  if HighlightEffect then HighlightEffect:stop() end
  FxEngine:playEffect(highlight_effect, rnd)
end

Fx.dehighlight = function()
  if HighlightEffect then HighlightEffect:stop() end
end
