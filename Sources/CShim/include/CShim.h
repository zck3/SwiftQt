//=========================================================================
// This file is part of SwiftQt.
// (C) 2023-2024, 2026 Zack T Smith.
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
// BELOW ARE DECLARATIONS THAT MAP C FUNCTIONS TO SWIFT FUNCTIONS. 
//=========================================================================

#ifndef SWIFTQT_CSHIM_H
#define SWIFTQT_CSHIM_H

#include "common.h"

typedef struct 
{
	int fubar;
} Conduit;

//-----------------------------------------------------------------------------
// QPixmap
//-----------------------------------------------------------------------------
ObjectID Conduit_pixmapWithPathNew(const char*path)	__attribute__((swift_name("Conduit.pixmapWithPathNew(_:)")));
ObjectID Conduit_pixmapWithSizeNew(SQCoord, SQCoord)	__attribute__((swift_name("Conduit.pixmapWithSizeNew(_:_:)")));
bool Conduit_pixmapLoad (ObjectID objectID, const char *path)	__attribute__((swift_name("Conduit.pixmapLoad(_:_:)")));	
bool Conduit_pixmapIsGrayscale (ObjectID objectID)	__attribute__((swift_name("Conduit.pixmapIsGrayscale(_:)")));	
SQCoord Conduit_pixmapWidth (ObjectID objectID)	__attribute__((swift_name("Conduit.pixmapWidth(_:)")));	
SQCoord Conduit_pixmapHeight (ObjectID objectID)	__attribute__((swift_name("Conduit.pixmapHeight(_:)")));	
SQCoord Conduit_pixmapDepth (ObjectID objectID)	__attribute__((swift_name("Conduit.pixmapDepth(_:)")));	

//-----------------------------------------------------------------------------
// QImage
//-----------------------------------------------------------------------------
ObjectID Conduit_imageNew(const char*path)	__attribute__((swift_name("Conduit.imageNew(_:)")));
bool Conduit_imageLoad (ObjectID objectID, const char *path)	__attribute__((swift_name("Conduit.imageLoad(_:_:)")));	
bool Conduit_imageIsGrayscale (ObjectID objectID)	__attribute__((swift_name("Conduit.imageIsGrayscale(_:)")));	
SQCoord Conduit_imageWidth (ObjectID objectID)	__attribute__((swift_name("Conduit.imageWidth(_:)")));	
SQCoord Conduit_imageHeight (ObjectID objectID)	__attribute__((swift_name("Conduit.imageHeight(_:)")));	
SQCoord Conduit_imageDepth (ObjectID objectID)	__attribute__((swift_name("Conduit.imageDepth(_:)")));	

//-----------------------------------------------------------------------------
// QApplication
//-----------------------------------------------------------------------------
ObjectID Conduit_applicationNew(long,char*[])   __attribute__((swift_name("Conduit.applicationNew(_:_:)")));
void Conduit_applicationExec(void)	__attribute__((swift_name("Conduit.applicationExec()")));
void Conduit_applicationQuit(void)	__attribute__((swift_name("Conduit.applicationQuit()")));
void Conduit_applicationBeep(void)	__attribute__((swift_name("Conduit.applicationBeep()")));
long Conduit_applicationTotalMainWindows (void) 	__attribute__((swift_name("Conduit.applicationTotalMainWindows()")));

//-----------------------------------------------------------------------------
// QLCDNumber
//-----------------------------------------------------------------------------
WidgetID Conduit_lcdNumberNew (WidgetID, long)	__attribute__((swift_name("Conduit.lcdNumberNew(_:_:)")));
void Conduit_lcdNumberSetHexMode (WidgetID)	__attribute__((swift_name("Conduit.lcdNumberSetHexMode(_:)")));
void Conduit_lcdNumberSetBinMode (WidgetID)	__attribute__((swift_name("Conduit.lcdNumberSetBinMode(_:)")));
void Conduit_lcdNumberSetDecMode (WidgetID)	__attribute__((swift_name("Conduit.lcdNumberSetDecMode(_:)")));
void Conduit_lcdNumberSetOctMode (WidgetID)	__attribute__((swift_name("Conduit.lcdNumberSetOctMode(_:)")));
double Conduit_lcdNumberValue (WidgetID)	__attribute__((swift_name("Conduit.lcdNumberValue(_:)")));
long Conduit_lcdNumberIntValue (WidgetID)	__attribute__((swift_name("Conduit.lcdNumberIntValue(_:)")));
long Conduit_lcdNumberDigitCount (WidgetID)	__attribute__((swift_name("Conduit.lcdNumberDigitCount(_:)")));
void Conduit_lcdNumberDisplayInt (WidgetID, long)	__attribute__((swift_name("Conduit.lcdNumberDisplayInt(_:_:)")));
void Conduit_lcdNumberDisplayDouble (WidgetID, double)	__attribute__((swift_name("Conduit.lcdNumberDisplayDouble(_:_:)")));
bool Conduit_lcdNumberSmallDecimalPoint (WidgetID)	__attribute__((swift_name("Conduit.lcdNumberSmallDecimalPoint(_:)")));
void Conduit_lcdNumberSetSmallDecimalPoint (WidgetID,bool)	__attribute__((swift_name("Conduit.lcdNumberSetSmallDecimalPoint(_:_:)")));

