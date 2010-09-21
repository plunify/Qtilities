# ***************************************************************************
# Copyright (c) 2009-2010, Jaco Naude
#
# See http://www.qtilities.org/licensing.html for licensing details.
#
# ***************************************************************************
# Qtilities Debug Plugin Library
# ***************************************************************************
QTILITIES += extension_system
QTILITIES += project_management
include(../../Qtilities.pri)

CONFIG(debug, debug|release) {
    TARGET = DebugPlugind
} else {
    TARGET = DebugPlugin
}

DESTDIR += $$QTILITIES_BIN/plugins
TEMPLATE = lib
DEFINES += DEBUG_PLUGIN_LIBRARY
CONFIG += plugin

# ------------------------------
# Temp Output Paths
# ------------------------------
OBJECTS_DIR     = $$QTILITIES_TEMP/DebugPlugin
MOC_DIR         = $$QTILITIES_TEMP/DebugPlugin
RCC_DIR         = $$QTILITIES_TEMP/DebugPlugin
UI_DIR          = $$QTILITIES_TEMP/DebugPlugin

# --------------------------
# Library Files
# --------------------------
HEADERS += source/DebugPlugin.h \
           source/DebugPlugin_global.h \
           source/DebugPluginConstants.h \
           source/DebugWidget.h

SOURCES += source/DebugPlugin.cpp \
           source/DebugWidget.cpp

RESOURCES += resources/resources.qrc

FORMS += \
    source/DebugWidget.ui
