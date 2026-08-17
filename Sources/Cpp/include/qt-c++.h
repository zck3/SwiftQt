//=========================================================================
// This file is part of SwiftQt.
// (C) 2023-2024 Zack T Smith.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
// The author may be reached at 3 at zs3 dot me.
//=========================================================================

#ifndef QT_CPP_H
#define QT_CPP_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>

#include <map>
#include <deque>

extern "C" {
#include "common.h"
}

class CallPropagator : QObject 
{
	Q_OBJECT

public:
	CallPropagator ();
	~CallPropagator ();

	//---------------------------------------------------------------------
	// QCalendarWidget
	//---------------------------------------------------------------------
	WidgetID calendarWidgetNew (WidgetID);
	void calendarWidgetClearMaximumDate (WidgetID);
	void calendarWidgetClearMinimumDate (WidgetID);
	long calendarWidgetMonthShown (WidgetID);
	long calendarWidgetYearShown (WidgetID);
	long calendarWidgetHorizontalHeaderFormat (WidgetID widgetID);
	long calendarWidgetVerticalHeaderFormat (WidgetID widgetID);
	void calendarWidgetSetHorizontalHeaderFormat (WidgetID widgetID, long value);
	void calendarWidgetSetVerticalHeaderFormat (WidgetID widgetID, long value);
	long calendarWidgetFirstDayOfWeek (WidgetID);
	void calendarWidgetSetFirstDayOfWeek (WidgetID, long);
	SQDate calendarWidgetSelectedDate (WidgetID);

	//---------------------------------------------------------------------
	// QLayout (abstract class)
	//---------------------------------------------------------------------
	void layoutAddWidget (WidgetID, WidgetID);
	void layoutRemoveWidget (WidgetID, WidgetID);
	long layoutSpacing (ObjectID);
	void layoutSetSpacing (ObjectID, long);

	//---------------------------------------------------------------------
	// QGridLayout
	//---------------------------------------------------------------------
	ObjectID gridLayoutNew (WidgetID);
	void gridLayoutAddWidget (ObjectID,WidgetID,long row,long column,long alignment);
	void gridLayoutAddWidgetWithSpans (ObjectID,WidgetID,long row,long column,long rowspan,long colspan,long alignment);
	SQRect gridLayoutCellRect (ObjectID,long,long);
	long gridLayoutColumnCount (ObjectID);
	long gridLayoutColumnMinimumWidth (ObjectID, long);
	long gridLayoutColumnStretch (ObjectID, long);
	long gridLayoutHorizontalSpacing (ObjectID);
	long gridLayoutRowCount (ObjectID);
	long gridLayoutRowMinimumHeight (ObjectID, long);
	long gridLayoutRowStretch (ObjectID, long);
	void gridLayoutSetColumnMinimumWidth (ObjectID,long, long);
	void gridLayoutSetColumnStretch (ObjectID,long, long);
	void gridLayoutSetHorizontalSpacing (ObjectID,long);
	void gridLayoutSetRowMinimumHeight (ObjectID,long, long);
	void gridLayoutSetRowStretch (ObjectID,long, long);
	void gridLayoutSetVerticalSpacing (ObjectID,long);
	long gridLayoutVerticalSpacing (ObjectID);

	//---------------------------------------------------------------------
	// QBoxLayout
	//---------------------------------------------------------------------
	ObjectID boxLayoutNew (WidgetID, long direction);
	void boxLayoutAddWidget (ObjectID, WidgetID, int stretch, int alignment);
	void boxLayoutAddSpacing (ObjectID, long);
	void boxLayoutAddStretch (ObjectID, long);
	void boxLayoutAddStrut (ObjectID, long);

	//---------------------------------------------------------------------
	// QHBoxLayout
	//---------------------------------------------------------------------
	ObjectID hBoxLayoutNew (WidgetID);

	//---------------------------------------------------------------------
	// QVBoxLayout
	//---------------------------------------------------------------------
	ObjectID vBoxLayoutNew (WidgetID);

	//---------------------------------------------------------------------
	// QPixmap
	//---------------------------------------------------------------------
	ObjectID pixmapWithPathNew (const char*path);
	ObjectID pixmapWithSizeNew (SQCoord,SQCoord);
	bool pixmapLoad (ObjectID objectID, const char *path);
	SQCoord pixmapWidth (ObjectID objectID);
	SQCoord pixmapHeight (ObjectID objectID);
	SQCoord pixmapDepth (ObjectID objectID);