//-----------------------------------------------------------------------------
// QSlider
//-----------------------------------------------------------------------------
WidgetID Conduit_sliderNew (WidgetID parentID)	__attribute__((swift_name("Conduit.sliderNew(_:)")));
long Conduit_sliderTickPosition (WidgetID)	__attribute__((swift_name("Conduit.sliderTickPosition(_:)")));
long Conduit_sliderTickInterval (WidgetID)	__attribute__((swift_name("Conduit.sliderTickInterval(_:)")));
void Conduit_sliderSetTickPosition (WidgetID, long)	__attribute__((swift_name("Conduit.sliderSetTickPosition(_:_:)")));
void Conduit_sliderSetTickInterval (WidgetID, long)	__attribute__((swift_name("Conduit.sliderSetTickInterval(_:_:)")));

//-----------------------------------------------------------------------------
// QAbstractSlider
//-----------------------------------------------------------------------------
void Conduit_abstractSliderSetMaximum (WidgetID, long maximum)	__attribute__((swift_name("Conduit.abstractSliderSetMaximum(_:_:)")));
void Conduit_abstractSliderSetMinimum (WidgetID, long minimum)	__attribute__((swift_name("Conduit.abstractSliderSetMinimum(_:_:)")));
void Conduit_abstractSliderSetPageStep (WidgetID, long pageStep)	__attribute__((swift_name("Conduit.abstractSliderSetPageStep(_:_:)")));
void Conduit_abstractSliderSetValue (WidgetID, long value)	__attribute__((swift_name("Conduit.abstractSliderSetValue(_:_:)")));
void Conduit_abstractSliderSetSliderDown (WidgetID, bool value)	__attribute__((swift_name("Conduit.abstractSliderSetSliderDown(_:_:)")));
bool Conduit_abstractSliderIsSliderDown(WidgetID)	__attribute__((swift_name("Conduit.abstractSliderIsSliderDown(_:)")));
long Conduit_abstractSliderMaximum (WidgetID)	__attribute__((swift_name("Conduit.abstractSliderMaximum(_:)")));
long Conduit_abstractSliderMinimum (WidgetID)	__attribute__((swift_name("Conduit.abstractSliderMinimum(_:)")));
long Conduit_abstractSliderPageStep (WidgetID)	__attribute__((swift_name("Conduit.abstractSliderPageStep(_:)")));
long Conduit_abstractSliderValue (WidgetID)	__attribute__((swift_name("Conduit.abstractSliderValue(_:)")));
long Conduit_abstractSliderOrientation (WidgetID)	__attribute__((swift_name("Conduit.abstractSliderOrientation(_:)")));
void Conduit_abstractSliderSetOrientation (WidgetID,long)	__attribute__((swift_name("Conduit.abstractSliderSetOrientation(_:_:)")));

//-----------------------------------------------------------------------------
// SwiftQt convenience functions
//-----------------------------------------------------------------------------
void Conduit_swiftQtConveniencePopup(const char*, const char*)	__attribute__((swift_name("Conduit.swiftQtConveniencePopup(_:_:)")));
bool Conduit_swiftQtConvenienceQuestion (const char *title, const char *question)	__attribute__((swift_name("Conduit.swiftQtConvenienceQuestion(_:_:)")));
bool Conduit_swiftQtIsDarkMode(void)	__attribute__((swift_name("Conduit.swiftQtIsDarkMode()")));

//-----------------------------------------------------------------------------
// QScreen
//-----------------------------------------------------------------------------
long Conduit_primaryScreenLogicalDotsPerInch(void)	__attribute__((swift_name("Conduit.primaryScreenLogicalDotsPerInch()")));
long Conduit_primaryScreenWidth (void)	__attribute__((swift_name("Conduit.primaryScreenWidth()")));
long Conduit_primaryScreenHeight (void)	__attribute__((swift_name("Conduit.primaryScreenHeight()")));

