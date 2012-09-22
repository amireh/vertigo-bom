Hax.UI = {
  Attached = {}, -- a list of attached UISheets
  CurrentSheet = nil, -- points to the currently attached UISheet
  Dialog = {
    Window = nil,
    Label = nil,
    OkButton = nil,
    OkCallback = nil
  },
  Defaults = {
    Font = "DejaVuSans-10",
    MouseCursor = {
      ImageSet = "TaharezLook",
      Image = "MouseArrow"
    }
  }
}

Hax.UI.setup = function()
  if isSetup then return true end

	-- load schemes
  CESchemeMgr:create( "TaharezLook.scheme" )
	CESchemeMgr:create( "VanillaSkin.scheme" )
	-- CESchemeMgr:createFromFile( "WindowsLook.scheme" )
	-- CESchemeMgr:createFromFile( "VanillaSkin.scheme" )
	-- CESchemeMgr:createFromFile( "CombatSkin.scheme" )

	-- create our imagesets used for spell buttons
	--~ CEImageMgr:create( "spells_earth.imageset" )
	--~ CEImageMgr:create( "spells_fire.imageset" )
  --~ CEImageMgr:create( "huds.imageset" )

	-- load a default font
  local defaults = Hax.UI.Defaults
	CESystem:setDefaultFont( defaults.Font )
	-- set default mouse cursor
	CESystem:setDefaultMouseCursor( defaults.MouseCursor.ImageSet, defaults.MouseCursor.Image )
  -- CESystem:getDefaultGUIContext():getMouseCursor():setDefaultImage( defaults.MouseCursor.Image )

	-- set up the dialog
	Hax.UI.Dialog.Window = CEWindowMgr:loadWindowLayout("overlays/dialog.layout")
	--~ Hax.UI.Dialog.Label = Hax.UI.Dialog.Window:getChild("Elementum/Overlays/Dialog/Label")
	Hax.UI.Dialog.Label = Hax.UI.Dialog.Window:getChild("Dialog_Label")
	Hax.UI.Dialog.OkButton = Hax.UI.Dialog.Window:getChild("Dialog_OkButton")
	Hax.UI.Dialog.CancelButton = Hax.UI.Dialog.Window:getChild("Dialog_CancelButton")
  Hax.UI.Dialog.CancelButton:hide()
  Hax.UI.Dialog.OkButton:setProperty("HorizontalAlignment", "Centre")
	Hax.UI.Dialog.Window:hide()

  require "Shared/UI/UISheet"
  require "Shared/UI/UIDialogs"
  require "Shared/UI/UIAnimable"

  isSetup = true
  return true
end

Hax.UI.cleanup = function()
  if not isSetup then return true end

  Hax.Log("Cleaning up all registered UI Sheets. Total = " .. #Hax.UI.Attached)

  -- destroy all UISheets
  while #Hax.UI.Attached > 0 do
    Hax.UI.Attached[1]:destroy()
  end
  for sheet in list_iter(Hax.UI.Attached) do
    sheet:destroy()
  end

  assert(#Hax.UI.Attached == 0)

  CEWindowMgr:destroyWindow(Hax.UI.Dialog.Window)
  Hax.UI.Dialog = {}

  isSetup = false
  return true
end