	//---------------------------------------------------------------------
	// QImage
	//---------------------------------------------------------------------
	ObjectID imageNew (const char*path);
	bool imageLoad (ObjectID objectID, const char *path);
	bool imageIsGrayscale (ObjectID objectID);
	SQCoord imageWidth (ObjectID objectID);
	SQCoord imageHeight (ObjectID objectID);
	SQCoord imageDepth (ObjectID objectID);

	//---------------------------------------------------------------------
	// QMainWindow
	//---------------------------------------------------------------------
	WidgetID windowNew (SQCoord x, SQCoord y, SQCoord width, SQCoord height);
	QMainWindow *lookupWindow (WidgetID);
	QMainWindow *mainWindow (void);
        SQCoord windowWidth (WidgetID);
        SQCoord windowHeight (WidgetID);
        void windowClose (WidgetID);
        void windowSetMinimumSize (WidgetID, SQCoord, SQCoord);
        void windowSetMaximumSize (WidgetID, SQCoord, SQCoord);
	const char *windowTitle (WidgetID);
	void windowSetTitle (WidgetID, const char *);
	void windowSetCentralWidget (WidgetID, WidgetID);

	//---------------------------------------------------------------------
	// QStatusBar
	//---------------------------------------------------------------------
	WidgetID statusBarNew (WidgetID parentID, const char *text = nullptr);
	void windowSetStatusBar (WidgetID, WidgetID);
	void windowSetMenuBar (WidgetID, WidgetID);
	void statusBarShowMessage (WidgetID statusBarID, const char *text = nullptr, long duration = 0);

	//---------------------------------------------------------------------
	// QGroupBox
	//---------------------------------------------------------------------
	WidgetID groupBoxNew (WidgetID, const char* title);
	long groupBoxAlignment (WidgetID groupBoxID);
	void groupBoxSetAlignment (WidgetID groupBoxID, long);
	const char* groupBoxTitle (WidgetID);
	void groupBoxSetTitle (WidgetID, const char*);

	//---------------------------------------------------------------------
	// QLabel
	//---------------------------------------------------------------------
	WidgetID labelNew (WidgetID parent, const char *text = nullptr);
	void labelClear (WidgetID);
	const char* labelText (WidgetID);
	void labelSetText (WidgetID, const char*);
	void labelSetPixmap (WidgetID, ObjectID); 
	void labelSetImage (WidgetID, ObjectID); 
	bool labelWordWrap (WidgetID labelID);
	void labelSetWordWrap (WidgetID labelID, bool value);
	long labelAlignment (WidgetID labelID);
	void labelSetAlignment (WidgetID labelID, long value);
	long labelIndent (WidgetID labelID);
	void labelSetIndent (WidgetID labelID, long value);
	long labelMargin (WidgetID labelID);
	void labelSetMargin (WidgetID labelID, long value);

	//---------------------------------------------------------------------
	// QMenuBar
	//---------------------------------------------------------------------
	WidgetID menuBarNew (void);
	void menuBarAddMenu (WidgetID parent, WidgetID menu);

	//---------------------------------------------------------------------
	// QMenu
	//---------------------------------------------------------------------
	WidgetID menuNew (const char *title = nullptr);
	const char *menuTitle (WidgetID);
	void menuSetTitle (WidgetID, const char *);
	void menuAddAction (WidgetID, ObjectID);
	void menuAddSeparator (WidgetID);

	//---------------------------------------------------------------------
	// QAction
	//---------------------------------------------------------------------
	ObjectID actionNew (const char*title);
	void actionSetShortcut (ObjectID actionID, SQKeySequence keySequenceID);

	//---------------------------------------------------------------------
	// QAbstractButton
	//---------------------------------------------------------------------
	const char *abstractButtonText (WidgetID);
	void abstractButtonSetText (WidgetID, const char *);
	bool abstractButtonIsChecked (WidgetID);
	void abstractButtonSetChecked (WidgetID, bool);