//-----------------------------------------------------------------------------
// QMainWindow
//-----------------------------------------------------------------------------
WidgetID Conduit_windowNew(SQCoord, SQCoord, SQCoord, SQCoord) __attribute__((swift_name("Conduit.windowNew(_:_:_:_:)")));
void Conduit_windowShow (WidgetID)	__attribute__((swift_name("Conduit.windowShow(_:)")));
void Conduit_windowHide (WidgetID)	__attribute__((swift_name("Conduit.windowHide(_:)")));
void Conduit_windowClose (WidgetID)	__attribute__((swift_name("Conduit.windowClose(_:)")));
SQCoord Conduit_windowWidth (WidgetID) 	__attribute__((swift_name("Conduit.windowWidth(_:)")));
SQCoord Conduit_windowHeight (WidgetID) 	__attribute__((swift_name("Conduit.windowHeight(_:)")));
void Conduit_windowSetMinimumSize (WidgetID, SQCoord, SQCoord) 	__attribute__((swift_name("Conduit.windowSetMinimumSize(_:_:_:)")));
void Conduit_windowSetMaximumSize (WidgetID, SQCoord, SQCoord) 	__attribute__((swift_name("Conduit.windowSetMaximumSize(_:_:_:)")));
const char *Conduit_windowTitle (WidgetID) 	__attribute__((swift_name("Conduit.windowTitle(_:)")));
void Conduit_windowSetTitle (WidgetID, const char *) 	__attribute__((swift_name("Conduit.windowSetTitle(_:_:)")));
void Conduit_windowSetStatusBar (WidgetID, WidgetID)	__attribute__((swift_name("Conduit.windowSetStatusBar(_:_:)")));
void Conduit_windowSetMenuBar (WidgetID, WidgetID)	__attribute__((swift_name("Conduit.windowSetMenuBar(_:_:)")));
void Conduit_windowSetCentralWidget (WidgetID, WidgetID)	__attribute__((swift_name("Conduit.windowSetCentralWidget(_:_:)")));

//-----------------------------------------------------------------------------
// QMenuBar
//-----------------------------------------------------------------------------
WidgetID Conduit_menuBarNew (void)	__attribute__((swift_name("Conduit.menuBarNew()")));
void Conduit_menuBarAddMenu (WidgetID, WidgetID) 	__attribute__((swift_name("Conduit.menuBarAddMenu(_:_:)")));

//-----------------------------------------------------------------------------
// QMenu
//-----------------------------------------------------------------------------
WidgetID Conduit_menuNew (const char*title) 	__attribute__((swift_name("Conduit.menuNew(_:)")));
const char *Conduit_menuTitle (WidgetID) 	__attribute__((swift_name("Conduit.menuTitle(_:)")));
void Conduit_menuSetTitle (WidgetID, const char *) 	__attribute__((swift_name("Conduit.menuSetTitle(_:_:)")));
void Conduit_menuAddAction (WidgetID, ObjectID) 	__attribute__((swift_name("Conduit.menuAddAction(_:_:)")));
void Conduit_menuAddSeparator (WidgetID) 	__attribute__((swift_name("Conduit.menuAddSeparator(_:)")));

//-----------------------------------------------------------------------------
// QAction
//-----------------------------------------------------------------------------
ObjectID Conduit_actionNew (const char* title) 	__attribute__((swift_name("Conduit.actionNew(_:)")));
void Conduit_actionSetShortcut (ObjectID, SQKeySequence) 	__attribute__((swift_name("Conduit.actionSetShortcut(_:_:)")));

//-----------------------------------------------------------------------------
// QColor
//-----------------------------------------------------------------------------
//ObjectID Conduit_colorNew (long red, long green, long blue) 	__attribute__((swift_name("Conduit.colorNew(_:_:_:)")));

//-----------------------------------------------------------------------------
// QStatusBar
//-----------------------------------------------------------------------------
WidgetID Conduit_statusBarNew (WidgetID, const char*) 	__attribute__((swift_name("Conduit.statusBarNew(_:_:)")));
void Conduit_statusBarShowMessage (WidgetID, const char*, long)	__attribute__((swift_name("Conduit.statusBarShowMessage(_:_:_:)")));

