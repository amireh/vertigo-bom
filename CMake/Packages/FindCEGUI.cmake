# Locate CEGUI
# This module defines
# CEGUI_LIBRARY
# CEGUI_FOUND, if false, do not try to link to CEGUI
# CEGUI_INCLUDE_DIR, where to find the headers
#
# $CEGUI_DIR is an environment variable that would
# correspond to the ./configure --prefix=$CEGUI_DIR
#
# Created by David Guthrie with code from Robert Osfield.
# Modified by Ahmad Amireh.

FIND_PATH(CEGUI_INCLUDE_DIR CEGUI/CEGUI.h CEGUI.h
    PATHS
    $ENV{CEGUI_DIR}/include
    $ENV{CEGUIDIR}/include
    $ENV{CEGUI_ROOT}/include
    ${DELTA3D_EXT_DIR}/inc
    ${DELTA3D_EXT_DIR}/Frameworks
    ~/Library/Frameworks
    /Library/Frameworks
    /usr/local/include
    /usr/local/include/CEGUI
    /usr/include
    /sw/include # Fink
    /opt/local/include # DarwinPorts
    /opt/csw/include # Blastwave
    /opt/include
    /usr/freeware/include
	C:/Workspace/Build/CEGUI/include
	C:/Workspace/Build/CEGUI/cegui/include
)

IF (APPLE)
   FIND_PATH(CEGUI_FRAMEWORK_DIR CEGUI.h
     PATHS
       ~/Library/Frameworks/CEGUI.framework/Headers
       /Library/Frameworks/CEGUI.framework/Headers
       ${DELTA3D_EXT_DIR}/Frameworks/CEGUI.framework/Headers
       /usr/local/lib/CEGUI/CEGUIBase.framework/Headers
)
ENDIF (APPLE)

IF (CEGUI_FRAMEWORK_DIR)
   SET(CEGUI_INCLUDE_DIR ${CEGUI_INCLUDE_DIR} ${CEGUI_FRAMEWORK_DIR})
ELSE (CEGUI_FRAMEWORK_DIR)
   SET(CEGUI_INCLUDE_DIR ${CEGUI_INCLUDE_DIR} ${CEGUI_INCLUDE_DIR}/CEGUI)
ENDIF (CEGUI_FRAMEWORK_DIR)

MACRO(FIND_CEGUI_LIBRARY MYLIBRARY MYLIBRARYNAMES)

    FIND_LIBRARY(${MYLIBRARY}
        NAMES ${MYLIBRARYNAMES}
        PATHS
        $ENV{CEGUI_DIR}/lib
        $ENV{CEGUI_DIR}
        $ENV{CEGUIDIR}/lib
        $ENV{CEGUIDIR}
        $ENV{CEGUI_ROOT}/lib
        ${DELTA3D_EXT_DIR}/lib
        $ENV{DELTA_ROOT}/ext/lib
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local/lib
        /usr/local/lib/CEGUI
        /usr/lib
        /sw/lib
        /opt/local/lib
        /opt/csw/lib
        /opt/lib
        [HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session\ Manager\\Environment;CEGUI_ROOT]/lib
        /usr/freeware/lib64
		C:/Workspace/Build/CEGUI/lib
		C:/Workspace/Build/CEGUI/lib/ReleaseWithSymbols
		C:/Workspace/Build/CEGUI/lib/Release
    )

	FIND_PATH(CEGUI_LIBRARY_DIRS CEGUIBase.lib CEGUIBase.so CEGUIBase.a
	    PATHS
        $ENV{CEGUI_DIR}/lib
        $ENV{CEGUI_DIR}
        $ENV{CEGUIDIR}/lib
        $ENV{CEGUIDIR}
        $ENV{CEGUI_ROOT}/lib
        ${DELTA3D_EXT_DIR}/lib
        $ENV{DELTA_ROOT}/ext/lib
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local/lib
        /usr/local/lib/CEGUI
        /usr/lib
        /sw/lib
        /opt/local/lib
        /opt/csw/lib
        /opt/lib
        [HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session\ Manager\\Environment;CEGUI_ROOT]/lib
        /usr/freeware/lib64
		C:/Workspace/Build/CEGUI/lib/ReleaseWithSymbols
		C:/Workspace/Build/CEGUI/lib/Release)

ENDMACRO(FIND_CEGUI_LIBRARY LIBRARY LIBRARYNAME)

FIND_CEGUI_LIBRARY(CEGUI_LIBRARY "CEGUIBase")
FIND_CEGUI_LIBRARY(CEGUICoreWindowRendererSet_LIBRARY "CEGUICoreWindowRendererSet")
FIND_CEGUI_LIBRARY(CEGUICommonDialogs_LIBRARY "CEGUICommonDialogs")
FIND_CEGUI_LIBRARY(CEGUIOgre_LIBRARY "CEGUIOgreRenderer")
FIND_CEGUI_LIBRARY(CEGUILuaScriptModule_LIBRARY "CEGUILuaScriptModule")

FIND_CEGUI_LIBRARY(CEGUI_LIBRARY_DEBUG CEGUIBase_d)
FIND_CEGUI_LIBRARY(CEGUIOgre_LIBRARY_DEBUG CEGUIOgreRenderer_d)

SET(CEGUI_FOUND "NO")
IF(CEGUI_LIBRARY AND CEGUI_INCLUDE_DIR)
    SET(CEGUI_FOUND "YES")
ENDIF(CEGUI_LIBRARY AND CEGUI_INCLUDE_DIR)
