# ***************************************************************************
# Copyright (c) 2009-2013, Jaco Naudé
#
# See http://www.qtilities.org/licensing.html for licensing details.
#
# ***************************************************************************
# Qtilities - Qt Utility Libraries
# Logging Library
# ***************************************************************************

include(../Qtilities.pri)
INCLUDEPATH += $$QTILITIES_INCLUDE/QtilitiesLogging
INCLUDEPATH += $$QTILITIES_SOURCE/Common

CONFIG += qt dll
CONFIG += c++11

QT += core
QT -= gui

TARGET = QtilitiesLogging$${QTILITIES_LIB_POSTFIX}

TEMPLATE = lib
DEFINES += LOGGING_LIBRARY
DESTDIR = $$QTILITIES_BIN

OBJECTS_DIR = $$QTILITIES_TEMP/Logging
MOC_DIR = $$QTILITIES_TEMP/Logging
RCC_DIR = $$QTILITIES_TEMP/Logging
UI_DIR = $$QTILITIES_TEMP/Logging

# --------------------------
# Logging Library Files
# --------------------------
HEADERS += source/Logging_global.h \
    source/LoggingConstants.h \
    source/AbstractFormattingEngine.h \
    source/AbstractLoggerEngine.h \
    source/FormattingEngines.h \
    source/Logger.h \
    source/LoggerEngines.h \
    source/LoggerFactory.h \
    source/ILoggerExportable.h

SOURCES += source/AbstractLoggerEngine.cpp \
    source/Logger.cpp \
    source/LoggerEngines.cpp \
    source/FormattingEngines.cpp