//-----------------------------------------------------------------------------
// QWidget 
//-----------------------------------------------------------------------------
WidgetID Conduit_widgetNew (WidgetID)	__attribute__((swift_name("Conduit.widgetNew(_:)")));
void Conduit_move (WidgetID, SQCoord, SQCoord) 	__attribute__((swift_name("Conduit.move(_:_:_:)")));
void Conduit_resize (WidgetID, SQCoord, SQCoord) 	__attribute__((swift_name("Conduit.resize(_:_:_:)")));
void Conduit_setMinimumSize (WidgetID, SQSize) 	__attribute__((swift_name("Conduit.setMinimumSize(_:_:)")));
SQSize Conduit_minimumSize (WidgetID)   	__attribute__((swift_name("Conduit.minimumSize(_:)")));
void Conduit_setFrame (WidgetID, SQRect) 	__attribute__((swift_name("Conduit.setFrame(_:_:)")));
SQRect Conduit_frame (WidgetID)   	__attribute__((swift_name("Conduit.frame(_:)")));
SQCoord Conduit_height (WidgetID)   	__attribute__((swift_name("Conduit.height(_:)")));
SQCoord Conduit_width (WidgetID)   	__attribute__((swift_name("Conduit.width(_:)")));
void Conduit_setHidden (WidgetID, bool) 	__attribute__((swift_name("Conduit.setHidden(_:_:)")));
bool Conduit_isHidden (WidgetID)   	__attribute__((swift_name("Conduit.isHidden(_:)")));
void Conduit_setStyleSheet (WidgetID, const char*) 	__attribute__((swift_name("Conduit.setStyleSheet(_:_:)")));
const char *Conduit_styleSheet (WidgetID) 	__attribute__((swift_name("Conduit.styleSheet(_:)")));
void Conduit_raise (WidgetID) 	__attribute__((swift_name("Conduit.raise(_:)")));
void Conduit_lower (WidgetID) 	__attribute__((swift_name("Conduit.lower(_:)")));
WidgetID Conduit_layout (WidgetID) 	__attribute__((swift_name("Conduit.layout(_:)")));
void Conduit_setLayout (WidgetID, ObjectID) 	__attribute__((swift_name("Conduit.setLayout(_:_:)")));
void Conduit_setMaximumHeight(WidgetID, long maxh)     __attribute__((swift_name("Conduit.setMaximumHeight(_:_:)")));
void Conduit_setMaximumWidth(WidgetID, long maxw)     __attribute__((swift_name("Conduit.setMaximumWidth(_:_:)")));
void Conduit_setMinimumHeight(WidgetID, long minh)     __attribute__((swift_name("Conduit.setMinimumHeight(_:_:)")));
void Conduit_setMinimumWidth(WidgetID, long minw)     __attribute__((swift_name("Conduit.setMinimumWidth(_:_:)")));
void Conduit_setParent(WidgetID, WidgetID)     __attribute__((swift_name("Conduit.setParent(_:_:)")));
WidgetID Conduit_parentWidget(WidgetID)     __attribute__((swift_name("Conduit.parentWidget(_:)")));

//-----------------------------------------------------------------------------
// QGroupBox
//-----------------------------------------------------------------------------
WidgetID Conduit_groupBoxNew (WidgetID, const char*) 	__attribute__((swift_name("Conduit.groupBoxNew(_:_:)")));
long Conduit_groupBoxAlignment (WidgetID groupBoxID) 	__attribute__((swift_name("Conduit.groupBoxAlignment(_:)")));
void Conduit_groupBoxSetAlignment (WidgetID groupBoxID, long) 	__attribute__((swift_name("Conduit.groupBoxSetAlignment(_:_:)")));
const char* Conduit_groupBoxTitle (WidgetID) 	__attribute__((swift_name("Conduit.groupBoxTitle(_:)")));
void Conduit_groupBoxSetTitle (WidgetID, const char*) 	__attribute__((swift_name("Conduit.groupBoxSetTitle(_:_:)")));

//-----------------------------------------------------------------------------
// QLineEdit
//-----------------------------------------------------------------------------
WidgetID Conduit_lineEditNew (WidgetID) 	__attribute__((swift_name("Conduit.lineEditNew(_:)")));
const char *Conduit_lineEditText (WidgetID) 	__attribute__((swift_name("Conduit.lineEditText(_:)")));
void Conduit_lineEditSetText (WidgetID, const char *) 	__attribute__((swift_name("Conduit.lineEditSetText(_:_:)")));

//-----------------------------------------------------------------------------
// QDate
//-----------------------------------------------------------------------------
SQDate Conduit_dateWith(long,long,long)	__attribute__((swift_name("SQDate.with(_:_:_:)")));
SQDate Conduit_dateCurrent (void)	__attribute__((swift_name("SQDate.current()")));
long Conduit_dateDay (SQDate)	__attribute__((swift_name("Conduit.dateDay(_:)")));
long Conduit_dateMonth (SQDate)	__attribute__((swift_name("Conduit.dateMonth(_:)")));
long Conduit_dateYear (SQDate)	__attribute__((swift_name("Conduit.dateYear(_:)")));

