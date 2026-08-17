//=========================================================================
// This file is part of SwiftQt.
// (C) 2023 Zack T Smith.
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
//
//=============================================================================
// The bridging header file is required to be C code only. Therefore any calls
// to Qt, have to go through C middleman functions, which I call the Conduit
// in the C code and CallPropagator in C++.
// Messages from Qt to Swift code go through the bridge's swiftEventHandler.
//=============================================================================

#include "qt-c++.h"

extern "C" {

#include "common.h"

//-----------------------------------------------------------------------------
// QPixmap
//-----------------------------------------------------------------------------
ObjectID Conduit_pixmapWithPathNew(const char*path);
ObjectID Conduit_pixmapWithSizeNew(Coord,Coord);
bool Conduit_pixmapLoad (ObjectID objectID, const char *path);
bool Conduit_pixmapIsGrayscale (ObjectID objectID);
Coord Conduit_pixmapWidth (ObjectID objectID);
Coord Conduit_pixmapHeight (ObjectID objectID);
Coord Conduit_pixmapDepth (ObjectID objectID);

//-----------------------------------------------------------------------------
// QImage
//-----------------------------------------------------------------------------
ObjectID Conduit_imageNew(const char*path);
bool Conduit_imageLoad (ObjectID objectID, const char *path);
bool Conduit_imageIsGrayscale (ObjectID objectID);
Coord Conduit_imageWidth (ObjectID objectID);
Coord Conduit_imageHeight (ObjectID objectID);
Coord Conduit_imageDepth (ObjectID objectID);

//-----------------------------------------------------------------------------
// QApplication
//-----------------------------------------------------------------------------
ObjectID Conduit_applicationNew (long, char *[]);
void Conduit_applicationExec(void);
void Conduit_applicationQuit(void);
void Conduit_applicationBeep(void);
long Conduit_applicationTotalMainWindows (void);

//-----------------------------------------------------------------------------
// QLCDNumber
//-----------------------------------------------------------------------------
WidgetID Conduit_lcdNumberNew (WidgetID, long);
void Conduit_lcdNumberSetHexMode (WidgetID);
void Conduit_lcdNumberSetBinMode (WidgetID);
void Conduit_lcdNumberSetDecMode (WidgetID);
void Conduit_lcdNumberSetOctMode (WidgetID);
double Conduit_lcdNumberValue (WidgetID);
long Conduit_lcdNumberIntValue (WidgetID);
long Conduit_lcdNumberDigitCount (WidgetID);
void Conduit_lcdNumberDisplayInt (WidgetID, long);
void Conduit_lcdNumberDisplayDouble (WidgetID, double);
bool Conduit_lcdNumberSmallDecimalPoint (WidgetID);
void Conduit_lcdNumberSetSmallDecimalPoint (WidgetID,bool);

//-----------------------------------------------------------------------------
// QSlider
//-----------------------------------------------------------------------------
WidgetID Conduit_sliderNew (WidgetID parentID);
long Conduit_sliderTickPosition (WidgetID);
long Conduit_sliderTickInterval (WidgetID);
void Conduit_sliderSetTickPosition (WidgetID, long);
void Conduit_sliderSetTickInterval (WidgetID, long);

//-----------------------------------------------------------------------------
// QAbstractSlider
//-----------------------------------------------------------------------------
void Conduit_abstractSliderSetMaximum (WidgetID, long maximum);
void Conduit_abstractSliderSetMinimum (WidgetID, long minimum);
void Conduit_abstractSliderSetPageStep (WidgetID, long pageStep);
void Conduit_abstractSliderSetValue (WidgetID, long value);
void Conduit_abstractSliderSetSliderDown (WidgetID, bool value);
bool Conduit_abstractSliderIsSliderDown(WidgetID);
long Conduit_abstractSliderMaximum (WidgetID);
long Conduit_abstractSliderMinimum (WidgetID);
long Conduit_abstractSliderPageStep (WidgetID);
long Conduit_abstractSliderValue (WidgetID);
long Conduit_abstractSliderOrientation (WidgetID);
void Conduit_abstractSliderSetOrientation (WidgetID,long);

//-----------------------------------------------------------------------------
// SwiftQt convenience functions
//-----------------------------------------------------------------------------
const char *Conduit_swiftQtRelease(void);
void Conduit_swiftQtConveniencePopup(const char*, const char*);
bool Conduit_swiftQtConvenienceQuestion (const char *title, const char *question);
bool Conduit_swiftQtIsDarkMode(void);

//-----------------------------------------------------------------------------
// QMainWindow
//-----------------------------------------------------------------------------
WidgetID Conduit_windowNew(Coord,Coord,Coord,Coord);
void Conduit_showWindow (WidgetID);
Coord Conduit_windowWidth (WidgetID);
Coord Conduit_windowHeight (WidgetID);
void Conduit_windowSetMinimumSize (WidgetID, Coord, Coord);
void Conduit_windowSetMaximumSize (WidgetID, Coord, Coord);
const char *Conduit_windowTitle (WidgetID);
void Conduit_windowSetTitle (WidgetID, const char *);
void Conduit_windowSetStatusBar (WidgetID, WidgetID);
void Conduit_windowSetMenuBar (WidgetID, WidgetID);
void Conduit_windowSetCentralWidget (WidgetID, WidgetID);

//-----------------------------------------------------------------------------
// QMenuBar
//-----------------------------------------------------------------------------
WidgetID Conduit_menuBarNew (void);
void Conduit_menuBarAddMenu (WidgetID, WidgetID);

//-----------------------------------------------------------------------------
// QMenu
//-----------------------------------------------------------------------------
WidgetID Conduit_menuNew (const char*title);
const char *Conduit_menuTitle (WidgetID);
void Conduit_menuSetTitle (WidgetID, const char *);
void Conduit_menuAddAction (WidgetID, ObjectID);
void Conduit_menuAddSeparator (WidgetID);

//-----------------------------------------------------------------------------
// QAction
//-----------------------------------------------------------------------------
ObjectID Conduit_actionNew (const char* title);
void Conduit_actionSetShortcut (ObjectID, SQKeySequence);

//-----------------------------------------------------------------------------
// QStatusBar
//-----------------------------------------------------------------------------
WidgetID Conduit_statusBarNew (WidgetID, const char*);
void Conduit_statusBarShowMessage (WidgetID, const char*, long);

//-----------------------------------------------------------------------------
// QWidget 
//-----------------------------------------------------------------------------
WidgetID Conduit_widgetNew (WidgetID);
void Conduit_move (WidgetID, Coord, Coord);
void Conduit_resize (WidgetID, Coord, Coord);
void Conduit_setMinimumSize (WidgetID, Size);
Size Conduit_minimumSize (WidgetID);
void Conduit_setFrame (WidgetID, Rect);
Rect Conduit_frame (WidgetID);
Coord Conduit_height (WidgetID);
Coord Conduit_width (WidgetID);
void Conduit_setHidden (WidgetID, bool);
bool Conduit_isHidden (WidgetID);
void Conduit_setStyleSheet (WidgetID, const char*);
const char *Conduit_styleSheet (WidgetID);
void Conduit_raise (WidgetID);
void Conduit_lower (WidgetID);
WidgetID Conduit_layout (WidgetID);
void Conduit_setLayout (WidgetID, ObjectID);
void Conduit_setMaximumHeight(WidgetID, long maxh);
void Conduit_setMaximumWidth(WidgetID, long maxw);
void Conduit_setMinimumHeight(WidgetID, long minh);
void Conduit_setMinimumWidth(WidgetID, long minw);
void Conduit_setParent(WidgetID, WidgetID);
WidgetID Conduit_parentWidget(WidgetID);

//-----------------------------------------------------------------------------
// QGroupBox
//-----------------------------------------------------------------------------
WidgetID Conduit_groupBoxNew (WidgetID, const char*);
long Conduit_groupBoxAlignment (WidgetID groupBoxID);
void Conduit_groupBoxSetAlignment (WidgetID groupBoxID, long);
const char* Conduit_groupBoxTitle (WidgetID);
void Conduit_groupBoxSetTitle (WidgetID, const char*);

//-----------------------------------------------------------------------------
// QLineEdit
//-----------------------------------------------------------------------------
WidgetID Conduit_lineEditNew (WidgetID);
const char *Conduit_lineEditText (WidgetID);
void Conduit_lineEditSetText (WidgetID, const char *);

//-----------------------------------------------------------------------------
// QCalendarWidget
//-----------------------------------------------------------------------------
WidgetID Conduit_calendarWidgetNew (WidgetID);
void Conduit_calendarWidgetClearMaximumDate(WidgetID);
void Conduit_calendarWidgetClearMinimumDate(WidgetID);
long Conduit_calendarWidgetMonthShown(WidgetID);
long Conduit_calendarWidgetYearShown(WidgetID);
long Conduit_calendarWidgetHorizontalHeaderFormat(WidgetID);
long Conduit_calendarWidgetVerticalHeaderFormat(WidgetID);
void Conduit_calendarWidgetSetHorizontalHeaderFormat(WidgetID,long);
void Conduit_calendarWidgetSetVerticalHeaderFormat(WidgetID,long);
long Conduit_calendarWidgetFirstDayOfWeek(WidgetID);
void Conduit_calendarWidgetSetFirstDayOfWeek(WidgetID,long);
Date Conduit_calendarWidgetSelectedDate(WidgetID);

//-----------------------------------------------------------------------------
// QLabel
//-----------------------------------------------------------------------------
WidgetID Conduit_labelNew (WidgetID, const char*);
void Conduit_labelClear (WidgetID);
const char* Conduit_labelText (WidgetID);
void Conduit_labelSetText (WidgetID, const char*);
void Conduit_labelSetPixmap (WidgetID, ObjectID);
void Conduit_labelSetImage (WidgetID, ObjectID);
bool Conduit_labelWordWrap (WidgetID labelID);
void Conduit_labelSetWordWrap (WidgetID labelID, bool);
long Conduit_labelAlignment (WidgetID labelID);
void Conduit_labelSetAlignment (WidgetID labelID, long);
long Conduit_labelIndent (WidgetID labelID);
void Conduit_labelSetIndent (WidgetID labelID, long);
long Conduit_labelMargin (WidgetID labelID);
void Conduit_labelSetMargin (WidgetID labelID, long);

//-----------------------------------------------------------------------------
// QLayout (abstract class)
//-----------------------------------------------------------------------------
void Conduit_layoutAddWidget (WidgetID,WidgetID);
void Conduit_layoutRemoveWidget (WidgetID,WidgetID);
long Conduit_layoutSpacing (ObjectID);
void Conduit_layoutSetSpacing (ObjectID,long);

//-----------------------------------------------------------------------------
// QGridLayout
//-----------------------------------------------------------------------------
ObjectID Conduit_gridLayoutNew (WidgetID);
void Conduit_gridLayoutAddWidget(ObjectID,WidgetID,long row,long col,long align);
void Conduit_gridLayoutAddWidgetWithSpans(ObjectID,WidgetID,long row,long col,long rowspan,long colspan,long align);
Rect Conduit_gridLayoutCellRect(ObjectID,long,long);
long Conduit_gridLayoutColumnCount(ObjectID);
long Conduit_gridLayoutColumnMinimumWidth(ObjectID,long);
long Conduit_gridLayoutColumnStretch(ObjectID,long);
long Conduit_gridLayoutHorizontalSpacing(ObjectID);
long Conduit_gridLayoutRowCount(ObjectID);
long Conduit_gridLayoutRowMinimumHeight(ObjectID,long);
long Conduit_gridLayoutRowStretch(ObjectID,long);
void Conduit_gridLayoutSetColumnMinimumWidth(ObjectID,long,long);
void Conduit_gridLayoutSetColumnStretch(ObjectID,long,long);
void Conduit_gridLayoutSetHorizontalSpacing(ObjectID,long);
void Conduit_gridLayoutSetRowMinimumHeight(ObjectID,long,long);
void Conduit_gridLayoutSetRowStretch(ObjectID,long,long);
void Conduit_gridLayoutSetVerticalSpacing(ObjectID,long);
long Conduit_gridLayoutVerticalSpacing(ObjectID);
		
//-----------------------------------------------------------------------------
// QBoxLayout
//-----------------------------------------------------------------------------
ObjectID Conduit_boxLayoutNew (WidgetID,long);
void Conduit_boxLayoutAddWidget (ObjectID,WidgetID,long,long);
void Conduit_boxLayoutAddSpacing (ObjectID, long);
void Conduit_boxLayoutAddStretch (ObjectID, long);
void Conduit_boxLayoutAddStrut (ObjectID, long);

//-----------------------------------------------------------------------------
// QHBoxLayout
//-----------------------------------------------------------------------------
ObjectID Conduit_hBoxLayoutNew (WidgetID);

//-----------------------------------------------------------------------------
// QVBoxLayout
//-----------------------------------------------------------------------------
ObjectID Conduit_vBoxLayoutNew (WidgetID);

//-----------------------------------------------------------------------------
// QAbstractButton
//-----------------------------------------------------------------------------
const char *Conduit_abstractButtonText (WidgetID);
void Conduit_abstractButtonSetText (WidgetID, const char *);
bool Conduit_abstractButtonIsChecked (WidgetID);
void Conduit_abstractButtonSetChecked (WidgetID, bool);

//-----------------------------------------------------------------------------
// QCheckBox
//-----------------------------------------------------------------------------
WidgetID Conduit_checkBoxNew (WidgetID, const char *);
bool Conduit_checkBoxIsTristate (WidgetID);
void Conduit_checkBoxSetTristate (WidgetID, bool);
long Conduit_checkBoxCheckState (WidgetID);
void Conduit_checkBoxSetCheckState (WidgetID, long);

//-----------------------------------------------------------------------------
// QRadioButton
//-----------------------------------------------------------------------------
WidgetID Conduit_radioButtonNew (WidgetID, const char *);

//-----------------------------------------------------------------------------
// QPushButton
//-----------------------------------------------------------------------------
WidgetID Conduit_pushButtonNew (WidgetID, const char *);
//const char *Conduit_pushButtonText (WidgetID);
//void Conduit_pushButtonSetText (WidgetID, const char *);
bool Conduit_pushButtonIsFlat (WidgetID);
void Conduit_pushButtonSetFlat (WidgetID, bool);
bool Conduit_pushButtonIsDefault (WidgetID);
void Conduit_pushButtonSetDefault (WidgetID, bool);

//-----------------------------------------------------------------------------
// Text editor
//-----------------------------------------------------------------------------
WidgetID Conduit_textEditNew (WidgetID);
const char *Conduit_textEditToPlainText (WidgetID);
void Conduit_textEditSetText (WidgetID, const char *);
//void Conduit_textEditSetHTML (WidgetID, const char *);
void Conduit_textEditSetReadOnly (WidgetID, bool);
const char *Conduit_textEditToHTML (WidgetID);
void Conduit_textEditSetAcceptRichText (WidgetID, bool);

//-----------------------------------------------------------------------------
// Web engine view
//-----------------------------------------------------------------------------
WidgetID Conduit_webEngineViewNew (WidgetID);
void Conduit_webEngineViewSetHTML (WidgetID, const char *);

//-----------------------------------------------------------------------------
// QTableWidgetItem
//-----------------------------------------------------------------------------
ObjectID Conduit_tableWidgetItemNew (const char*);
const char* Conduit_tableWidgetItemText (ObjectID);
void Conduit_tableWidgetItemSetText (ObjectID,const char*);

//-----------------------------------------------------------------------------
// QTableWidget
//-----------------------------------------------------------------------------
WidgetID Conduit_tableWidgetNew (WidgetID);
long Conduit_tableWidgetColumnCount (WidgetID);
void Conduit_tableWidgetSetColumnCount (WidgetID, long);
long Conduit_tableWidgetRowCount (WidgetID);
void Conduit_tableWidgetSetRowCount (WidgetID, long);
long Conduit_tableWidgetCurrentColumn (WidgetID);
long Conduit_tableWidgetCurrentRow (WidgetID);
void Conduit_tableWidgetSetCurrentCell (WidgetID, long,long);
ObjectID Conduit_tableWidgetItem (WidgetID,long,long);
void Conduit_tableWidgetSetItem (WidgetID,long,long,ObjectID);

ObjectID Conduit_tableWidgetCurrentItem (WidgetID);

WidgetID Conduit_tableWidgetCellWidget (WidgetID,long,long);
void Conduit_tableWidgetSetCellWidget (WidgetID,long,long,WidgetID);

void Conduit_tableWidgetInsertColumn (WidgetID tableID, long column);
void Conduit_tableWidgetInsertRow (WidgetID tableID, long row);
void Conduit_tableWidgetSetVerticalHeaderLabel (WidgetID tableID, const char *, bool);
void Conduit_tableWidgetSetHorizontalHeaderLabel (WidgetID tableID, const char *, bool);

}
