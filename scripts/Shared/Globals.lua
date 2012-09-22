-- CEGUI globals
CELogger = nil
CESystem = nil
CEWindowMgr = nil
CEFontMgr = nil
CESchemeMgr = nil
CEImageMgr = nil
CEAnimMgr = nil

-- Elementum globals
  if not Hax then Hax = {} end

  -- Managers
  EvtMgr = nil
  GameMgr = nil
  InputMgr = nil

  -- GameStates
  IntroState = nil

  -- Engines
  GfxEngine = nil
  FxEngine = nil
  UIEngine = nil
  ScriptEngine = nil

  update = nil
  cleanup = nil

-- Ogre globals
SceneMgr = nil
CompositorMgr = nil
Viewport = nil
Window = nil
Camera = nil
CameraMan = nil
AR = { Width = 0, Height = 0 }

local registered = false
Hax.registerGlobals = function()

  if registered then return true end

	Hax.Log( "*************************************************")
	Hax.Log( "* Launching Hax.Lua module!                    *")

	-- registers CEGUI singletons as globals for use by the UI sheets
  print("Dumping CEGUI:")
  table.dump(CEGUI)
	CELogger = CEGUI.Logger:getSingleton()
	CELogger:logEvent( ">>> Hax.LUA scripts engaging" )
	--CELogger:setLoggingLevel( CEGUI.Informative )

	-- get a local reference to the singletons we use (not required)
	CESystem    = CEGUI.System:getSingleton()
	CEWindowMgr = CEGUI.WindowManager:getSingleton()
	CEFontMgr   = CEGUI.FontManager:getSingleton()
	CESchemeMgr = CEGUI.SchemeManager:getSingleton()
	CEImageMgr = CEGUI.ImagesetManager:getSingleton()
  CEAnimMgr = CEGUI.AnimationManager:getSingleton()

	GameMgr = Hax.GameManager:getSingleton()
	EvtMgr = Hax.EventManager:getSingletonPtr()
  InputMgr = Hax.InputManager:getSingletonPtr()

  IntroState = Hax.Intro:getSingletonPtr()

  GfxEngine = Hax.GfxEngine:getSingletonPtr()
  FxEngine = Hax.FxEngine:getSingleton()
  UIEngine = Hax.UIEngine:getSingletonPtr()
  ScriptEngine = Hax.ScriptEngine:getSingletonPtr()

  SceneMgr = GfxEngine:getSceneMgr()
  CompositorMgr = Ogre.CompositorManager:getSingletonPtr()
  Viewport = GfxEngine:getViewport()
  Window = GfxEngine:getWindow()
  Camera = GfxEngine:getCamera()
  CameraMan = GfxEngine:getCameraMan()
  AR = { Width = Viewport:getActualWidth(), Height = Viewport:getActualHeight() }

	Hax.Log( "* Launched successfully!                        *")
	Hax.Log( "*************************************************")

	registered = true
end