//-----------------------------------------------------------------------------
// QCalendarWidget
//-----------------------------------------------------------------------------
WidgetID Conduit_calendarWidgetNew (WidgetID)	__attribute__((swift_name("Conduit.calendarWidgetNew(_:)")));
void Conduit_calendarWidgetClearMaximumDate(WidgetID)	__attribute__((swift_name("Conduit.calendarWidgetClearMaximumDate(_:)")));
void Conduit_calendarWidgetClearMinimumDate(WidgetID)	__attribute__((swift_name("Conduit.calendarWidgetClearMinimumDate(_:)")));
long Conduit_calendarWidgetMonthShown(WidgetID)	__attribute__((swift_name("Conduit.calendarWidgetMonthShown(_:)")));
long Conduit_calendarWidgetYearShown(WidgetID)	__attribute__((swift_name("Conduit.calendarWidgetYearShown(_:)")));
long Conduit_calendarWidgetHorizontalHeaderFormat(WidgetID)	__attribute__((swift_name("Conduit.calendarWidgetHorizontalHeaderFormat(_:)")));
long Conduit_calendarWidgetVerticalHeaderFormat(WidgetID)	__attribute__((swift_name("Conduit.calendarWidgetVerticalHeaderFormat(_:)")));
void Conduit_calendarWidgetSetHorizontalHeaderFormat(WidgetID,long)	__attribute__((swift_name("Conduit.calendarWidgetSetHorizontalHeaderFormat(_:_:)")));
void Conduit_calendarWidgetSetVerticalHeaderFormat(WidgetID,long)	__attribute__((swift_name("Conduit.calendarWidgetSetVerticalHeaderFormat(_:_:)")));
long Conduit_calendarWidgetFirstDayOfWeek(WidgetID)	__attribute__((swift_name("Conduit.calendarWidgetFirstDayOfWeek(_:)")));
void Conduit_calendarWidgetSetFirstDayOfWeek(WidgetID,long)	__attribute__((swift_name("Conduit.calendarWidgetSetFirstDayOfWeek(_:_:)")));
SQDate Conduit_calendarWidgetSelectedDate(WidgetID)	__attribute__((swift_name("Conduit.calendarWidgetSelectedDate(_:)")));

//-----------------------------------------------------------------------------
// QLabel
//-----------------------------------------------------------------------------
WidgetID Conduit_labelNew (WidgetID, const char*) 	__attribute__((swift_name("Conduit.labelNew(_:_:)")));
void Conduit_labelClear (WidgetID)	__attribute__((swift_name("Conduit.labelClear(_:)")));
const char* Conduit_labelText (WidgetID) 	__attribute__((swift_name("Conduit.labelText(_:)")));
void Conduit_labelSetText (WidgetID, const char*) 	__attribute__((swift_name("Conduit.labelSetText(_:_:)")));
void Conduit_labelSetPixmap (WidgetID, ObjectID) 	__attribute__((swift_name("Conduit.labelSetPixmap(_:_:)")));
void Conduit_labelSetImage (WidgetID, ObjectID) 	__attribute__((swift_name("Conduit.labelSetImage(_:_:)")));
bool Conduit_labelWordWrap (WidgetID labelID) 	__attribute__((swift_name("Conduit.labelWordWrap(_:)")));
void Conduit_labelSetWordWrap (WidgetID labelID, bool) 	__attribute__((swift_name("Conduit.labelSetWordWrap(_:_:)")));
long Conduit_labelAlignment (WidgetID labelID) 	__attribute__((swift_name("Conduit.labelAlignment(_:)")));
void Conduit_labelSetAlignment (WidgetID labelID, long) 	__attribute__((swift_name("Conduit.labelSetAlignment(_:_:)")));
long Conduit_labelIndent (WidgetID labelID) 	__attribute__((swift_name("Conduit.labelIndent(_:)")));
void Conduit_labelSetIndent (WidgetID labelID, long) 	__attribute__((swift_name("Conduit.labelSetIndent(_:_:)")));
long Conduit_labelMargin (WidgetID labelID) 	__attribute__((swift_name("Conduit.labelMargin(_:)")));
void Conduit_labelSetMargin (WidgetID labelID, long) 	__attribute__((swift_name("Conduit.labelSetMargin(_:_:)")));