	//---------------------------------------------------------------------
	// QRadioButton
	//---------------------------------------------------------------------
	WidgetID radioButtonNew (WidgetID parentID, const char *text = nullptr);

	//---------------------------------------------------------------------
	// QCheckBox
	//---------------------------------------------------------------------
	WidgetID checkBoxNew (WidgetID parentID, const char *text = nullptr);
	bool checkBoxIsTristate (WidgetID);
	void checkBoxSetTristate (WidgetID, bool);
	long checkBoxCheckState (WidgetID);
	void checkBoxSetCheckState (WidgetID, long);

	//---------------------------------------------------------------------
	// QPushButton
	//---------------------------------------------------------------------
	WidgetID pushButtonNew (WidgetID parentID, const char *text = nullptr);
	bool pushButtonIsFlat (WidgetID);
	void pushButtonSetFlat (WidgetID, bool);
	bool pushButtonIsDefault (WidgetID);
	void pushButtonSetDefault (WidgetID, bool);

	//---------------------------------------------------------------------
	// QTableWidgetItem
	//---------------------------------------------------------------------
	ObjectID tableWidgetItemNew (const char*);
	const char *tableWidgetItemText (ObjectID);
	void tableWidgetItemSetText (ObjectID,const char*);
	void tableWidgetItemSetForeground (ObjectID, SQColor);
	void tableWidgetItemSetBackground (ObjectID, SQColor);

	//---------------------------------------------------------------------
	// QTableWidget
	//---------------------------------------------------------------------
	WidgetID tableWidgetNew (WidgetID parent);
	long tableWidgetColumnCount (WidgetID);
	void tableWidgetSetColumnCount (WidgetID,long);
	long tableWidgetRowCount (WidgetID);
	void tableWidgetSetRowCount (WidgetID,long);
	long tableWidgetCurrentColumn (WidgetID);
	long tableWidgetCurrentRow (WidgetID);
	void tableWidgetSetCurrentCell (WidgetID,long,long);
	ObjectID tableWidgetItem (WidgetID,long,long);
	void tableWidgetSetItem (WidgetID,long,long,ObjectID);
	ObjectID tableWidgetCurrentItem (WidgetID);
	WidgetID tableWidgetCellWidget (WidgetID,long,long);
	void tableWidgetSetCellWidget (WidgetID,long,long,WidgetID);
	void tableWidgetInsertColumn (WidgetID tableID, long column);
	void tableWidgetInsertRow (WidgetID tableID, long row);
	void tableWidgetSetVerticalHeaderLabel (WidgetID tableID, const char *, bool is_last);
	void tableWidgetSetHorizontalHeaderLabel (WidgetID tableID, const char *, bool is_last);

	//---------------------------------------------------------------------
	// QTextEdit
	//---------------------------------------------------------------------
	WidgetID textEditNew (WidgetID parent);
	const char *textEditToPlainText (WidgetID);
	const char *textEditToHTML (WidgetID);
	void textEditSetReadOnly (WidgetID, bool);
	void textEditSetText (WidgetID, const char *);
	//void textEditSetHTML (WidgetID, const char *);
	void textEditSetAcceptRichText (WidgetID, bool);

	//---------------------------------------------------------------------
	// QWebEngineView
	//---------------------------------------------------------------------
	WidgetID webEngineViewNew (WidgetID parentID);
	void webEngineViewSetHTML (WidgetID, const char *);

	//---------------------------------------------------------------------
	// QLineEdit
	//---------------------------------------------------------------------
	WidgetID lineEditNew (WidgetID parentID);
	const char *lineEditText (WidgetID);
	void lineEditSetText (WidgetID, const char *);

	//---------------------------------------------------------------------
	// QWidget
	//---------------------------------------------------------------------
	WidgetID widgetNew (WidgetID);
	void setFrame (WidgetID, SQRect);
	SQRect frame (WidgetID);
	void setMinimumSize (WidgetID, SQSize);
	SQSize minimumSize (WidgetID);
	SQCoord height (WidgetID);
	SQCoord width (WidgetID);
	void move (WidgetID, SQCoord, SQCoord);
	void resize (WidgetID, SQCoord, SQCoord);
	void setHidden (WidgetID, bool);
	bool isHidden (WidgetID);
	void setStyleSheet (WidgetID, const char*);
	const char *styleSheet (WidgetID);
	void raise (WidgetID);
	void lower (WidgetID);
	WidgetID layout (WidgetID);
	void setLayout (WidgetID, ObjectID);
	void setMaximumHeight (WidgetID, long maxh);
	void setMaximumWidth (WidgetID, long maxw);
	void setMinimumHeight (WidgetID, long minh);
	void setMinimumWidth (WidgetID, long minw);
	void setParent (WidgetID, WidgetID);
	WidgetID parentWidget (WidgetID);

