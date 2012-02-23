/****************************************************************************
**
** Copyright (c) 2009-2012, Jaco Naude
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

#ifndef STRING_LIST_WIDGET_H
#define STRING_LIST_WIDGET_H

#include "QtilitiesCoreGui_global.h"

#include <QMainWindow>
#include <QToolBar>
#include <QListView>

namespace Ui
{
    class StringListWidget;
}
class QStringListModel;

namespace Qtilities {
    namespace CoreGui {
        /*!
        \struct StringListWidgetPrivateData
        \brief A structure storing private data in the StringListWidget class.
          */
        struct StringListWidgetPrivateData;

        /*!
        \class StringListWidget
        \brief A widget which allows easy editing of a QStringList.

        The StringListWidget class is a simple widget which can be used to display a QStringList. You can give your string list a type using setStringType() and the list of strings to be displayed is set using setStringList().

        The widget is a QMainWindow with a toolbar at the top containing actions to remove and add strings. To customize the operation of the widget the string list model can be accessed using stringListModel() and the view can be accessed through listView().

        Below is an image of the string list widget with the string type set to "Architecture".

        \image html class_stringlistwidget_screenshot.jpg "The String List Widget"

        <i>This class was added in %Qtilities v1.0.</i>
          */
        class QTILITIES_CORE_GUI_SHARED_EXPORT StringListWidget : public QMainWindow
        {
            Q_OBJECT
            Q_ENUMS(ListType)

        public:
            //! The possible types of items which are listed in the string list widget.
            enum ListType {
                PlainStrings         = 0, /*!< Plain strings. */
                FilePaths            = 1, /*!< File paths. */
                Directories          = 2  /*!< Directories. */
            };

            StringListWidget(const QStringList& string_list = QStringList(), Qt::ToolBarArea toolbar_area = Qt::TopToolBarArea, QWidget * parent = 0, Qt::WindowFlags flags = 0);
            ~StringListWidget();

            //! Gets the current list of strings.
            QStringList stringList() const;
            //! Sets the current list of string.
            void setStringList(const QStringList& string_list);

            //! Gets the current list of non-removable only strings.
            QStringList nonRemovableStringList() const;
            //! Sets the current list of non-removable only strings.
            void setNonRemovableStringList(const QStringList& string_list);

            //! Gets the string type.
            QString stringType() const;
            //! Sets the string type.
            void setStringType(const QString& string_type);

            //! Gets the type of items in the list.
            ListType listType() const;
            //! Sets the type of items in the list.
            void setListType(const ListType& list_type);

            //! Gets the file open dialog path to be used for FilePaths and Directories ListType.
            QString fileOpenDialogPath() const;
            //! Sets the file open dialog path to be used for FilePaths and Directories ListType.
            void setFileOpenDialogPath(const QString& open_dialog_path);

            //! Gets the file open dialog filter to be used for FilePaths ListType.
            QString fileOpenDialogFilter() const;
            //! Sets the file open dialog filter to be used for FilePaths ListType.
            void setFileOpenDialogFilter(const QString& open_dialog_filter);

            //! Returns the list view used to display the strings.
            QListView* listView();
            //! Returns the QStringListModel used as the model in the list view.
            QStringListModel* stringListModel();

        signals:
            //! Signal emitted as soon as the list of string changed.
            void stringListChanged(const QStringList& string_list);
            //! Signal emitted when the selection changes.
            void selectionChanged();

        private slots:
            void handleAddString();
            void handleRemoveString();

        private:
            Ui::StringListWidget *ui;
            StringListWidgetPrivateData* d;
        };
    }
}
#endif // STRING_LIST_WIDGET_H
