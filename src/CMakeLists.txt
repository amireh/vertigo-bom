# add sources
SET(Hax_Bulk_SRCS
  Hax.cpp
  FileManager.cpp
  LogManager.cpp
  Configurator.cpp
  Configurable.cpp

  Entity.cpp
  Animable.cpp
  Renderable.cpp
  Identifiable.cpp
  Mobile.cpp

  Event.cpp
  EventListener.cpp
  EventManager.cpp

  FxEngine.cpp
  GameManager.cpp
  GameState.cpp
  Intro.cpp
  GfxEngine.cpp
  InputManager.cpp
  ScriptEngine.cpp
  UIEngine.cpp

  Main.cpp

  # CEGUI/FormattedListboxTextItem.cpp

  Ogre/MovableTextOverlay.cpp
  Ogre/RectLayoutManager.cpp
  Ogre/MousePicker.cpp
  # Ogre/OgreRTT.cpp

  log4cpp/VanillaLayout.cpp
  log4cpp/FileLayout.cpp
  # log4cpp/SyslogLayout.cpp

  binreloc/binreloc.c
)

SET(USING_TOLUAPP 1)

# using tolua++ for Lua bindings
if(USING_TOLUAPP)
  # command for generating the bindings
  ADD_CUSTOM_COMMAND(
    OUTPUT  ${CMAKE_CURRENT_SOURCE_DIR}/tolua++/wrappers/Hax_wrap.cxx
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tolua++/generate_wrappers.sh ${CMAKE_CURRENT_SOURCE_DIR}/tolua++
    COMMENT "Generating Hax tolua++ bindings")

  LIST(APPEND Hax_Bulk_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/tolua++/wrappers/Hax_wrap.cxx)
  LIST(APPEND Hax_Bulk_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/tolua++/wrappers/Ogre_wrap.cxx)
  # LIST(APPEND Hax_Bulk_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/tolua++/wrappers/CEGUI_wrap.cxx)
  LIST(APPEND Hax_Bulk_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/tolua++/wrappers/OIS_wrap.cxx)
endif()

# on Windows we use a static version of the library
SET(LIB_TYPE SHARED)
ADD_DEFINITIONS("-DENABLE_BINRELOC")

LIST(APPEND PROJECT_LIBS
  ${Boost_LIBRARIES}
  ${OGRE_LIBRARIES}
  ${CEGUI_LIBRARY}
  # ${CEGUICoreWindowRendererSet_LIBRARY}
  # ${CEGUICommonDialogs_LIBRARY}
  ${CEGUILuaScriptModule_LIBRARY}
  ${CEGUIOgre_LIBRARY}
  ${TOLUAPP_LIBRARIES}
  ${OIS_LIBRARIES}
  ${LOG4CPP_LIBRARIES}
  ${LUA_LIBRARIES}
  ${YAJL_LIBRARIES}
  ${CURL_LIBRARIES}
  pthread)

# the library
# ADD_LIBRARY(Hax ${LIB_TYPE} ${Hax_Bulk_SRCS})
ADD_EXECUTABLE(${PROJECT_NAME} ${Hax_Bulk_SRCS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${PROJECT_LIBS})

IF(USING_TOLUAPP)
  ADD_CUSTOM_TARGET(HaxLua DEPENDS tolua++/wrappers/Hax_wrap.cxx)
  IF(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tolua++/wrappers/Hax_wrap.cxx")
    MESSAGE(STATUS "Lua bindings are not yet generated, forcing generation. Generate manually using make HaxLua")
    ADD_DEPENDENCIES(${PROJECT_NAME} HaxLua)
  ENDIF()
  SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/tolua++/wrappers/Hax_wrap.cxx PROPERTIES GENERATED 1)
ENDIF()