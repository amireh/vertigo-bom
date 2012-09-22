Intro.onEnter = function()
  -- Selected points to the puppet that is chosen to join the lobby with.
  -- On switching to Combat state, Intro::setPuppetName() is called with
  -- this puppet's name so that Combat can tell which puppet is self's
  Selected = nil

  Hax.Log("Entering Intro state")

  -- clear all event bindings
  Dispatcher.clearBindings()
  Input.clearBindings()

  -- Fx.setup()
  -- Simulation:attach()

  Intro.bind()

end

Intro.onExit = function()
  Hax.Log("Cleaning up in Intro state")

  -- Simulation.cleanup()

  return true
end


Defaults = {

  CameraYawPitchDist = Ogre.Vector3(180, 30, 140),

  MTO = {
    Colour = Ogre.ColourValue(1,1,1),
    Font = "DejaVuSans",
    Size = 16,
    Material = "RedTransparent"
  },

  Fog = {
    Enabled = true,
    Colour = Ogre.ColourValue(0,0,0,1),
    Distance = 0.0015
  },

  UnitWalkSpeed = 0.10,
  UnitRotSpeed = 60,
  AnimFadeSpeed = 30
}