//-----------------------------------------------------------------------------
// QLayout (abstract class)
//-----------------------------------------------------------------------------
void Conduit_layoutAddWidget (WidgetID,WidgetID) 	__attribute__((swift_name("Conduit.layoutAddWidget(_:_:)")));
void Conduit_layoutRemoveWidget (WidgetID,WidgetID) 	__attribute__((swift_name("Conduit.layoutRemoveWidget(_:_:)")));
long Conduit_layoutSpacing (ObjectID) 	__attribute__((swift_name("Conduit.layoutSpacing(_:)")));
void Conduit_layoutSetSpacing (ObjectID,long) 	__attribute__((swift_name("Conduit.layoutSetSpacing(_:_:)")));

//-----------------------------------------------------------------------------
// QGridLayout
//-----------------------------------------------------------------------------
ObjectID Conduit_gridLayoutNew (WidgetID) 	__attribute__((swift_name("Conduit.gridLayoutNew(_:)")));
void Conduit_gridLayoutAddWidget(ObjectID,WidgetID,long row,long col,long align)	__attribute__((swift_name("Conduit.gridLayoutAddWidget(_:_:_:_:_:)")));
void Conduit_gridLayoutAddWidgetWithSpans(ObjectID,WidgetID,long row,long col,long rowspan,long colspan,long align) __attribute__((swift_name("Conduit.gridLayoutAddWidgetWithSpans(_:_:_:_:_:_:_:)")));
SQRect Conduit_gridLayoutCellRect(ObjectID,long,long) __attribute__((swift_name("Conduit.gridLayoutCellRect(_:_:_:)")));
long Conduit_gridLayoutColumnCount(ObjectID) __attribute__((swift_name("Conduit.gridLayoutColumnCount(_:)")));
long Conduit_gridLayoutColumnMinimumWidth(ObjectID,long) __attribute__((swift_name("Conduit.gridLayoutColumnMinimumWidth(_:_:)")));
long Conduit_gridLayoutColumnStretch(ObjectID,long) __attribute__((swift_name("Conduit.gridLayoutColumnStretch(_:_:)")));
long Conduit_gridLayoutHorizontalSpacing(ObjectID) __attribute__((swift_name("Conduit.gridLayoutHorizontalSpacing(_:)")));
long Conduit_gridLayoutRowCount(ObjectID) __attribute__((swift_name("Conduit.gridLayoutRowCount(_:)")));
long Conduit_gridLayoutRowMinimumHeight(ObjectID,long) __attribute__((swift_name("Conduit.gridLayoutRowMinimumHeight(_:_:)")));
long Conduit_gridLayoutRowStretch(ObjectID,long) __attribute__((swift_name("Conduit.gridLayoutRowStretch(_:_:)")));
void Conduit_gridLayoutSetColumnMinimumWidth(ObjectID,long,long) __attribute__((swift_name("Conduit.gridLayoutSetColumnMinimumWidth(_:_:_:)")));
void Conduit_gridLayoutSetColumnStretch(ObjectID,long,long) __attribute__((swift_name("Conduit.gridLayoutSetColumnStretch(_:_:_:)")));
void Conduit_gridLayoutSetHorizontalSpacing(ObjectID,long) __attribute__((swift_name("Conduit.gridLayoutSetHorizontalSpacing(_:_:)")));
void Conduit_gridLayoutSetRowMinimumHeight(ObjectID,long,long) __attribute__((swift_name("Conduit.gridLayoutSetRowMinimumHeight(_:_:_:)")));
void Conduit_gridLayoutSetRowStretch(ObjectID,long,long) __attribute__((swift_name("Conduit.gridLayoutSetRowStretch(_:_:_:)")));
void Conduit_gridLayoutSetVerticalSpacing(ObjectID,long) __attribute__((swift_name("Conduit.gridLayoutSetVerticalSpacing(_:_:)")));
long Conduit_gridLayoutVerticalSpacing(ObjectID) __attribute__((swift_name("Conduit.gridLayoutVerticalSpacing(_:)")));
		
//-----------------------------------------------------------------------------
// QBoxLayout
//-----------------------------------------------------------------------------
ObjectID Conduit_boxLayoutNew (WidgetID,long) 	__attribute__((swift_name("Conduit.boxLayoutNew(_:_:)")));
void Conduit_boxLayoutAddWidget (ObjectID,WidgetID,long,long) 	__attribute__((swift_name("Conduit.boxLayoutAddWidget(_:_:_:_:)")));
void Conduit_boxLayoutAddSpacing (ObjectID, long)	__attribute__((swift_name("Conduit.boxLayoutAddSpacing(_:_:)")));
void Conduit_boxLayoutAddStretch (ObjectID, long)	__attribute__((swift_name("Conduit.boxLayoutAddStretch(_:_:)")));
void Conduit_boxLayoutAddStrut (ObjectID, long)	__attribute__((swift_name("Conduit.boxLayoutAddStrut(_:_:)")));

