/****************************************************************************
**
** Copyright (c) 2009-2010, Jaco Naude
**
** This file is part of Qtilities which is released under the following
** licensing options.
**
** Option 1: Open Source
** Under this license Qtilities is free software: you can
** redistribute it and/or modify it under the terms of the GNU General
** Public License as published by the Free Software Foundation, either
** version 3 of the License, or (at your option) any later version.
**
** Qtilities is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Qtilities. If not, see http://www.gnu.org/licenses/.
**
** Option 2: Commercial
** Alternatively, this library is also released under a commercial license
** that allows the development of closed source proprietary applications
** without restrictions on licensing. For more information on this option,
** please see the project website's licensing page:
** http://www.qtilities.org/licensing.html
**
** If you are unsure which license is appropriate for your use, please
** contact support@qtilities.org.
**
****************************************************************************/

#ifndef IMODE_H
#define IMODE_H

#include "QtilitiesCoreGui_global.h"

#include <IObjectBase>
#include <IContext>

#include <QWidget>
#include <QIcon>

namespace Qtilities {
    namespace CoreGui {
        namespace Interfaces {
            using namespace Qtilities::Core::Interfaces;

            /*!
            \class IMode
            \brief Used by the ModeManager to communicate with child modes.
              */
            class QTILITIES_CORE_GUI_SHARED_EXPORT IMode: virtual public IObjectBase, public IContext
            {

            public:
                IMode() : d_mode_id(-1) {}
                virtual ~IMode() {}

                //! The main window's central widget for the mode.
                /*!
                  This widget must have a proper layout in order to be displayed correctly.
                  */
                virtual QWidget* modeWidget() = 0;
                //! This function will be called everytime the QtilitiesMainWindow is resized allowing modes to resize their mode widgets explicitly.
                /*!
                  Normally it is not needed to reimplement this function. However in some cases where you are displaying a widget with a fixed sizeHint(), you
need to resize the widget in the implementation of this function.
                  */
                virtual void resizeModeWidget(const QSize& new_size) {}
                //! This function is called in the initializeDependancies() function, thus all objects implementing interfaces in which a mode might be interested will be present in the global object pool.
                virtual void initializeMode() = 0;
                //! An icon for the mode.
                /*!
                  The expected mode icon size is 48x48.
                  */
                virtual QIcon modeIcon() const = 0;
                //! The name of the mode which is the text used to represent it.
                virtual QString modeName() const = 0;
                //! Returns a context string for the context associated with this mode.
                /*!
                  By default no context will be associated with a mode.
                  */
                virtual QString contextString() const { return QString(); }
                //! Returns a help ID for this context.
                virtual QString contextHelpId() const { return QString(); }
                //! Returns a unique ID for this mode.
                /*!
                    A mode ID is an unique number which is associated with a mode in an application. This allows modes with the same name to
                    be added if desired. From the developer's perspective you don't have to reimplement this function in your interface
                    implementation. In that case the Qtilities::CoreGui::ModeManager class will assign an unique mode ID when the mode
                    is added to the mode manager and a debug message will be printed with information about the newly assigned mode ID.

                    It is however desired to specify your own mode ID in some cases, more specifically if you use the Qtilities::CoreGui::DynamicSideWidgetViewer
                    widget in your application and you want dynamic side viewer widgets to appear only in specific application modes. To achieve this
                    your modeID() must appear in the list of Qtilities::CoreGui::Interfaces::ISideViewerWidget::destinationModes() for a specific side viewer widget
                    implementation.

                    \note Mode IDs available for user modes range from 100 - 999. The mode manager starts to assign unique mode IDs from 1000 onwards.
                  */
                virtual int modeID() const { return d_mode_id; }
                //! Sets the mode ID for this mode.
                /*!
                  When your IMode implementation does not reimplement modeID(), it will automatically return the mode ID which was assigned by the ModeManager.
                  If you want to use your own mode ID you must reimplement modeID() and return your mode there, or set it using this function.
                  */
                inline void setModeID(int mode_id) { d_mode_id = mode_id; }

            private:
                int d_mode_id;
            };
        }
    }
}

Q_DECLARE_INTERFACE(Qtilities::CoreGui::Interfaces::IMode,"com.qtilities.CoreGui.IMode/1.0");

#endif // IMODE_H