	//---------------------------------------------------------------------
	// QSlider
	//---------------------------------------------------------------------
	WidgetID sliderNew (WidgetID parentID);
	long sliderTickPosition (WidgetID);
	long sliderTickInterval (WidgetID);
	void sliderSetTickPosition (WidgetID, long);
	void sliderSetTickInterval (WidgetID, long);

	//---------------------------------------------------------------------
	// QAbstractSlider
	//---------------------------------------------------------------------
	void abstractSliderSetMaximum (WidgetID, long maximum);
	void abstractSliderSetMinimum (WidgetID, long minimum);
	void abstractSliderSetPageStep (WidgetID, long pageStep);
	void abstractSliderSetValue (WidgetID, long value);
	void abstractSliderSetSliderDown (WidgetID, bool value);
	bool abstractSliderIsSliderDown (WidgetID);
	long abstractSliderMaximum (WidgetID);
	long abstractSliderMinimum (WidgetID);
	long abstractSliderPageStep (WidgetID);
	long abstractSliderValue (WidgetID);
	long abstractSliderOrientation (WidgetID);
	void abstractSliderSetOrientation (WidgetID,long);

	//---------------------------------------------------------------------
	// QLCDNumber
	//---------------------------------------------------------------------
	WidgetID lcdNumberNew (WidgetID, long);
	void lcdNumberSetHexMode (WidgetID);
	void lcdNumberSetBinMode (WidgetID);
	void lcdNumberSetDecMode (WidgetID);
	void lcdNumberSetOctMode (WidgetID);
	double lcdNumberValue (WidgetID);
	long lcdNumberIntValue (WidgetID);
	long lcdNumberDigitCount (WidgetID);
	void lcdNumberDisplayInt (WidgetID, long);
	void lcdNumberDisplayDouble (WidgetID, double);
	bool lcdNumberSmallDecimalPoint (WidgetID);
	void lcdNumberSetSmallDecimalPoint (WidgetID,bool);

	//---------------------------------------------------------------------
	// QApplication
	//---------------------------------------------------------------------
	ObjectID applicationNew (long, char *[]);

	//---------------------------------------------------------------------
	// QScreen
	//---------------------------------------------------------------------
	long primaryScreenLogicalDotsPerInch ();
	long primaryScreenWidth ();
	long primaryScreenHeight ();

	//---------------------------------------------------------------------
	// Included for convenience
	//---------------------------------------------------------------------
	void conveniencePopup (const char* title, const char* message);
	bool yesnoQuestion (const char* title, const char* message);

	// Used by the event filter.
	WidgetID lookupWidget (QWidget*);

private:
	//---------------------------------------------------------------------
	// Book-keeping
	//---------------------------------------------------------------------
	int widgetObjectCounter = 100; // A zero widget/object ID means nullptr.
	std::map<WidgetID, QWidget*> widgets;
	std::map<ObjectID, QObject*> objects;
	void widgetDestroyed (WidgetID widgetID) {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QWidgetDeallocated;
		event.recipient = widgetID;
		swiftEventHandler (event);
	}
	void objectDestroyed (ObjectID objectID) {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QObjectDeallocated;
		event.recipient = objectID;
		swiftEventHandler (event);
	}
	WidgetID lookupOrAddWidget (QWidget*);
	ObjectID lookupOrAddObject (QObject*);
	ObjectID lookupObject (QObject*);

	std::deque<const char*> tableHorizontalHeaderLabels;
	std::deque<const char*> tableVerticalHeaderLabels;

public slots:
};

class EventFilter : public QObject
{
	Q_OBJECT

public:
	using QObject::QObject; // Inherit QObject's constructors.

protected:
	bool eventFilter (QObject *object, QEvent *event) override;
};

#endif