//-----------------------------------------------------------------------------
// QHBoxLayout
//-----------------------------------------------------------------------------
ObjectID Conduit_hBoxLayoutNew (WidgetID) 	__attribute__((swift_name("Conduit.hBoxLayoutNew(_:)")));

//-----------------------------------------------------------------------------
// QVBoxLayout
//-----------------------------------------------------------------------------
ObjectID Conduit_vBoxLayoutNew (WidgetID) 	__attribute__((swift_name("Conduit.vBoxLayoutNew(_:)")));

//-----------------------------------------------------------------------------
// QAbstractButton
//-----------------------------------------------------------------------------
const char *Conduit_abstractButtonText (WidgetID) 	__attribute__((swift_name("Conduit.abstractButtonText(_:)")));
void Conduit_abstractButtonSetText (WidgetID, const char *) 	__attribute__((swift_name("Conduit.abstractButtonSetText(_:_:)")));
bool Conduit_abstractButtonIsChecked (WidgetID) 	__attribute__((swift_name("Conduit.abstractButtonIsChecked(_:)")));
void Conduit_abstractButtonSetChecked (WidgetID, bool) 	__attribute__((swift_name("Conduit.abstractButtonSetChecked(_:_:)")));

//-----------------------------------------------------------------------------
// QCheckBox
//-----------------------------------------------------------------------------
WidgetID Conduit_checkBoxNew (WidgetID, const char *) 	__attribute__((swift_name("Conduit.checkBoxNew(_:_:)")));
bool Conduit_checkBoxIsTristate (WidgetID) 	__attribute__((swift_name("Conduit.checkBoxIsTristate(_:)")));
void Conduit_checkBoxSetTristate (WidgetID, bool) 	__attribute__((swift_name("Conduit.checkBoxSetTristate(_:_:)")));
long Conduit_checkBoxCheckState (WidgetID) 	__attribute__((swift_name("Conduit.checkBoxCheckState(_:)")));
void Conduit_checkBoxSetCheckState (WidgetID, long) 	__attribute__((swift_name("Conduit.checkBoxSetCheckState(_:_:)")));

//-----------------------------------------------------------------------------
// QRadioButton
//-----------------------------------------------------------------------------
WidgetID Conduit_radioButtonNew (WidgetID, const char *) 	__attribute__((swift_name("Conduit.radioButtonNew(_:_:)")));

//-----------------------------------------------------------------------------
// QPushButton
//-----------------------------------------------------------------------------
WidgetID Conduit_pushButtonNew (WidgetID, const char *) 	__attribute__((swift_name("Conduit.pushButtonNew(_:_:)")));
//const char *Conduit_pushButtonText (WidgetID) 	__attribute__((swift_name("Conduit.pushButtonText(_:)")));
//void Conduit_pushButtonSetText (WidgetID, const char *) 	__attribute__((swift_name("Conduit.pushButtonSetText(_:_:)")));
bool Conduit_pushButtonIsFlat (WidgetID) 	__attribute__((swift_name("Conduit.pushButtonIsFlat(_:)")));
void Conduit_pushButtonSetFlat (WidgetID, bool) 	__attribute__((swift_name("Conduit.pushButtonSetFlat(_:_:)")));
bool Conduit_pushButtonIsDefault (WidgetID) 	__attribute__((swift_name("Conduit.pushButtonIsDefault(_:)")));
void Conduit_pushButtonSetDefault (WidgetID, bool) 	__attribute__((swift_name("Conduit.pushButtonSetDefault(_:_:)")));

//-----------------------------------------------------------------------------
// Text editor
//-----------------------------------------------------------------------------
WidgetID Conduit_textEditNew (WidgetID) 	__attribute__((swift_name("Conduit.textEditNew(_:)")));
const char *Conduit_textEditToPlainText (WidgetID) 	__attribute__((swift_name("Conduit.textEditToPlainText(_:)")));
void Conduit_textEditSetText (WidgetID, const char *) 	__attribute__((swift_name("Conduit.textEditSetText(_:_:)")));
//void Conduit_textEditSetHTML (WidgetID, const char *) 	__attribute__((swift_name("Conduit.textEditSetHTML(_:_:)")));
void Conduit_textEditSetReadOnly (WidgetID, bool) 	__attribute__((swift_name("Conduit.textEditSetReadOnly(_:_:)")));
const char *Conduit_textEditToHTML (WidgetID) 	__attribute__((swift_name("Conduit.textEditToHTML(_:)")));
void Conduit_textEditSetAcceptRichText (WidgetID, bool)	__attribute__((swift_name("Conduit.textEditSetAcceptRichText(_:_:)")));

