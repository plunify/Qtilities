# ***************************************************************************
# Copyright (c) 2009-2013, Jaco Naudé
#
# See http://www.qtilities.org/licensing.html for licensing details.
#
# ***************************************************************************
# Qtilities - Qt Utility Libraries
# Qtilities Core Library
# ***************************************************************************
QTILITIES += logging
include(../Qtilities.pri)
INCLUDEPATH += $$QTILITIES_INCLUDE/QtilitiesCore

CONFIG += qt dll
CONFIG += c++11

QT += core xml
# Note: xml module is deprecated
QT -= gui

TARGET = QtilitiesCore$${QTILITIES_LIB_POSTFIX}

TEMPLATE = lib
DEFINES += QTILITIESCORE_LIBRARY
DESTDIR = $$QTILITIES_BIN

OBJECTS_DIR = $$QTILITIES_TEMP/Core
MOC_DIR = $$QTILITIES_TEMP/Core
RCC_DIR = $$QTILITIES_TEMP/Core
UI_DIR = $$QTILITIES_TEMP/Core

# --------------------------
# Qtilities Core Files
# --------------------------
HEADERS += source/QtilitiesCore_global.h \
    source/QtilitiesCoreApplication.h \
    source/QtilitiesCoreApplication_p.h \
    source/QtilitiesCoreConstants.h \
    source/Observer.h \
    source/PointerList.h \
    source/ObserverData.h \
    source/AbstractSubjectFilter.h \
    source/ActivityPolicyFilter.h \
    source/ObjectManager.h \
    source/QtilitiesPropertyChangeEvent.h \
    source/ObserverMimeData.h \
    source/IObjectManager.h \
    source/SubjectTypeFilter.h \
    source/IExportable.h \
    source/IFactoryProvider.h \
    source/ObserverRelationalTable.h \
    source/Factory.h \
    source/IModificationNotifier.h \
    source/IContext.h \
    source/IContextManager.h \
    source/ContextManager.h \
    source/IObjectBase.h \
    source/ObserverHints.h \
    source/SubjectFilterTemplate.h \
    source/QtilitiesCategory.h \
    source/IExportableFormatting.h \
    ../Common/Qtilities.h \
    source/QtilitiesFileInfo.h \
    source/ObserverDotWriter.h \
    source/VersionInformation.h \
    source/InstanceFactoryInfo.h \
    source/QtilitiesProperty.h \
    source/IIterator.h \
    source/SubjectIterator.h \
    source/TreeIterator.h \
    source/IExportableObserver.h \
    source/ITask.h \
    source/Task.h \
    source/TaskManager.h \
    source/ITaskContainer.h \
    source/FileUtils.h \
    source/QtilitiesProcess.h \
    source/FileSetInfo.h \
    source/FileLocker.h \
    source/IAvailablePropertyProvider.h \
    source/GenericProperty.h \
    source/GenericPropertyManager.h \
    source/Zipper.h

SOURCES += source/QtilitiesCoreApplication.cpp \
    source/QtilitiesCoreApplication_p.cpp \
    source/Observer.cpp \
    source/ActivityPolicyFilter.cpp \
    source/ObjectManager.cpp \
    source/QtilitiesPropertyChangeEvent.cpp \
    source/SubjectTypeFilter.cpp \
    source/ObserverData.cpp \
    source/ObserverRelationalTable.cpp \
    source/ContextManager.cpp \
    source/ObserverHints.cpp \
    source/SubjectFilterTemplate.cpp \
    source/QtilitiesCategory.cpp \
    source/PointerList.cpp \
    source/QtilitiesFileInfo.cpp \
    source/ObserverDotWriter.cpp \
    source/VersionInformation.cpp \
    source/InstanceFactoryInfo.cpp \
    source/QtilitiesProperty.cpp \
    source/IExportable.cpp \
    source/TaskManager.cpp \
    source/ITaskContainer.cpp \
    source/Task.cpp \
    source/FileUtils.cpp \
    source/QtilitiesProcess.cpp \
    source/FileSetInfo.cpp \
    source/FileLocker.cpp \
    source/GenericProperty.cpp \
    source/GenericPropertyManager.cpp \
    source/Zipper.cpp