//-----------------------------------------------------------------------------
// Web engine view
//-----------------------------------------------------------------------------
WidgetID Conduit_webEngineViewNew (WidgetID) 	__attribute__((swift_name("Conduit.webEngineViewNew(_:)")));
void Conduit_webEngineViewSetHTML (WidgetID, const char *) 	__attribute__((swift_name("Conduit.webEngineViewSetHTML(_:_:)")));

//-----------------------------------------------------------------------------
// QTableWidgetItem
//-----------------------------------------------------------------------------
ObjectID Conduit_tableWidgetItemNew (const char*) 	__attribute__((swift_name("Conduit.tableWidgetItemNew(_:)")));
const char* Conduit_tableWidgetItemText (ObjectID) 	__attribute__((swift_name("Conduit.tableWidgetItemText(_:)")));
void Conduit_tableWidgetItemSetText (ObjectID,const char*) 	__attribute__((swift_name("Conduit.tableWidgetItemSetText(_:_:)")));
void Conduit_tableWidgetItemSetForeground (ObjectID, SQColor) 	__attribute__((swift_name("Conduit.tableWidgetItemSetForeground(_:_:)")));
void Conduit_tableWidgetItemSetBackground (ObjectID, SQColor) 	__attribute__((swift_name("Conduit.tableWidgetItemSetBackground(_:_:)")));

//-----------------------------------------------------------------------------
// QTableWidget
//-----------------------------------------------------------------------------
WidgetID Conduit_tableWidgetNew (WidgetID) 	__attribute__((swift_name("Conduit.tableWidgetNew(_:)")));
long Conduit_tableWidgetColumnCount (WidgetID)	__attribute__((swift_name("Conduit.tableWidgetColumnCount(_:)")));
void Conduit_tableWidgetSetColumnCount (WidgetID, long)	__attribute__((swift_name("Conduit.tableWidgetSetColumnCount(_:_:)")));
long Conduit_tableWidgetRowCount (WidgetID) 	__attribute__((swift_name("Conduit.tableWidgetRowCount(_:)")));
void Conduit_tableWidgetSetRowCount (WidgetID, long) __attribute__((swift_name("Conduit.tableWidgetSetRowCount(_:_:)")));
long Conduit_tableWidgetCurrentColumn (WidgetID)	__attribute__((swift_name("Conduit.tableWidgetCurrentColumn(_:)")));
long Conduit_tableWidgetCurrentRow (WidgetID)	__attribute__((swift_name("Conduit.tableWidgetCurrentRow(_:)")));
void Conduit_tableWidgetSetCurrentCell (WidgetID, long,long)	__attribute__((swift_name("Conduit.tableWidgetSetCurrentCell(_:_:_:)")));
ObjectID Conduit_tableWidgetItem (WidgetID,long,long)	__attribute__((swift_name("Conduit.tableWidgetItem(_:_:_:)")));
void Conduit_tableWidgetSetItem (WidgetID,long,long,ObjectID)	__attribute__((swift_name("Conduit.tableWidgetSetItem(_:_:_:_:)")));

ObjectID Conduit_tableWidgetCurrentItem (WidgetID)	__attribute__((swift_name("Conduit.tableWidgetCurrentItem(_:)")));

WidgetID Conduit_tableWidgetCellWidget (WidgetID,long,long)	__attribute__((swift_name("Conduit.tableWidgetCellWidget(_:_:_:)")));
void Conduit_tableWidgetSetCellWidget (WidgetID,long,long,WidgetID)	__attribute__((swift_name("Conduit.tableWidgetSetCellWidget(_:_:_:_:)")));

void Conduit_tableWidgetInsertColumn (WidgetID tableID, long column)	__attribute__((swift_name("Conduit.tableWidgetInsertColumn(_:_:)")));
void Conduit_tableWidgetInsertRow (WidgetID tableID, long row)	__attribute__((swift_name("Conduit.tableWidgetInsertRow(_:_:)")));
void Conduit_tableWidgetSetVerticalHeaderLabel (WidgetID tableID, const char *, bool)	__attribute__((swift_name("Conduit.tableWidgetSetVerticalHeaderLabels(_:_:_:)")));
void Conduit_tableWidgetSetHorizontalHeaderLabel (WidgetID tableID, const char *, bool)	__attribute__((swift_name("Conduit.tableWidgetSetHorizontalHeaderLabels(_:_:_:)")));

#endif
