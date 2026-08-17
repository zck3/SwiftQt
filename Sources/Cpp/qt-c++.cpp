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

#include <QtCore/QDebug>
#include <QtCore/QtGlobal>
#include <QtGui/QCloseEvent>
#include <QtGui/QColor>
#include <QtGui/QGuiApplication>
#include <QtGui/QKeySequence>
#include <QtGui/QMoveEvent>
#include <QtGui/QPalette>
#include <QtGui/QResizeEvent>
#include <QtGui/QScreen>
#include <QtGui/QWheelEvent>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

#include <iostream>
#include <exception>

#include "qt-c++.h"

static CallPropagator *sharedCallPropagator = NULL;

#ifdef __cplusplus
extern "C" {
#endif
  #include <stdio.h>
#ifdef __cplusplus
}
#endif

void ensure_call_propagator_exists()
{
	if (!sharedCallPropagator) {
		sharedCallPropagator = new CallPropagator();
	}
}

//--------------------
// QSlider
//--------------------
WidgetID Conduit_sliderNew (WidgetID parentID) {
	return sharedCallPropagator->sliderNew(parentID);
}

long Conduit_sliderTickPosition (WidgetID widgetID) {
	return sharedCallPropagator->sliderTickPosition(widgetID);
}

long Conduit_sliderTickInterval (WidgetID widgetID) {
	return sharedCallPropagator->sliderTickInterval(widgetID);
}

void Conduit_sliderSetTickPosition (WidgetID widgetID, long value) {
	sharedCallPropagator->sliderSetTickPosition (widgetID, value);
}

void Conduit_sliderSetTickInterval (WidgetID widgetID, long value) {
	sharedCallPropagator->sliderSetTickInterval (widgetID, value);
}

//--------------------
// QAbstractSlider
//--------------------
long Conduit_abstractSliderOrientation (WidgetID widgetID) {
	return sharedCallPropagator->abstractSliderOrientation (widgetID);
}

void Conduit_abstractSliderSetOrientation (WidgetID widgetID, long value) {
	sharedCallPropagator->abstractSliderSetOrientation (widgetID, value);
}

void Conduit_abstractSliderSetMaximum (WidgetID widgetID, long maximum) {
	sharedCallPropagator->abstractSliderSetMaximum (widgetID, maximum);
}

void Conduit_abstractSliderSetMinimum (WidgetID widgetID, long minimum) {
	sharedCallPropagator->abstractSliderSetMinimum (widgetID, minimum);
}

void Conduit_abstractSliderSetPageStep (WidgetID widgetID, long pageStep) {
	sharedCallPropagator->abstractSliderSetPageStep (widgetID, pageStep);
}

void Conduit_abstractSliderSetValue (WidgetID widgetID, long value) {
	sharedCallPropagator->abstractSliderSetValue (widgetID, value);
}

void Conduit_abstractSliderSetSliderDown (WidgetID widgetID, bool value) {
	sharedCallPropagator->abstractSliderSetSliderDown (widgetID, value);
}

bool Conduit_abstractSliderIsSliderDown (WidgetID widgetID) {
	return sharedCallPropagator->abstractSliderIsSliderDown (widgetID);
}

long Conduit_abstractSliderMaximum (WidgetID widgetID) {
	return sharedCallPropagator->abstractSliderMaximum (widgetID);
}

long Conduit_abstractSliderMinimum (WidgetID widgetID) {
	return sharedCallPropagator->abstractSliderMinimum (widgetID);
}

long Conduit_abstractSliderPageStep (WidgetID widgetID) {
	return sharedCallPropagator->abstractSliderPageStep (widgetID);
}

long Conduit_abstractSliderValue (WidgetID widgetID) {
	return sharedCallPropagator->abstractSliderValue (widgetID);
}

//--------------------
// QDate
//--------------------
SQDate Conduit_dateWith (long year, long month, long day) {
	QDate date (year, month, day);
	return date.toJulianDay();
}

SQDate Conduit_dateCurrent () {
	QDate qdate = QDate::currentDate();
	return qdate.toJulianDay();
}

long Conduit_dateDay (SQDate date) {
	QDate qdate = QDate::fromJulianDay(date);
	return qdate.day();
}

long Conduit_dateMonth (SQDate date) {
	QDate qdate = QDate::fromJulianDay(date);
	return qdate.month();
}

long Conduit_dateYear (SQDate date) {
	QDate qdate = QDate::fromJulianDay(date);
	return qdate.year();
}

//--------------------
// QCalendarWidget
//--------------------
WidgetID Conduit_calendarWidgetNew (WidgetID parentID) {
	return sharedCallPropagator->calendarWidgetNew (parentID);
}

SQDate Conduit_calendarWidgetSelectedDate(WidgetID widgetID) {
	return sharedCallPropagator->calendarWidgetSelectedDate (widgetID);
}

void Conduit_calendarWidgetClearMaximumDate (WidgetID widgetID) {
	sharedCallPropagator->calendarWidgetClearMaximumDate (widgetID);
}

void Conduit_calendarWidgetClearMinimumDate (WidgetID widgetID) {
	sharedCallPropagator->calendarWidgetClearMinimumDate (widgetID);
}

long Conduit_calendarWidgetMonthShown (WidgetID widgetID) {
	return sharedCallPropagator->calendarWidgetMonthShown (widgetID);
}

long Conduit_calendarWidgetYearShown (WidgetID widgetID) {
	return sharedCallPropagator->calendarWidgetYearShown (widgetID);
}

long Conduit_calendarWidgetHorizontalHeaderFormat (WidgetID widgetID)
{
	return sharedCallPropagator->calendarWidgetHorizontalHeaderFormat (widgetID);
}

long Conduit_calendarWidgetVerticalHeaderFormat (WidgetID widgetID)
{
	return sharedCallPropagator->calendarWidgetVerticalHeaderFormat (widgetID);
}

void Conduit_calendarWidgetSetHorizontalHeaderFormat (WidgetID widgetID, long value)
{
	sharedCallPropagator->calendarWidgetSetHorizontalHeaderFormat (widgetID, value);
}

void Conduit_calendarWidgetSetVerticalHeaderFormat (WidgetID widgetID, long value)
{
	sharedCallPropagator->calendarWidgetSetVerticalHeaderFormat (widgetID, value);
}

long Conduit_calendarWidgetFirstDayOfWeek(WidgetID widgetID)
{
	return sharedCallPropagator->calendarWidgetFirstDayOfWeek (widgetID);
}

void Conduit_calendarWidgetSetFirstDayOfWeek(WidgetID widgetID, long value)
{
	sharedCallPropagator->calendarWidgetSetFirstDayOfWeek (widgetID, value);
}

//--------------------
// QGroupBox
//--------------------
WidgetID Conduit_groupBoxNew (WidgetID parentID, const char* title)
{
	return sharedCallPropagator->groupBoxNew (parentID, title);
}

long Conduit_groupBoxAlignment (WidgetID groupBoxID)
{
	return sharedCallPropagator->groupBoxAlignment (groupBoxID);
}

void Conduit_groupBoxSetAlignment (WidgetID groupBoxID, long value)
{
	sharedCallPropagator->groupBoxSetAlignment (groupBoxID, value);
}

const char* Conduit_groupBoxTitle (WidgetID groupBoxID)
{
	return sharedCallPropagator->groupBoxTitle (groupBoxID);
}

void Conduit_groupBoxSetTitle (WidgetID groupBoxID, const char* title)
{
	sharedCallPropagator->groupBoxSetTitle (groupBoxID, title ?: "");
}

//--------------------
// QLayout
//--------------------
void Conduit_layoutAddWidget (ObjectID layoutID, WidgetID subwidgetID)
{
	sharedCallPropagator->layoutAddWidget (layoutID, subwidgetID);
}

void Conduit_layoutRemoveWidget (ObjectID layoutID, WidgetID subwidgetID)
{
	sharedCallPropagator->layoutRemoveWidget (layoutID, subwidgetID);
}

long Conduit_layoutSpacing (ObjectID layoutID)
{
	return sharedCallPropagator->layoutSpacing(layoutID);
}

void Conduit_layoutSetSpacing (ObjectID layoutID, long spacing)
{
	sharedCallPropagator->layoutSetSpacing(layoutID, spacing);
}

//--------------------
// QGridLayout
//--------------------
ObjectID Conduit_gridLayoutNew (WidgetID widgetID) {
	return sharedCallPropagator->gridLayoutNew(widgetID);
}

void Conduit_gridLayoutAddWidget (ObjectID layoutID, WidgetID widgetID, long row, long column, long alignment) {
	sharedCallPropagator->gridLayoutAddWidget (layoutID, widgetID, row, column, alignment);
}

void Conduit_gridLayoutAddWidgetWithSpans (ObjectID layoutID, WidgetID widgetID, 
				   long row, long column, long rowspan, long colspan, long alignment) {
	sharedCallPropagator->gridLayoutAddWidgetWithSpans (layoutID, widgetID, row, column, rowspan, colspan, alignment);
}

SQRect Conduit_gridLayoutCellRect (ObjectID layoutID, long row, long column) {
	return sharedCallPropagator->gridLayoutCellRect (layoutID, row, column);
}

long Conduit_gridLayoutColumnCount (ObjectID layoutID) {
	return sharedCallPropagator->gridLayoutColumnCount (layoutID);
}

long Conduit_gridLayoutColumnMinimumWidth (ObjectID layoutID, long column) {
	return sharedCallPropagator->gridLayoutColumnMinimumWidth (layoutID, column);
}

long Conduit_gridLayoutColumnStretch (ObjectID layoutID, long column) {
	return sharedCallPropagator->gridLayoutColumnStretch (layoutID, column);
}

long Conduit_gridLayoutHorizontalSpacing (ObjectID layoutID) {
	return sharedCallPropagator->gridLayoutHorizontalSpacing (layoutID);
}

long Conduit_gridLayoutRowCount (ObjectID layoutID) {
	return sharedCallPropagator->gridLayoutRowCount (layoutID);
}

long Conduit_gridLayoutRowMinimumHeight (ObjectID layoutID, long row) {
	return sharedCallPropagator->gridLayoutRowMinimumHeight (layoutID, row);
}

long Conduit_gridLayoutRowStretch (ObjectID layoutID, long row) {
	return sharedCallPropagator->gridLayoutRowStretch (layoutID, row);
}

void Conduit_gridLayoutSetColumnMinimumWidth (ObjectID layoutID, long column, long value) {
	sharedCallPropagator->gridLayoutSetColumnMinimumWidth (layoutID, column, value);
}

void Conduit_gridLayoutSetColumnStretch (ObjectID layoutID, long column, long value) {
	sharedCallPropagator->gridLayoutSetColumnStretch (layoutID, column, value);
}

void Conduit_gridLayoutSetHorizontalSpacing (ObjectID layoutID, long value) {
	sharedCallPropagator->gridLayoutSetHorizontalSpacing (layoutID, value);
}

void Conduit_gridLayoutSetRowMinimumHeight (ObjectID layoutID, long row, long value) {
	sharedCallPropagator->gridLayoutSetRowMinimumHeight (layoutID, row, value);
}

void Conduit_gridLayoutSetRowStretch (ObjectID layoutID, long row, long value) {
	sharedCallPropagator->gridLayoutSetRowStretch (layoutID, row, value);
}

void Conduit_gridLayoutSetVerticalSpacing (ObjectID layoutID, long value) {
	sharedCallPropagator->gridLayoutSetVerticalSpacing (layoutID, value);
}

long Conduit_gridLayoutVerticalSpacing (ObjectID layoutID) {
	return sharedCallPropagator->gridLayoutVerticalSpacing (layoutID);
}

//--------------------
// QBoxLayout
//--------------------
ObjectID Conduit_boxLayoutNew (ObjectID parentID, long direction)
{
	return sharedCallPropagator->boxLayoutNew (parentID, direction);
}

void Conduit_boxLayoutAddWidget (ObjectID layoutID, WidgetID subwidgetID, long stretch, long alignment)
{
	sharedCallPropagator->boxLayoutAddWidget (layoutID, subwidgetID, stretch, alignment);
}

void Conduit_boxLayoutAddSpacing (ObjectID layoutID, long value)
{
	sharedCallPropagator->boxLayoutAddSpacing (layoutID, value);
}

void Conduit_boxLayoutAddStretch (ObjectID layoutID, long value)
{
	sharedCallPropagator->boxLayoutAddStretch (layoutID, value);
}

void Conduit_boxLayoutAddStrut (ObjectID layoutID, long value)
{
	sharedCallPropagator->boxLayoutAddStrut (layoutID, value);
}

//--------------------
// QHBoxLayout
//--------------------
ObjectID Conduit_hBoxLayoutNew (ObjectID parentID)
{
	return sharedCallPropagator->hBoxLayoutNew (parentID);
}

//--------------------
// QVBoxLayout
//--------------------
ObjectID Conduit_vBoxLayoutNew (ObjectID parentID)
{
	return sharedCallPropagator->vBoxLayoutNew (parentID);
}

//--------------------
// QPixmap
//--------------------
ObjectID Conduit_pixmapWithPathNew (const char* path)
{
	return sharedCallPropagator->pixmapWithPathNew (path);
}

ObjectID Conduit_pixmapWithSizeNew (SQCoord width, SQCoord height)
{
	return sharedCallPropagator->pixmapWithSizeNew (width, height);
}

bool Conduit_pixmapLoad (ObjectID objectID, const char *path)
{
	return sharedCallPropagator->pixmapLoad (objectID, path);
}

SQCoord Conduit_pixmapWidth (ObjectID objectID)
{
	return sharedCallPropagator->pixmapWidth (objectID);
}

SQCoord Conduit_pixmapHeight (ObjectID objectID)
{
	return sharedCallPropagator->pixmapHeight (objectID);
}

SQCoord Conduit_pixmapDepth (ObjectID objectID)
{
	return sharedCallPropagator->pixmapDepth (objectID);
}

//--------------------
// QImage
//--------------------
ObjectID Conduit_imageNew (const char* path)
{
	return sharedCallPropagator->imageNew (path);
}

bool Conduit_imageLoad (ObjectID objectID, const char *path)
{
	return sharedCallPropagator->imageLoad (objectID, path);
}

bool Conduit_imageIsGrayscale (ObjectID objectID)
{
	return sharedCallPropagator->imageIsGrayscale (objectID);
}

SQCoord Conduit_imageWidth (ObjectID objectID)
{
	return sharedCallPropagator->imageWidth (objectID);
}

SQCoord Conduit_imageHeight (ObjectID objectID)
{
	return sharedCallPropagator->imageHeight (objectID);
}

SQCoord Conduit_imageDepth (ObjectID objectID)
{
	return sharedCallPropagator->imageDepth (objectID);
}

//--------------------
// Conveniences
//--------------------
void Conduit_swiftQtConveniencePopup(const char* title, const char* message)
{
	sharedCallPropagator->conveniencePopup (title, message);
}

bool Conduit_swiftQtConvenienceQuestion(const char* title, const char* message)
{
	return sharedCallPropagator->yesnoQuestion (title, message);
}

bool Conduit_swiftQtIsDarkMode()
{
	QColor color = QPalette().color(QPalette::Window);
	int average = (color.red() + color.green() + color.blue()) / 3;
	return average < 0x60;
}

//--------------------
// QWidget
//--------------------
WidgetID Conduit_widgetNew (WidgetID parentID)
{
	return sharedCallPropagator->widgetNew (parentID);
}

void Conduit_move (WidgetID widgetID, SQCoord x, SQCoord y)
{
	sharedCallPropagator->move (widgetID, x, y);
}

void Conduit_resize (WidgetID widgetID, SQCoord width, SQCoord height)
{
	sharedCallPropagator->resize (widgetID, width, height);
}

void Conduit_setHidden (WidgetID widgetID, bool value)
{
	sharedCallPropagator->setHidden (widgetID, value);
}

bool Conduit_isHidden (WidgetID widgetID)
{
	return sharedCallPropagator->isHidden (widgetID);
}

void Conduit_setMinimumSize (WidgetID widgetID, SQSize size)
{
	sharedCallPropagator->setMinimumSize (widgetID, size);
}

SQSize Conduit_minimumSize (WidgetID widgetID)
{
	return sharedCallPropagator->minimumSize (widgetID);
}

void Conduit_setParent (WidgetID widgetID, WidgetID parentID)
{
	sharedCallPropagator->setParent (widgetID, parentID);
}

WidgetID Conduit_parentWidget (WidgetID widgetID)
{
	return sharedCallPropagator->parentWidget (widgetID);
}

void Conduit_setFrame (WidgetID widgetID, SQRect rect)
{
	sharedCallPropagator->setFrame (widgetID, rect);
}

SQRect Conduit_frame (WidgetID widgetID)
{
	return sharedCallPropagator->frame (widgetID);
}

SQCoord Conduit_height (WidgetID widgetID)
{
	return sharedCallPropagator->height (widgetID);
}

SQCoord Conduit_width (WidgetID widgetID)
{
	return sharedCallPropagator->width (widgetID);
}

const char *Conduit_styleSheet (WidgetID widgetID)
{
	return sharedCallPropagator->styleSheet (widgetID);
}

void Conduit_setStyleSheet (WidgetID widgetID, const char* string)
{
	sharedCallPropagator->setStyleSheet (widgetID, string);
}

void Conduit_raise (WidgetID widgetID)
{
	sharedCallPropagator->raise (widgetID);
}

void Conduit_lower (WidgetID widgetID)
{
	sharedCallPropagator->lower (widgetID);
}

WidgetID Conduit_layout (WidgetID widgetID)
{
	return sharedCallPropagator->layout (widgetID);
}

void Conduit_setLayout (WidgetID widgetID, ObjectID layoutID)
{
	sharedCallPropagator->setLayout (widgetID, layoutID);
}

void Conduit_setMaximumHeight (WidgetID widgetID, long value) {
	if (value >= 0) sharedCallPropagator->setMaximumHeight (widgetID, value);
}

void Conduit_setMaximumWidth (WidgetID widgetID, long value) {
	if (value >= 0) sharedCallPropagator->setMaximumWidth (widgetID, value);
}

void Conduit_setMinimumHeight (WidgetID widgetID, long value) {
	if (value >= 0) sharedCallPropagator->setMinimumHeight (widgetID, value);
}

void Conduit_setMinimumWidth (WidgetID widgetID, long value) {
	if (value >= 0) sharedCallPropagator->setMinimumWidth (widgetID, value);
}

//--------------------
// QMainWindow
//--------------------
WidgetID Conduit_windowNew (SQCoord x, SQCoord y, SQCoord width, SQCoord height)
{
	return sharedCallPropagator->windowNew (x, y, width, height);
}

const char *Conduit_windowTitle (WidgetID windowID)
{
	return sharedCallPropagator->windowTitle (windowID);
}

void Conduit_windowSetTitle (WidgetID windowID, const char *title)
{
	sharedCallPropagator->windowSetTitle (windowID, title);
}

void Conduit_windowSetMinimumSize (WidgetID windowID, SQCoord width, SQCoord height)
{
	sharedCallPropagator->windowSetMinimumSize (windowID, width, height);
}

void Conduit_windowSetMaximumSize (WidgetID windowID, SQCoord width, SQCoord height)
{
	sharedCallPropagator->windowSetMaximumSize (windowID, width, height);
}

SQCoord Conduit_windowWidth (WidgetID windowID) // Superfluous?
{
	return sharedCallPropagator->windowWidth (windowID);
}

SQCoord Conduit_windowHeight (WidgetID windowID) // Superfluous?
{
	return sharedCallPropagator->windowHeight (windowID);
}

void Conduit_windowClose (WidgetID windowID) {
	return sharedCallPropagator->windowClose (windowID);
}

void Conduit_windowShow (WidgetID windowID) 
{
	QMainWindow *window = sharedCallPropagator->lookupWindow (windowID);
	if (window) {
		window->show();
	}
}

void Conduit_windowHide (WidgetID windowID) 
{
	QMainWindow *window = sharedCallPropagator->lookupWindow (windowID);
	if (window) {
		window->hide();
	}
}

void Conduit_windowSetStatusBar (WidgetID windowID, WidgetID statusBarID)
{
	sharedCallPropagator->windowSetStatusBar (windowID, statusBarID);
}

void Conduit_windowSetCentralWidget (WidgetID windowID, WidgetID widgetID)
{
	sharedCallPropagator->windowSetCentralWidget (windowID, widgetID);
}

void Conduit_windowSetMenuBar (WidgetID windowID, WidgetID menuBarID)
{
	sharedCallPropagator->windowSetMenuBar (windowID, menuBarID);
}

//--------------------
// QStatusBar
//--------------------
WidgetID Conduit_statusBarNew (WidgetID parentID, const char *text)
{
	return sharedCallPropagator->statusBarNew (parentID, text ?: "");
}

void Conduit_statusBarShowMessage (WidgetID widgetID, const char* text, long duration)
{
	sharedCallPropagator->statusBarShowMessage (widgetID, text ?: "", duration);
}

//--------------------
// QMenuBar
//--------------------
WidgetID Conduit_menuBarNew ()
{
	return sharedCallPropagator->menuBarNew ();
}

void Conduit_menuBarAddMenu (WidgetID parent, WidgetID menu)
{
	sharedCallPropagator->menuBarAddMenu (parent, menu);
}

//--------------------
// QMenu
//--------------------
WidgetID Conduit_menuNew (const char *title)
{
	return sharedCallPropagator->menuNew (title);
}

const char *Conduit_menuTitle (WidgetID widgetID)
{
	return sharedCallPropagator->menuTitle (widgetID);
}

void Conduit_menuSetTitle (WidgetID widgetID, const char *title)
{
	sharedCallPropagator->menuSetTitle (widgetID, title);
}

void Conduit_menuAddAction (WidgetID widgetID, ObjectID actionID)
{
	sharedCallPropagator->menuAddAction (widgetID, actionID);
}

void Conduit_menuAddSeparator (WidgetID widgetID)
{
	sharedCallPropagator->menuAddSeparator (widgetID);
}

//--------------------
// QAction
//--------------------
ObjectID Conduit_actionNew (const char* text)
{
	return sharedCallPropagator->actionNew (text);
}

void Conduit_actionSetShortcut (ObjectID actionID, SQKeySequence keySequence)
{
	return sharedCallPropagator->actionSetShortcut (actionID, keySequence);
}

#if 0
//--------------------
// QColor
//--------------------
ObjectID Conduit_colorNew (long red, long green, long blue)
{
	return sharedCallPropagator->colorNew (red, green, blue);
}
#endif

//--------------------
// QLabel
//--------------------
WidgetID Conduit_labelNew (WidgetID parent, const char *text)
{
	return sharedCallPropagator->labelNew (parent, text);
}

void Conduit_labelClear (WidgetID labelID)
{
	sharedCallPropagator->labelClear (labelID);
}

const char* Conduit_labelText (WidgetID labelID)
{
	return sharedCallPropagator->labelText (labelID);
}

void Conduit_labelSetText (WidgetID labelID, const char*string)
{
	sharedCallPropagator->labelSetText (labelID, string);
}

bool Conduit_labelWordWrap (WidgetID labelID)
{
	return sharedCallPropagator->labelWordWrap (labelID);
}

void Conduit_labelSetWordWrap (WidgetID labelID, bool value)
{
	sharedCallPropagator->labelSetWordWrap (labelID, value);
}

long Conduit_labelAlignment (WidgetID labelID)
{
	return sharedCallPropagator->labelAlignment (labelID);
}

void Conduit_labelSetAlignment (WidgetID labelID, long value)
{
	sharedCallPropagator->labelSetAlignment (labelID, value);
}

long Conduit_labelIndent (WidgetID labelID)
{
	return sharedCallPropagator->labelIndent (labelID);
}

void Conduit_labelSetIndent (WidgetID labelID, long value)
{
	sharedCallPropagator->labelSetIndent (labelID, value);
}

long Conduit_labelMargin (WidgetID labelID)
{
	return sharedCallPropagator->labelMargin (labelID);
}

void Conduit_labelSetMargin (WidgetID labelID, long value)
{
	sharedCallPropagator->labelSetMargin (labelID, value);
}

void Conduit_labelSetPixmap (WidgetID labelID, ObjectID pixmapID)
{
	sharedCallPropagator->labelSetPixmap (labelID, pixmapID);
}

void Conduit_labelSetImage (WidgetID labelID, ObjectID imageID)
{
	sharedCallPropagator->labelSetImage (labelID, imageID);
}

//--------------------
// QAbstractButton
//--------------------
const char *Conduit_abstractButtonText (WidgetID widgetID)
{
	return sharedCallPropagator->abstractButtonText (widgetID);
}

void Conduit_abstractButtonSetText (WidgetID widgetID, const char *text)
{
	sharedCallPropagator->abstractButtonSetText (widgetID, text);
}

bool Conduit_abstractButtonIsChecked (WidgetID widgetID)
{
	return sharedCallPropagator->abstractButtonIsChecked (widgetID);
}

void Conduit_abstractButtonSetChecked (WidgetID widgetID, bool value)
{
	sharedCallPropagator->abstractButtonSetChecked (widgetID, value);
}

//--------------------
// QPushButton
//--------------------
WidgetID Conduit_pushButtonNew (WidgetID parent, const char *text)
{
	return sharedCallPropagator->pushButtonNew (parent, text);
}

bool Conduit_pushButtonIsFlat (WidgetID widgetID)
{
	return sharedCallPropagator->pushButtonIsFlat (widgetID);
}

void Conduit_pushButtonSetFlat (WidgetID widgetID, bool value)
{
	sharedCallPropagator->pushButtonSetFlat (widgetID, value);
}

bool Conduit_pushButtonIsDefault (WidgetID widgetID)
{
	return sharedCallPropagator->pushButtonIsDefault (widgetID);
}

void Conduit_pushButtonSetDefault (WidgetID widgetID, bool value)
{
	sharedCallPropagator->pushButtonSetDefault (widgetID, value);
}

//--------------------
// QRadioButton
//--------------------
WidgetID Conduit_radioButtonNew (WidgetID parent, const char *text)
{
	return sharedCallPropagator->radioButtonNew (parent, text);
}

//--------------------
// QCheckBox
//--------------------
WidgetID Conduit_checkBoxNew (WidgetID parent, const char *text)
{
	return sharedCallPropagator->checkBoxNew (parent, text);
}

bool Conduit_checkBoxIsTristate (WidgetID widgetID)
{
	return sharedCallPropagator->checkBoxIsTristate (widgetID);
}

void Conduit_checkBoxSetTristate (WidgetID widgetID, bool value)
{
	sharedCallPropagator->checkBoxSetTristate (widgetID, value);
}

long Conduit_checkBoxCheckState (WidgetID widgetID)
{
	return sharedCallPropagator->checkBoxCheckState (widgetID);
}

void Conduit_checkBoxSetCheckState (WidgetID widgetID, long value)
{
	sharedCallPropagator->checkBoxSetCheckState (widgetID, value);
}

//--------------------
// QTextEdit
//--------------------
WidgetID Conduit_textEditNew (WidgetID parent)
{
	return sharedCallPropagator->textEditNew (parent);
}

void Conduit_textEditSetText (WidgetID widgetID, const char *text)
{
	sharedCallPropagator->textEditSetText (widgetID, text);
}

void Conduit_textEditSetAcceptRichText (WidgetID widgetID, bool accepts)
{
	sharedCallPropagator->textEditSetAcceptRichText (widgetID, accepts);
}

const char *Conduit_textEditToPlainText (WidgetID widgetID)
{
	return sharedCallPropagator->textEditToPlainText (widgetID);
}

const char *Conduit_textEditToHTML (WidgetID widgetID)
{
	return sharedCallPropagator->textEditToHTML (widgetID);
}

//--------------------
// QLineEdit
//--------------------
const char *Conduit_lineEditText (WidgetID widgetID)
{
	return sharedCallPropagator->lineEditText (widgetID);
}

void Conduit_lineEditSetText (WidgetID widgetID, const char *text)
{
	sharedCallPropagator->lineEditSetText (widgetID, text);
}

WidgetID Conduit_lineEditNew (WidgetID parent)
{
	return sharedCallPropagator->lineEditNew (parent);
}

//--------------------
// QTableWidgetItem
//--------------------
ObjectID Conduit_tableWidgetItemNew (const char *text)
{
	return sharedCallPropagator->tableWidgetItemNew (text);
}

const char *Conduit_tableWidgetItemText (ObjectID itemID)
{
	return sharedCallPropagator->tableWidgetItemText (itemID);
}

void Conduit_tableWidgetItemSetText (ObjectID itemID, const char* text)
{
	sharedCallPropagator->tableWidgetItemSetText (itemID, text);
}

void Conduit_tableWidgetItemSetForeground (ObjectID itemID, SQColor color)
{
	sharedCallPropagator->tableWidgetItemSetForeground (itemID, color);
}

void Conduit_tableWidgetItemSetBackground (ObjectID itemID, SQColor color)
{
	sharedCallPropagator->tableWidgetItemSetBackground (itemID, color);
}

//--------------------
// QTableWidget
//--------------------
WidgetID Conduit_tableWidgetNew (WidgetID parent)
{
	return sharedCallPropagator->tableWidgetNew (parent);
}

void Conduit_tableWidgetInsertColumn (WidgetID tableID, long column)
{
	sharedCallPropagator->tableWidgetInsertColumn (tableID, column);
}

void Conduit_tableWidgetInsertRow (WidgetID tableID, long row)
{
	sharedCallPropagator->tableWidgetInsertRow (tableID, row);
}

long Conduit_tableWidgetColumnCount (WidgetID table) {
	return sharedCallPropagator->tableWidgetColumnCount (table);
}

void Conduit_tableWidgetSetColumnCount (WidgetID tableID, long count) {
	sharedCallPropagator->tableWidgetSetColumnCount (tableID, count);
}

long Conduit_tableWidgetRowCount (WidgetID table) {
	return sharedCallPropagator->tableWidgetRowCount (table);
}

void Conduit_tableWidgetSetRowCount (WidgetID tableID, long count) {
	return sharedCallPropagator->tableWidgetSetRowCount (tableID, count);
}

long Conduit_tableWidgetCurrentColumn (WidgetID table) {
	return sharedCallPropagator->tableWidgetCurrentColumn (table);
}

long Conduit_tableWidgetCurrentRow (WidgetID table) {
	return sharedCallPropagator->tableWidgetCurrentRow (table);
}

void Conduit_tableWidgetSetCurrentCell (WidgetID tableID, long row, long column) {
	return sharedCallPropagator->tableWidgetSetCurrentCell (tableID, row, column);
}

ObjectID Conduit_tableWidgetItem (WidgetID tableID, long row, long column) {
	return sharedCallPropagator->tableWidgetItem (tableID, row, column);
}

void Conduit_tableWidgetSetItem (WidgetID tableID, long row, long column, ObjectID itemID) {
	sharedCallPropagator->tableWidgetSetItem (tableID, row, column, itemID);
}

ObjectID Conduit_tableWidgetCurrentItem (WidgetID table) {
	return sharedCallPropagator->tableWidgetCurrentItem (table);
}

WidgetID Conduit_tableWidgetCellWidget (WidgetID tableID, long row, long column) {
	return sharedCallPropagator->tableWidgetCellWidget (tableID, row, column);
}

void Conduit_tableWidgetSetCellWidget (WidgetID tableID, long row, long column, WidgetID widgetID) {
	sharedCallPropagator->tableWidgetSetCellWidget (tableID, row, column, widgetID);
}

void Conduit_tableWidgetSetVerticalHeaderLabel (WidgetID tableID, const char *string, bool is_last)
{
	sharedCallPropagator->tableWidgetSetVerticalHeaderLabel (tableID, string, is_last);
}

void Conduit_tableWidgetSetHorizontalHeaderLabel (WidgetID tableID, const char *string, bool is_last)
{
	sharedCallPropagator->tableWidgetSetHorizontalHeaderLabel (tableID, string, is_last);
}

//--------------------
// QWebEngineView
//--------------------
WidgetID Conduit_webEngineViewNew (WidgetID parent)
{
	return sharedCallPropagator->webEngineViewNew (parent);
}

void Conduit_webEngineViewSetHTML (WidgetID widgetID, const char *text)
{
	sharedCallPropagator->webEngineViewSetHTML (widgetID, text);
}

//--------------------
// QLCDNumber
//--------------------
WidgetID Conduit_lcdNumberNew (WidgetID widgetID, long numDigits) {
	return sharedCallPropagator->lcdNumberNew (widgetID, numDigits);
}

void Conduit_lcdNumberSetHexMode (WidgetID widgetID) {
	sharedCallPropagator->lcdNumberSetHexMode (widgetID);
}

void Conduit_lcdNumberSetBinMode (WidgetID widgetID) {
	sharedCallPropagator->lcdNumberSetBinMode (widgetID);
}

void Conduit_lcdNumberSetDecMode (WidgetID widgetID) {
	sharedCallPropagator->lcdNumberSetDecMode (widgetID);
}

void Conduit_lcdNumberSetOctMode (WidgetID widgetID) {
	sharedCallPropagator->lcdNumberSetOctMode (widgetID);
}

double Conduit_lcdNumberValue (WidgetID widgetID) {
	return sharedCallPropagator->lcdNumberValue (widgetID);
}

long Conduit_lcdNumberIntValue (WidgetID widgetID) {
	return sharedCallPropagator->lcdNumberIntValue (widgetID);
}

long Conduit_lcdNumberDigitCount (WidgetID widgetID) {
	return sharedCallPropagator->lcdNumberDigitCount (widgetID);
}

void Conduit_lcdNumberDisplayInt (WidgetID widgetID, long value) {
	sharedCallPropagator->lcdNumberDisplayInt (widgetID, value);
}

void Conduit_lcdNumberDisplayDouble (WidgetID widgetID, double value) {
	sharedCallPropagator->lcdNumberDisplayDouble (widgetID, value);
}

bool Conduit_lcdNumberSmallDecimalPoint (WidgetID widgetID) {
	return sharedCallPropagator->lcdNumberSmallDecimalPoint (widgetID);
}

void Conduit_lcdNumberSetSmallDecimalPoint (WidgetID widgetID, bool value) {
	sharedCallPropagator->lcdNumberSetSmallDecimalPoint (widgetID, value);
}

//-----------------------------------------------------------------------------
// QScreen
//-----------------------------------------------------------------------------
long Conduit_primaryScreenLogicalDotsPerInch() {
	return sharedCallPropagator->primaryScreenLogicalDotsPerInch();
}

long Conduit_primaryScreenWidth () {
	return sharedCallPropagator->primaryScreenWidth();
}

long Conduit_primaryScreenHeight () {
	return sharedCallPropagator->primaryScreenHeight ();
}

//-----------------------------------------------------------------------------
// QApplication
//-----------------------------------------------------------------------------
ObjectID Conduit_applicationNew (long argc, char *argv[]) 
{
	ensure_call_propagator_exists();
	return sharedCallPropagator->applicationNew(argc, argv);
}

void Conduit_applicationExec()
{
	ensure_call_propagator_exists();
	QApplication::exec();
}

void Conduit_applicationQuit ()
{
	QApplication::quit ();
}

void Conduit_applicationBeep()
{
#ifdef __linux__
	if (!system ("which ffplay > /dev/null")) {
		system ("ffplay -nodisp -autoexit /usr/share/sounds/freedesktop/stereo/bell.oga 2> /dev/null");
	} else {
		QApplication::beep();
	}
#else
	QApplication::beep();
#endif
}

//-----------------------------------------------------------------------------
// C++ Code that is called by the C "conduit" code.
//-----------------------------------------------------------------------------

CallPropagator::CallPropagator() 
{
}

CallPropagator::~CallPropagator()
{
	widgets.clear();
	objects.clear();
}

//--------------------
// QLayout
//--------------------
void CallPropagator::layoutAddWidget (ObjectID layoutID, WidgetID subwidgetID)
{
	QLayout *layout = (QLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	QWidget *subwidget = widgets[subwidgetID];
	if (!subwidget) {
		return;
	}
	layout->addWidget (subwidget);
}

void CallPropagator::layoutRemoveWidget (ObjectID layoutID, WidgetID subwidgetID)
{
	QLayout *layout = (QLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	QWidget *subwidget = widgets[subwidgetID];
	if (!subwidget) {
		return;
	}
	layout->removeWidget (subwidget);
}

long CallPropagator::layoutSpacing (ObjectID layoutID)
{
	QLayout *layout = (QLayout*) objects[layoutID];
	if (!layout) {
		return 0;
	}
	return layout->spacing();
}

void CallPropagator::layoutSetSpacing (ObjectID layoutID, long spacing)
{
	QLayout *layout = (QLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	layout->setSpacing(spacing);
}

//--------------------
// QBoxLayout
//--------------------
ObjectID CallPropagator::boxLayoutNew (WidgetID parentID, long direction)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}
	QBoxLayout::Direction dir;
	switch (direction) {
	case 0: dir = QBoxLayout::LeftToRight; break;
	case 1: dir = QBoxLayout::RightToLeft; break;
	default:
	case 2: dir = QBoxLayout::TopToBottom; break;
	case 3: dir = QBoxLayout::BottomToTop; break;
	}
	QBoxLayout *layout = new QBoxLayout (dir, parent);
	int layoutID = widgetObjectCounter++;
	objects[layoutID] = (QObject*) layout;

	connect (layout, &QBoxLayout::destroyed, this, [this, layoutID]() {
		objectDestroyed(layoutID);
	});

	return layoutID;
}

void CallPropagator::boxLayoutAddWidget (WidgetID layoutID, WidgetID subwidgetID, int stretch, int value)
{
	QBoxLayout *layout = (QBoxLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	QWidget *subwidget = widgets[subwidgetID];
	if (!subwidget) {
		return;
	}

	Qt::Alignment alignment;
	if (value & 1) alignment |= Qt::AlignLeft;
	if (value & 2) alignment |= Qt::AlignRight;
	if (value & 4) alignment |= Qt::AlignCenter;
	if (value & 8) alignment |= Qt::AlignJustify;
	if (value & 0x20) alignment |= Qt::AlignTop;
	if (value & 0x40) alignment |= Qt::AlignBottom;
	if (value & 0x80) alignment |= Qt::AlignVCenter;
	if (value & 0x100) alignment |= Qt::AlignBaseline;

	layout->addWidget (subwidget, stretch, alignment);
}

void CallPropagator::boxLayoutAddSpacing (ObjectID layoutID, long value)
{
	QBoxLayout *layout = (QBoxLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	layout->addSpacing (value);
}

void CallPropagator::boxLayoutAddStretch (ObjectID layoutID, long value)
{
	QBoxLayout *layout = (QBoxLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	layout->addStretch (value);
}

void CallPropagator::boxLayoutAddStrut (ObjectID layoutID, long value)
{
	QBoxLayout *layout = (QBoxLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	layout->addStrut (value);
}

//--------------------
// QHBoxLayout
//--------------------
ObjectID CallPropagator::hBoxLayoutNew (WidgetID parentID)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}
	QHBoxLayout *layout = new QHBoxLayout (parent);
	int layoutID = widgetObjectCounter++;
	objects[layoutID] = (QObject*) layout;

	connect (layout, &QHBoxLayout::destroyed, this, [this, layoutID]() {
		objectDestroyed(layoutID);
	});

	return layoutID;
}

//--------------------
// QVBoxLayout
//--------------------
ObjectID CallPropagator::vBoxLayoutNew (WidgetID parentID)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}
	QVBoxLayout *layout = new QVBoxLayout (parent);
	int layoutID = widgetObjectCounter++;
	objects[layoutID] = (QObject*) layout;

	connect (layout, &QVBoxLayout::destroyed, this, [this, layoutID]() {
		objectDestroyed(layoutID);
	});

	return layoutID;
}

//--------------------
// QPixmap
//--------------------
ObjectID CallPropagator::pixmapWithPathNew (const char* path)
{
	QPixmap *pixmap;
	if (path && *path) {
		QString qpath(path);
		pixmap = new QPixmap(qpath);
	} else {
		pixmap = new QPixmap();
	}

	int objectID = widgetObjectCounter++;
	objects[objectID] = (QObject*) pixmap;

#if 0
	// Need wrapper class or cleanup function
	connect (pixmap, &QPixmap::destroyed, this, [this, objectID]() {
		objectDestroyed(objectID);
	});
#endif

	return objectID;
}

ObjectID CallPropagator::pixmapWithSizeNew (SQCoord width, SQCoord height)
{
	QPixmap *pixmap;
	if (width > 0 && height > 0) {
		pixmap = new QPixmap(width, height);
	} else {
		pixmap = new QPixmap();
	}
	int objectID = widgetObjectCounter++;
	objects[objectID] = (QWidget*) pixmap;

#if 0
	// Need wrapper class or cleanup function
	connect (pixmap, &QPixmap::destroyed, this, [this, objectID]() {
		objectDestroyed(objectID);
	});
#endif

	return objectID;
}

bool CallPropagator::pixmapLoad (ObjectID objectID, const char *path)
{
	QPixmap *pixmap = (QPixmap*)objects[objectID];
	if (!pixmap) {
		return false;
	}

	bool result = false;
	if (path) {
		QString qpath(path);
		result = pixmap->load (qpath);
	}
	return result;
}

SQCoord CallPropagator::pixmapWidth (ObjectID objectID)
{
	QPixmap *pixmap = (QPixmap*)objects[objectID];
	if (!pixmap) {
		return false;
	}
	return pixmap->width();
}

SQCoord CallPropagator::pixmapHeight (ObjectID objectID)
{
	QPixmap *pixmap = (QPixmap*)objects[objectID];
	if (!pixmap) {
		return false;
	}
	return pixmap->height ();
}

SQCoord CallPropagator::pixmapDepth (ObjectID objectID)
{
	QPixmap *pixmap = (QPixmap*)objects[objectID];
	if (!pixmap) {
		return false;
	}
	return pixmap->depth();
}

//--------------------
// QImage
//--------------------
ObjectID CallPropagator::imageNew (const char* path)
{
	QImage *image;
	if (path && *path) {
		QString qpath(path);
		image = new QImage(qpath);
	} else {
		image = new QImage();
	}
	int objectID = widgetObjectCounter++;
	objects[objectID] = (QWidget*) image;

#if 0
	// Need wrapper class or cleanup function
	connect (image, &QImage::destroyed, this, [this, objectID]() {
		objectDestroyed(objectID);
	});
#endif

	return objectID;
}

bool CallPropagator::imageLoad (ObjectID objectID, const char *path)
{
	QImage *image = (QImage*)objects[objectID];
	if (!image) {
		return false;
	}

	bool result = false;
	if (path) {
		QString qpath(path);
		result = image->load (qpath);
	}
	return result;
}

bool CallPropagator::imageIsGrayscale (ObjectID objectID)
{
	QImage *image = (QImage*)objects[objectID];
	if (!image) {
		return false;
	}
	return image->isGrayscale();
}

SQCoord CallPropagator::imageWidth (ObjectID objectID)
{
	QImage *image = (QImage*)objects[objectID];
	if (!image) {
		return false;
	}
	return image->width();
}

SQCoord CallPropagator::imageHeight (ObjectID objectID)
{
	QImage *image = (QImage*)objects[objectID];
	if (!image) {
		return false;
	}
	return image->height ();
}

SQCoord CallPropagator::imageDepth (ObjectID objectID)
{
	QImage *image = (QImage*)objects[objectID];
	if (!image) {
		return false;
	}
	return image->depth();
}

//--------------------
// Conveniences
//--------------------
void CallPropagator::conveniencePopup (const char* title, const char* message)
{
	QMessageBox messageBox;
	messageBox.information (nullptr, title ?: "", message ?: "");
}

bool CallPropagator::yesnoQuestion (const char *title, const char *question)
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question (nullptr, title, question, QMessageBox::Yes | QMessageBox::No);
	return reply == QMessageBox::Yes;
}

//--------------------
// QGroupBox
//--------------------
WidgetID CallPropagator::groupBoxNew (WidgetID parentID, const char* title)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}
	QGroupBox *widget = new QGroupBox(title, parent);
	int widgetID = widgetObjectCounter++;
	widgets[widgetID] = (QWidget*) widget;

	connect (widget, &QGroupBox::destroyed, this, [this, widgetID]() {
		widgetDestroyed(widgetID);
	});

	return widgetID;
}

long CallPropagator::groupBoxAlignment (WidgetID widgetID)
{
	QGroupBox *widget = (QGroupBox*) widgets[widgetID];
	if (!widget) {
		return 0;
	}
	return (long)widget->alignment ();
}

void CallPropagator::groupBoxSetAlignment (WidgetID widgetID, long value)
{
	QGroupBox *widget = (QGroupBox*) widgets[widgetID];
	if (!widget) {
		return;
	}

	Qt::Alignment alignment;
	if (value & 1) alignment |= Qt::AlignLeft;
	if (value & 2) alignment |= Qt::AlignRight;
	if (value & 4) alignment |= Qt::AlignCenter;
	if (value & 8) alignment |= Qt::AlignJustify;
	if (value & 0x20) alignment |= Qt::AlignTop;
	if (value & 0x40) alignment |= Qt::AlignBottom;
	if (value & 0x80) alignment |= Qt::AlignVCenter;
	if (value & 0x100) alignment |= Qt::AlignBaseline;

	widget->setAlignment (alignment);
}

const char* CallPropagator::groupBoxTitle (WidgetID widgetID)
{
	QGroupBox *widget = (QGroupBox*) widgets[widgetID];
	if (!widget) {
		return NULL;
	}
	QString title = widget->title();
	std::string string = title.toStdString();
	const char *cstring = string.c_str();
	char *copy = strdup(cstring);
	return copy;
}

void CallPropagator::groupBoxSetTitle (WidgetID widgetID, const char* string)
{
	QGroupBox *widget = (QGroupBox*) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setTitle (string ?: "");
}

//--------------------
// QWidget
//--------------------
WidgetID CallPropagator::widgetNew (WidgetID parentID)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}
	QWidget *widget = new QWidget (parent);

	int index = widgetObjectCounter++;
	widgets[index] = widget;

	connect (widget, &QWidget::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

void CallPropagator::move (WidgetID widgetID, SQCoord x, SQCoord y) 
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->move (x, y);
}

void CallPropagator::resize (WidgetID widgetID, SQCoord width, SQCoord height) 
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->resize (width, height);
}

void CallPropagator::setHidden (WidgetID widgetID, bool value)
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setHidden (value);
}

bool CallPropagator::isHidden (WidgetID widgetID)
{
	QWidget *widget = widgets[widgetID];
	if (widget) {
		return widget->isHidden();
	}
	return false;
}

void CallPropagator::setFrame (WidgetID widgetID, SQRect rect)
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->move (rect.origin.x, rect.origin.y);
	widget->resize (rect.size.width, rect.size.height);

	//printf("Qt: %s %s to %ld,%ld %ldx%ld\n", typeid(widget).name(), __FUNCTION__, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
}

void CallPropagator::setMinimumSize (WidgetID widgetID, SQSize size)
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}
	QSize qsize;
	qsize.setWidth (size.width);
	qsize.setHeight (size.height);
	widget->setMinimumSize (qsize);
}

SQSize CallPropagator::minimumSize (WidgetID widgetID)
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		SQSize zerosize = {0, 0};
		return zerosize;
	}
	QSize qsize = widget->minimumSize ();
	SQSize size;
	size.width = qsize.width();
	size.height = qsize.height ();
	return size;
}

WidgetID CallPropagator::parentWidget (WidgetID widgetID)
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return -1;
	}
	QWidget *parent = widget->parentWidget ();
	if (!parent) {
		return -1;
	}
	WidgetID parentID = lookupOrAddWidget (parent);
	return parentID;
}

void CallPropagator::setParent (WidgetID widgetID, WidgetID parentID)
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}
	if (parentID < 0) {
		widget->setParent (NULL);
		return;
	}
	QWidget *parent = widgets[widgetID];
	if (!parent) {
		return;
	}
	widget->setParent (parent);
}

SQCoord CallPropagator::width (WidgetID widgetID)
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return 0;
	}
	return widget->width();
}

SQCoord CallPropagator::height (WidgetID widgetID)
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return 0;
	}
	return widget->height ();
}

void CallPropagator::setStyleSheet (WidgetID widgetID, const char*string)
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setStyleSheet (string);
}

const char *CallPropagator::styleSheet (WidgetID widgetID)
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return NULL;
	}

	QString text = widget->styleSheet ();
	std::string string = text.toStdString();
	const char *cstring = string.c_str();
	char *copy = strdup(cstring);
	return copy;
}

void CallPropagator::raise (WidgetID widgetID)
{
	QWidget *widget = widgets[widgetID];
	if (widget) {
		widget->raise();
	}
}

void CallPropagator::lower (WidgetID widgetID)
{
	QWidget *widget = widgets[widgetID];
	if (widget) {
		widget->lower();
	}
}

WidgetID CallPropagator::layout (WidgetID widgetID)
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return -1;
	}
	QLayout *layout = widget->layout ();
	ObjectID layoutID = lookupOrAddObject ((QObject*)layout);
	return layoutID;
}

void CallPropagator::setLayout (WidgetID widgetID, WidgetID layoutID)
{
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}
	QLayout *layout = (QLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	widget->setLayout (layout);
}

SQRect CallPropagator::frame (WidgetID widgetID)
{
	QWidget *widget = widgets[widgetID];
	SQRect rect;
	if (!widget) {
		rect.origin.x = 0;
		rect.origin.y = 0;
		rect.size.width = 0;
		rect.size.height = 0;
		return rect;
	}
	rect.origin.x = widget->x();
	rect.origin.y = widget->y();
	rect.size.width = widget->width();
	rect.size.height = widget->height ();

	//printf("Qt: %s %s: %ld,%ld %ldx%ld\n", typeid(widget).name(), __FUNCTION__, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
	return rect;
}

void CallPropagator::setMaximumHeight (WidgetID widgetID, long value) {
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setMaximumHeight (value);
}

void CallPropagator::setMaximumWidth (WidgetID widgetID, long value) {
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setMaximumWidth(value);
}

void CallPropagator::setMinimumHeight (WidgetID widgetID, long value) {
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setMinimumHeight (value);
}

void CallPropagator::setMinimumWidth (WidgetID widgetID, long value) {
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setMinimumWidth(value);
}

//--------------------
// QMainWindow
//--------------------
QMainWindow *CallPropagator::lookupWindow (WidgetID windowID)
{
	QWidget *ptr = widgets[windowID];
	if (!ptr) {
		return nullptr;
	}
	return dynamic_cast<QMainWindow*>(ptr);
}

WidgetID CallPropagator::windowNew (SQCoord x, SQCoord y, SQCoord width, SQCoord height)
{
	QMainWindow *window = new QMainWindow();
	int windowID = widgetObjectCounter++;
	widgets[windowID] = (QWidget*) window;
	window->setMinimumSize(width, height);
	window->move(x, y);

	connect (window, &QMainWindow::destroyed, this, [this, windowID]() {
		widgetDestroyed(windowID);
	});

	// Ensure that closing a window deletes it.
	// TODO: Ensure that all Swift objects associated with it
	// are also destroyed.
	window->setAttribute (Qt::WA_DeleteOnClose);

	// RULE: Rather than subclass QMainWindow to receive the resize events
	// and send them to the Swift side, add an event filter to capture events
	// and send them from the filter.
	//
	EventFilter *filter = new EventFilter();
	window->installEventFilter (filter);

	return windowID;
}

const char *CallPropagator::windowTitle (WidgetID widgetID)
{
	QMainWindow *window = (QMainWindow *) widgets[widgetID];
	if (!window) {
		return NULL;
	}

	QString text = window->windowTitle();
	std::string string = text.toStdString();
	const char *cstring = string.c_str();
	char *copy = strdup(cstring);
	return copy;
}

void CallPropagator::windowClose (WidgetID widgetID)
{
	QMainWindow *window = (QMainWindow *) widgets[widgetID];
	if (!window) {
		return;
	}
	window->close();

	// NOTE: Can't call destroy() because that's protected.
	// In addition, destroy() deallocates other resources on the C++ side
	// which would be difficult to replicate on the Swift side.
}

void CallPropagator::windowSetTitle (WidgetID widgetID, const char *text)
{
	QMainWindow *window = (QMainWindow *) widgets[widgetID];
	if (!window) {
		return;
	}

	window->setWindowTitle(text);
}

void CallPropagator::windowSetMinimumSize (WidgetID windowID, SQCoord width, SQCoord height)
{
	QMainWindow *window = lookupWindow (windowID);
	if (window) {
		window->setMinimumSize (width, height);
	}
}

void CallPropagator::windowSetMaximumSize (WidgetID windowID, SQCoord width, SQCoord height)
{
	QMainWindow *window = lookupWindow (windowID);
	if (window) {
		window->setMaximumSize (width, height);
	}
}

SQCoord CallPropagator::windowWidth (WidgetID windowID) 
{
	QMainWindow *window = lookupWindow (windowID);
	return window? window->width() : 0;
}

SQCoord CallPropagator::windowHeight (WidgetID windowID) 
{
	QMainWindow *window = lookupWindow (windowID);
	return window? window->height () : 0;
}

void CallPropagator::windowSetStatusBar (WidgetID windowID, WidgetID statusBarID)
{
	QMainWindow *window = lookupWindow (windowID);
	QStatusBar *statusBar = (QStatusBar*) widgets[statusBarID];
	if (window) {
		window->setStatusBar (statusBar); // statusBar can be nullptr.
	}
}

void CallPropagator::windowSetMenuBar (WidgetID windowID, WidgetID menuBarID)
{
	QMainWindow *window = lookupWindow (windowID);
	QMenuBar *menuBar = (QMenuBar*) widgets[menuBarID];
	if (window && menuBar) {
		window->setMenuBar (menuBar);
	}
}

void CallPropagator::windowSetCentralWidget (WidgetID windowID, WidgetID widgetID)
{
	QMainWindow *window = lookupWindow (windowID);
	if (!window) {
		return;
	}
	QWidget *widget = (QWidget*) widgets[widgetID];
	if (!widget) {
		return;
	}
	window->setCentralWidget (widget);
}

/* This just returns the first window.
 */
QMainWindow *CallPropagator::mainWindow ()
{
	for (const auto & [key, value] : widgets) {
		QWidget *widget = value;
		if (dynamic_cast<QMainWindow*>(widget)) {
			return (QMainWindow*) widget;
		}
	}
	return NULL;
}

long Conduit_applicationTotalMainWindows ()
{
	long count = 0;

	for (const auto value : QApplication::topLevelWidgets()) {
		QWidget *widget = value;
		if (dynamic_cast<QMainWindow*>(widget)) {
			count++;
		}
	}
	return count;
}

//--------------------
// QStatusBar
//--------------------
void CallPropagator::statusBarShowMessage (WidgetID statusBarID, const char *text, long duration)
{
	QStatusBar *statusBar = (QStatusBar*) widgets[statusBarID];
	if (statusBar) {
		statusBar->showMessage (text ?: "", duration);
	} 
}

WidgetID CallPropagator::statusBarNew (WidgetID parentID, const char *text)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}

	//printf("Qt: STATUS BAR TEXT=%s\n",text);

	QStatusBar *statusBar = new QStatusBar (parent);
	if (text) {
		statusBar->showMessage (text);
	} 
	int index = widgetObjectCounter++;
	widgets[index] = statusBar;

	connect (statusBar, &QStatusBar::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

//--------------------
// QAction
//--------------------
ObjectID CallPropagator::actionNew (const char* text = nullptr)
{
	QAction *action = new QAction (text ?: "");
	int index = widgetObjectCounter++;
	objects[index] = (QObject*)action;

	connect (action, &QAction::triggered, this, [index]() {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalActionTriggered;
		event.recipient = index;
		swiftEventHandler (event);
	});

	connect (action, &QAction::destroyed, this, [this, index]() {
		objectDestroyed(index);
	});

	return index;
}

void CallPropagator::actionSetShortcut (ObjectID actionID, SQKeySequence sequenceString)
{
	if (!sequenceString) {
		return;
	}
	QAction *action = (QAction*) objects[actionID];
	if (!action) {
		return;
	}

	QKeySequence sequence (sequenceString);
	action->setShortcut (sequence);
}

//--------------------
// QMenuBar
//--------------------
WidgetID CallPropagator::menuBarNew ()
{
	QMenuBar *menubar = new QMenuBar ();
	int index = widgetObjectCounter++;
	widgets[index] = menubar;

	connect (menubar, &QMenuBar::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

void CallPropagator::menuBarAddMenu (WidgetID menubarID, WidgetID menuID)
{
	QMenuBar *menubar = (QMenuBar*) widgets[menubarID];
	if (!menubar) {
		return;
	}
	QMenu *menu = (QMenu*) widgets[menuID];
	if (!menu) {
		return;
	}

	menubar->addMenu(menu);
}

//--------------------
// QMenu
//--------------------
WidgetID CallPropagator::menuNew (const char *title)
{
	QMenu *menu = new QMenu (title);
	int index = widgetObjectCounter++;
	widgets[index] = menu;

	connect (menu, &QMenu::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

void CallPropagator::menuAddAction (WidgetID widgetID, ObjectID actionID)
{
	QMenu *menu = (QMenu*) widgets[widgetID];
	if (!menu) {
		return;
	}
	QAction *action = (QAction*) objects[actionID];
	if (!action) {
		return;
	}
	menu->addAction(action);
}

void CallPropagator::menuAddSeparator (WidgetID widgetID)
{
	QMenu *menu = (QMenu*) widgets[widgetID];
	if (!menu) {
		return;
	}
	menu->addSeparator();
}

const char *CallPropagator::menuTitle (WidgetID widgetID)
{
	QMenu *menu = (QMenu*) widgets[widgetID];
	if (!menu) {
		return NULL;
	}

	QString title = menu->title();
	std::string string = title.toStdString();
	const char *cstring = string.c_str();
	char *copy = strdup(cstring);
	return copy;
}

void CallPropagator::menuSetTitle (WidgetID widgetID, const char *title)
{
	QMenu *menu = (QMenu*) widgets[widgetID];
	if (!menu) {
		return;
	}

	menu->setTitle (title ?: "");
}

//--------------------
// QLabel
//--------------------
WidgetID CallPropagator::labelNew (WidgetID parentID, const char *text)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}

	QLabel *label = new QLabel (parent);
	if (text) {
		label->setText (text ?: "");
	} 
	int index = widgetObjectCounter++;
	widgets[index] = label;

	connect (label, &QLabel::linkHovered, this, [index, label]() {
		(void)label;
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalLabelHovered;
		event.recipient = index;
		swiftEventHandler (event);
	});

	connect (label, &QLabel::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

void CallPropagator::labelClear (WidgetID labelID)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return;
	}
	label->clear();
}
const char* CallPropagator::labelText (WidgetID labelID)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return NULL;
	}
	QString text = label->text ();
	std::string string = text.toStdString();
	const char *cstring = string.c_str();
	char *copy = strdup(cstring);
	return copy;
}
void CallPropagator::labelSetText (WidgetID labelID, const char*string)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return;
	}
	label->setText (string ?: "");
}
bool CallPropagator::labelWordWrap (WidgetID labelID)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return false;
	}
	return label->wordWrap();
}
void CallPropagator::labelSetWordWrap (WidgetID labelID, bool value)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return;
	}
	label->setWordWrap (value);
}

long CallPropagator::labelAlignment (WidgetID labelID)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return 0;
	}
	return (long)label->alignment ();
}

void CallPropagator::labelSetAlignment (WidgetID labelID, long value)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return;
	}

	Qt::Alignment alignment;
	if (value & 1) alignment |= Qt::AlignLeft;
	if (value & 2) alignment |= Qt::AlignRight;
	if (value & 4) alignment |= Qt::AlignCenter;
	if (value & 8) alignment |= Qt::AlignJustify;
	if (value & 0x20) alignment |= Qt::AlignTop;
	if (value & 0x40) alignment |= Qt::AlignBottom;
	if (value & 0x80) alignment |= Qt::AlignVCenter;
	if (value & 0x100) alignment |= Qt::AlignBaseline;

	label->setAlignment (alignment);
}

long CallPropagator::labelIndent (WidgetID labelID)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return 0;
	}
	return label->indent ();
}

long CallPropagator::labelMargin (WidgetID labelID)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return 0;
	}
	return label->margin();
}

void CallPropagator::labelSetIndent (WidgetID labelID, long value)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return;
	}
	label->setIndent (value);
}

void CallPropagator::labelSetMargin (WidgetID labelID, long value)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return;
	}
	label->setMargin(value);
}

void CallPropagator::labelSetPixmap (WidgetID labelID, ObjectID pixmapID)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return;
	}
	QPixmap *pixmap = (QPixmap*) objects[pixmapID];
	if (!pixmap) {
		return;
	}
	label->setPixmap (*pixmap);
}

void CallPropagator::labelSetImage (WidgetID labelID, ObjectID imageID)
{
	QLabel *label = (QLabel*) widgets[labelID];
	if (!label) {
		return;
	}
	QImage *image = (QImage*) objects[imageID];
	if (!image) {
		return;
	}
	label->setPixmap (QPixmap::fromImage(*image));
}

//--------------------
// QAbstractButton
//--------------------
const char *CallPropagator::abstractButtonText (WidgetID widgetID)
{
	QAbstractButton *abstractButton = (QAbstractButton *) widgets[widgetID];
	if (!abstractButton) {
		return NULL;
	}

	QString text = abstractButton->text ();
	std::string string = text.toStdString();
	const char *cstring = string.c_str();
	char *copy = strdup(cstring);
	return copy;
}

void CallPropagator::abstractButtonSetText (WidgetID widgetID, const char *text)
{
	QAbstractButton *abstractButton = (QAbstractButton *) widgets[widgetID];
	if (!abstractButton) {
		return;
	}

	abstractButton->setText (text ?: "");
}

bool CallPropagator::abstractButtonIsChecked (WidgetID widgetID)
{
	QAbstractButton *abstractButton = (QAbstractButton *) widgets[widgetID];
	if (!abstractButton) {
		return false;
	}

	return abstractButton->isChecked();
}

void CallPropagator::abstractButtonSetChecked (WidgetID widgetID, bool value)
{
	QAbstractButton *abstractButton = (QAbstractButton *) widgets[widgetID];
	if (!abstractButton) {
		return;
	}

	abstractButton->setChecked(value);
}

//--------------------
// QRadioButton
//--------------------
WidgetID CallPropagator::radioButtonNew (WidgetID parentID, const char *text)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}

	QRadioButton *button = new QRadioButton (parent);
	if (text) {
		button->setText (text ?: "");
	} 

	int index = widgetObjectCounter++;
	widgets[index] = button;

	connect (button, &QRadioButton::toggled, this, [index]() {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalRadioButtonToggled;
		event.recipient = index;
		swiftEventHandler (event);
	});

	connect (button, &QRadioButton::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

//--------------------
// QCheckBox
//--------------------
WidgetID CallPropagator::checkBoxNew (WidgetID parentID, const char *text)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}

	QCheckBox *button = new QCheckBox (parent);
	if (text) {
		button->setText (text ?: "");
	} 

	int index = widgetObjectCounter++;
	widgets[index] = button;

	connect (button, &QCheckBox::stateChanged, this, [index]() {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalCheckBoxStateChanged;
		event.recipient = index;
		swiftEventHandler (event);
	});

	connect (button, &QCheckBox::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}
bool CallPropagator::checkBoxIsTristate (WidgetID widgetID)
{
	QCheckBox *checkbox = (QCheckBox *) widgets[widgetID];
	if (!checkbox) {
		return false;
	}

	return checkbox->isTristate();
}
void CallPropagator::checkBoxSetTristate (WidgetID widgetID, bool value)
{
	QCheckBox *checkbox = (QCheckBox *) widgets[widgetID];
	if (!checkbox) {
		return;
	}

	return checkbox->setTristate(value);
}
long CallPropagator::checkBoxCheckState (WidgetID widgetID)
{
	QCheckBox *checkbox = (QCheckBox *) widgets[widgetID];
	if (!checkbox) {
		return Qt::Unchecked;
	}

	return checkbox->checkState();
}
void CallPropagator::checkBoxSetCheckState (WidgetID widgetID, long value)
{
	QCheckBox *checkbox = (QCheckBox *) widgets[widgetID];
	if (!checkbox) {
		return;
	}
	Qt::CheckState state = Qt::Unchecked;
	if (value == 1) {
        	state = Qt::PartiallyChecked;
	} else if (value == 2) {
        	state = Qt::Checked;
	}

	return checkbox->setCheckState(state);
}

//--------------------
// QPushButton
//--------------------
WidgetID CallPropagator::pushButtonNew (WidgetID parentID, const char *text)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}

	// printf("Qt: BUTTON TEXT=%s\n",text);

	QPushButton *button = new QPushButton (parent);
	if (text) {
		button->setText (text ?: "");
	} 

	int index = widgetObjectCounter++;
	widgets[index] = button;

	connect (button, &QPushButton::clicked, this, [index]() {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalPushButtonClicked;
		event.recipient = index;
		swiftEventHandler (event);
	});

	connect (button, &QPushButton::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

bool CallPropagator::pushButtonIsFlat (WidgetID widgetID)
{
	QPushButton *pushButton = (QPushButton *) widgets[widgetID];
	if (!pushButton) {
		return false;
	}

	return pushButton->isFlat ();
}

void CallPropagator::pushButtonSetFlat (WidgetID widgetID, bool value)
{
	QPushButton *pushButton = (QPushButton *) widgets[widgetID];
	if (!pushButton) {
		return;
	}

	pushButton->setFlat (value);
}

bool CallPropagator::pushButtonIsDefault (WidgetID widgetID)
{
	QPushButton *pushButton = (QPushButton *) widgets[widgetID];
	if (!pushButton) {
		return false;
	}

	return pushButton->isDefault ();
}

void CallPropagator::pushButtonSetDefault (WidgetID widgetID, bool value)
{
	QPushButton *pushButton = (QPushButton *) widgets[widgetID];
	if (!pushButton) {
		return;
	}

	pushButton->setDefault (value);
}

//--------------------
// QTableWidget
//--------------------
WidgetID CallPropagator::tableWidgetNew (WidgetID parentID)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}

	QTableWidget *table = new QTableWidget (parent);

	int index = widgetObjectCounter++;
	widgets[index] = table;

	connect (table, &QTableWidget::cellChanged, this, [index](int row, int column) {
		//printf ("QTableWidget cellChanged\n");
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalTableCellChanged;
		event.x = column;
		event.y = row;
		event.recipient = index;
		swiftEventHandler (event);
	});
	connect (table, &QTableWidget::cellClicked, this, [index](int row, int column) {
		//printf ("QTableWidget cellClicked\n");
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalTableCellClicked;
		event.x = column;
		event.y = row;
		event.recipient = index;
		swiftEventHandler (event);
	});
	connect (table, &QTableWidget::cellDoubleClicked, this, [index](int row, int column) {
		//printf ("QTableWidget cellDoubleClicked\n");
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalTableCellDoubleClicked;
		event.x = column;
		event.y = row;
		event.recipient = index;
		swiftEventHandler (event);
	});
	connect (table, &QTableWidget::itemSelectionChanged, this, [index]() {
		//printf ("QTableWidget itemSelectionChanged\n");
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalTableItemSelectionChanged;
		event.recipient = index;
		swiftEventHandler (event);
	});
	connect (table, &QTableWidget::currentCellChanged, this, [index](int row, int column, int previousRow, int previousColumn) {
		//printf ("QTableWidget currentCellChanged\n");
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalTableCurrentCellChanged;
		event.x = column;
		event.y = row;
		event.previousColumn = previousColumn;
		event.previousRow = previousRow;
		event.recipient = index;
		swiftEventHandler (event);
	});

	connect (table, &QTableWidget::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

const char *CallPropagator::tableWidgetItemText (ObjectID itemID)
{
	QTableWidgetItem *item = (QTableWidgetItem *)objects[itemID];
	if (!item) {
		qDebug() << "tableWidgetItemText: No such QTableWidgetItem.";
		return NULL;
	}

	QString text = item->text ();
	std::string string = text.toStdString();
	const char *cstring = string.c_str();
	char *copy = strdup(cstring);
	return copy;
}

void CallPropagator::tableWidgetItemSetForeground (ObjectID itemID, SQColor color)
{
	QTableWidgetItem *item = (QTableWidgetItem *)objects[itemID];
	if (!item) {
		qDebug() << "tableWidgetItemText: No such QTableWidgetItem.";
		return;
	}
	QColor qcolor((int)((color>>16)&255), (int)((color>>8)&255), (int)(color&255), (int)((color>>24)&255));
	item->setForeground(qcolor);
}

void CallPropagator::tableWidgetItemSetBackground (ObjectID itemID, SQColor color)
{
	QTableWidgetItem *item = (QTableWidgetItem *)objects[itemID];
	if (!item) {
		qDebug() << "tableWidgetItemText: No such QTableWidgetItem.";
		return;
	}
	QColor qcolor((int)((color>>16)&255), (int)((color>>8)&255), (int)(color&255), (int)((color>>24)&255));
	item->setBackground(qcolor);
}

void CallPropagator::tableWidgetItemSetText (ObjectID itemID, const char* text)
{
	QTableWidgetItem *item = (QTableWidgetItem *)objects[itemID];
	if (!item) {
		qDebug() << "tableWidgetItemText: No such QTableWidgetItem.";
		return;
	}
	item->setText (text ?: "");
}

ObjectID CallPropagator::tableWidgetItemNew (const char *text)
{
	QTableWidgetItem *item = new QTableWidgetItem (text ?: "");
	if (item) {
		int index = widgetObjectCounter++;
		objects[index] = (QObject*) item;
		return index;
	} else {
		return -1;
	}
}

void CallPropagator::tableWidgetSetVerticalHeaderLabel (WidgetID tableID, const char *string, bool is_last)
{
	tableVerticalHeaderLabels.push_back(strdup(string) ?: "");

	// KLUDGE: The Swift side sends each string one by one,
	// need to update this to receive an array.

	if (!is_last) {
		return;
	}

	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		tableVerticalHeaderLabels.clear();
		return;
	}

	QStringList list;
	unsigned n = tableVerticalHeaderLabels.size();
	for (unsigned i=0; i < n; i++) {
		const char *label = tableVerticalHeaderLabels.front ();
		QString string = QString(label);
		list.append (string);
		tableVerticalHeaderLabels.pop_front ();
	}

	table->setVerticalHeaderLabels (list);

	tableVerticalHeaderLabels.clear();
}

void CallPropagator::tableWidgetSetHorizontalHeaderLabel (WidgetID tableID, const char *string, bool is_last)
{
	tableHorizontalHeaderLabels.push_back(strdup(string) ?: "");

	// KLUDGE: The Swift side sends each string one by one,
	// need to update this to receive an array.

	if (!is_last) {
		return;
	}

	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		tableHorizontalHeaderLabels.clear();
		return;
	}

	QStringList list;
	unsigned n = tableHorizontalHeaderLabels.size();
	for (unsigned i=0; i < n; i++) {
		const char *label = tableHorizontalHeaderLabels.front ();
		QString string = QString(label);
		list.append (string);
		tableHorizontalHeaderLabels.pop_front ();
	}

	table->setHorizontalHeaderLabels (list);

	tableHorizontalHeaderLabels.clear();
}

long CallPropagator::tableWidgetColumnCount (WidgetID tableID) {
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return 0;
	}

	return table->columnCount ();
}
void CallPropagator::tableWidgetInsertColumn (WidgetID tableID, long column) {
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return;
	}

	table->insertColumn (column);
}
void CallPropagator::tableWidgetInsertRow (WidgetID tableID, long row) {
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return;
	}

	table->insertRow (row);
}
void CallPropagator::tableWidgetSetColumnCount (WidgetID tableID, long count) {
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return;
	}

	table->setColumnCount (count);
}
long CallPropagator::tableWidgetRowCount (WidgetID tableID) {
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return 0;
	}

	return table->rowCount ();
}
void CallPropagator::tableWidgetSetRowCount (WidgetID tableID, long count) {
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return;
	}

	table->setRowCount (count);
}
long CallPropagator::tableWidgetCurrentColumn (WidgetID tableID) {
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return -1;
	}

	return table->currentColumn();
}
long CallPropagator::tableWidgetCurrentRow (WidgetID tableID) {
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return -1;
	}

	return table->currentRow();
}

void CallPropagator::tableWidgetSetCurrentCell (WidgetID tableID, long row, long column)
{
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return;
	}
	table->setCurrentCell (row, column);
}

void CallPropagator::tableWidgetSetCellWidget (WidgetID tableID, long row, long column, WidgetID widgetID) 
{
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return;
	}

	QWidget *widget = (QWidget*) widgets[widgetID];
	if (!widget) {
		return;
	}

	table->setCellWidget (row, column, widget);
}

WidgetID CallPropagator::tableWidgetCellWidget (WidgetID tableID, long row, long column) 
{
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return -1;
	}

	QWidget *widget = table->cellWidget (row, column);
	if (!widget) {
		return -1;
	}

	WidgetID widgetID = lookupWidget (widget);

	// Send to the Swift side an indicator of what subclass of QWidget this is.
	// We should already have a stub object on the Swift side.

	if (dynamic_cast<QLabel*>(widget)) {
		widgetID |= 1 << 24;
	}
	else if (dynamic_cast<QLineEdit*>(widget)) {
		widgetID |= 2 << 24;
	}
	else if (dynamic_cast<QTextEdit*>(widget)) {
		widgetID |= 3 << 24;
	}
	else if (dynamic_cast<QPushButton*>(widget)) {
		widgetID |= 4 << 24;
	}

	return widgetID;
}

WidgetID CallPropagator::lookupOrAddWidget (QWidget* widget)
{
	// Check whether we already have this QWidget on file.
	// If not, create an entry for it in the widgets dictionary.
	int index = -1;
	for (const auto & [key, value] : widgets) {
		if (((void*)value) == (void*)widget) {
			index = key;
			break;
		}
	}
	if (index == -1) {
		index = widgetObjectCounter++;
		widgets[index] = (QWidget*) widget;
        } 
	return index;
}

WidgetID CallPropagator::lookupWidget (QWidget* widget)
{
	// Check whether we already have this QWidget on file.
	// If not, create an entry for it in the widgets dictionary.
	int index = -1;
	for (const auto & [key, value] : widgets) {
		if (((void*)value) == (void*)widget) {
			index = key;
			break;
		}
	}
	return index;
}

ObjectID CallPropagator::lookupOrAddObject (QObject* object)
{
	// Check whether we already have this QObject on file.
	// If not, create an entry for it in the objects dictionary.
	int index = -1;
	for (const auto & [key, value] : objects) {
		if (((void*)value) == (void*)object) {
			index = key;
			break;
		}
	}
	if (index == -1) {
		index = widgetObjectCounter++;
		objects[index] = (QObject*) object;
        } 
	return index;
}

ObjectID CallPropagator::lookupObject (QObject* object)
{
	// Check whether we already have this QObject on file.
	// If not, create an entry for it in the objects dictionary.
	int index = -1;
	for (const auto & [key, value] : objects) {
		if (((void*)value) == (void*)object) {
			index = key;
			break;
		}
	}
	return index;
}

//--------------------
// QTableWidgetItem
//--------------------
ObjectID CallPropagator::tableWidgetItem (WidgetID tableID, long row, long column) {
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return -1;
	}
	QTableWidgetItem *item = table->item(row, column);
        if (!item) {
                return -1;
	}
	int index = lookupOrAddObject ((QObject*) item);
	return index;
}

ObjectID CallPropagator::tableWidgetCurrentItem (WidgetID tableID) {
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return -1;
	}

	QTableWidgetItem *item = table->currentItem();
        if (!item) {
                return -1;
	}
	int index = lookupOrAddObject ((QObject*) item);
	return index;
}

void CallPropagator::tableWidgetSetItem (WidgetID tableID, long row, long column, ObjectID itemID) {
	QTableWidget *table = (QTableWidget*) widgets[tableID];
	if (!table) {
		return;
	}
	QTableWidgetItem *item = (QTableWidgetItem*) objects[itemID];
	if (!item) {
		return;
	}
	table->setItem (row, column, item);
}

//--------------------
// QTextEdit
//--------------------
WidgetID CallPropagator::textEditNew (WidgetID parentID)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}

	QTextEdit *editor = new QTextEdit (parent);
        editor->setAcceptRichText (false);
        editor->setWordWrapMode (QTextOption::WordWrap);
        editor->setVerticalScrollBarPolicy (Qt::ScrollBarAlwaysOn);
        editor->setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOff);

	int index = widgetObjectCounter++;
	widgets[index] = editor;

	connect (editor, &QTextEdit::currentCharFormatChanged, this, [index]() {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalTextEditCharFormatChanged;
		event.recipient = index;
		swiftEventHandler (event);
	});

	connect (editor, &QTextEdit::textChanged, this, [index]() {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalTextEditTextChanged;
		event.recipient = index;
		swiftEventHandler (event);
	});

	connect (editor, &QTextEdit::cursorPositionChanged, this, [index]() {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalTextEditCursorMoved;
		event.recipient = index;
		swiftEventHandler (event);
	});

	connect (editor->document (), &QTextDocument::modificationChanged, this, [index]() {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalTextEditModified;
		event.recipient = index;
		swiftEventHandler (event);
	});

	//connect (editor->document(), &QTextDocument::undoAvailable, actionUndo, &QAction::setEnabled);
	//connect (editor->document(), &QTextDocument::redoAvailable, actionRedo, &QAction::setEnabled);

	connect (editor, &QTextEdit::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

const char *CallPropagator::textEditToPlainText (WidgetID widgetID)
{
	QTextEdit *textEdit = (QTextEdit*) widgets[widgetID];
	if (!textEdit) {
		return NULL;
	}

	QString text = textEdit->toPlainText ();
	std::string string = text.toStdString();
	const char *cstring = string.c_str();
	char *copy = strdup(cstring);
	return copy;
}

const char *CallPropagator::textEditToHTML (WidgetID widgetID)
{
	QTextEdit *editor = (QTextEdit*) widgets[widgetID];
	if (!editor) {
		return NULL;
	}

	QString html = editor->toHtml();
	std::string string = html.toStdString();
	const char *cstring = string.c_str();
	char *copy = strdup(cstring);
	return copy;
}

void CallPropagator::textEditSetText (WidgetID widgetID, const char *text)
{
	QTextEdit *editor = (QTextEdit*) widgets[widgetID];
	if (!editor) {
		return;
	}

	editor->setText (text ?: "");
}

void CallPropagator::textEditSetAcceptRichText (WidgetID widgetID, bool accepts)
{
	QTextEdit *editor = (QTextEdit*) widgets[widgetID];
	if (!editor) {
		return;
	}

	editor->setAcceptRichText (accepts);
}

//--------------------
// QWebEngineView
//--------------------
WidgetID CallPropagator::webEngineViewNew (WidgetID parentID)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}

	QWebEngineView *webview = new QWebEngineView (parent);
	//connect (reloadAction, &QAction::triggered, webview, &QWebEngineView::reload);
	//connect (backAction, &QAction::triggered, webview, &QWebEngineView::back);
	//connect (forwardAction, &QAction::triggered, webview, &QWebEngineView::forward);

	int index = widgetObjectCounter++;
	widgets[index] = webview;

	connect (webview, &QWebEngineView::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

void CallPropagator::webEngineViewSetHTML (WidgetID widgetID, const char *text)
{
	QWebEngineView *webEngineView = (QWebEngineView*) widgets[widgetID];
	if (!webEngineView) {
		return;
	}

	printf ("Setting HTML of %s to %s\n", typeid(webEngineView).name(), text); fflush(NULL);

	try {
		webEngineView->setHtml (text ?: "");
	}
	catch(...) {
		std::cout << "Exception: "  << std::endl;
	}
}

//--------------------
// QLineEdit
//--------------------
const char *CallPropagator::lineEditText (WidgetID widgetID)
{
	QLineEdit *lineEdit = (QLineEdit*) widgets[widgetID];
	if (!lineEdit) {
		return NULL;
	}

	QString text = lineEdit->text ();
	std::string string = text.toStdString();
	const char *cstring = string.c_str();
	char *copy = strdup(cstring);
	return copy;
}

void CallPropagator::lineEditSetText (WidgetID widgetID, const char *text)
{
	QLineEdit *lineEdit = (QLineEdit*) widgets[widgetID];
	if (!lineEdit) {
		return;
	}

	lineEdit->setText (text ?: "");
}

WidgetID CallPropagator::lineEditNew (WidgetID parentID)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}

	QLineEdit *lineEdit = new QLineEdit (parent);

	int index = widgetObjectCounter++;
	widgets[index] = lineEdit;

	connect (lineEdit, &QLineEdit::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

//--------------------
// QGridLayout
//--------------------
ObjectID CallPropagator::gridLayoutNew (WidgetID parentID)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}
	QGridLayout *layout = new QGridLayout (parent);
	int layoutID = widgetObjectCounter++;
	objects[layoutID] = (QObject*) layout;

	connect (layout, &QGridLayout::destroyed, this, [this, layoutID]() {
		objectDestroyed(layoutID);
	});

	return layoutID;
}

void CallPropagator::gridLayoutAddWidget (ObjectID layoutID, WidgetID widgetID, long row, long column, long value)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}

	Qt::Alignment alignment;
	if (value & 1) alignment |= Qt::AlignLeft;
	if (value & 2) alignment |= Qt::AlignRight;
	if (value & 4) alignment |= Qt::AlignCenter;
	if (value & 8) alignment |= Qt::AlignJustify;
	if (value & 0x20) alignment |= Qt::AlignTop;
	if (value & 0x40) alignment |= Qt::AlignBottom;
	if (value & 0x80) alignment |= Qt::AlignVCenter;
	if (value & 0x100) alignment |= Qt::AlignBaseline;

	layout->addWidget (widget, row, column, alignment);
}

void CallPropagator::gridLayoutAddWidgetWithSpans (ObjectID layoutID, WidgetID widgetID, long row, long column, long rowspan, long colspan, long value)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	QWidget *widget = widgets[widgetID];
	if (!widget) {
		return;
	}

	Qt::Alignment alignment;
	if (value & 1) alignment |= Qt::AlignLeft;
	if (value & 2) alignment |= Qt::AlignRight;
	if (value & 4) alignment |= Qt::AlignCenter;
	if (value & 8) alignment |= Qt::AlignJustify;
	if (value & 0x20) alignment |= Qt::AlignTop;
	if (value & 0x40) alignment |= Qt::AlignBottom;
	if (value & 0x80) alignment |= Qt::AlignVCenter;
	if (value & 0x100) alignment |= Qt::AlignBaseline;

	layout->addWidget (widget, row, column, rowspan, colspan, alignment);
}

SQRect CallPropagator::gridLayoutCellRect (ObjectID layoutID, long row, long column)
{
	SQRect rect;
	rect.origin.x = 0;
	rect.origin.y = 0;
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		rect.size.width = 0;
		rect.size.height = 0;
		return rect;
	}
	QRect qrect = layout->cellRect (row, column);
	rect.size.width = qrect.width();
	rect.size.height = qrect.height ();
	return rect;
}

long CallPropagator::gridLayoutRowCount (ObjectID layoutID)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return 0;
	}
	return layout->rowCount ();
}

long CallPropagator::gridLayoutColumnCount (ObjectID layoutID)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return 0;
	}
	return layout->columnCount ();
}

long CallPropagator::gridLayoutColumnMinimumWidth (ObjectID layoutID, long column)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return 0;
	}
	return layout->columnMinimumWidth(column);
}

long CallPropagator::gridLayoutColumnStretch (ObjectID layoutID, long column)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return 0;
	}
	return layout->columnStretch(column);
}

long CallPropagator::gridLayoutHorizontalSpacing (ObjectID layoutID)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return 0;
	}
	return layout->horizontalSpacing();
}

long CallPropagator::gridLayoutRowMinimumHeight (ObjectID layoutID, long row)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return 0;
	}
	return layout->rowMinimumHeight (row);
}

long CallPropagator::gridLayoutRowStretch (ObjectID layoutID, long row)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return 0;
	}
	return layout->rowStretch(row);
}

void CallPropagator::gridLayoutSetColumnMinimumWidth (ObjectID layoutID, long column, long minWidth)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	layout->setColumnMinimumWidth (column, minWidth);
}

void CallPropagator::gridLayoutSetColumnStretch (ObjectID layoutID, long column, long stretch)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	layout->setColumnStretch (column, stretch);
}

void CallPropagator::gridLayoutSetHorizontalSpacing (ObjectID layoutID, long horizontalSpacing)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	layout->setHorizontalSpacing (horizontalSpacing);
}

void CallPropagator::gridLayoutSetRowMinimumHeight (ObjectID layoutID, long row, long minHeight)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	layout->setRowMinimumHeight (row, minHeight);
}

void CallPropagator::gridLayoutSetRowStretch (ObjectID layoutID, long row, long stretch)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	layout->setRowStretch (row, stretch);
}

void CallPropagator::gridLayoutSetVerticalSpacing (ObjectID layoutID, long verticalSpacing)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return;
	}
	layout->setVerticalSpacing(verticalSpacing);
}

long CallPropagator::gridLayoutVerticalSpacing (ObjectID layoutID)
{
	QGridLayout *layout = (QGridLayout*) objects[layoutID];
	if (!layout) {
		return 0;
	}
	return layout->verticalSpacing();
}

//--------------------
// QCalendarWidget
//--------------------
WidgetID CallPropagator::calendarWidgetNew (WidgetID parentID)
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}

	QCalendarWidget *widget = new QCalendarWidget (parent);
	int index = widgetObjectCounter++;
	widgets[index] = widget;

	connect (widget, &QCalendarWidget::selectionChanged, this, [index]() {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalCalendarSelectionChanged;
		event.recipient = index;
		swiftEventHandler (event);
	});

	connect (widget, &QCalendarWidget::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

SQDate CallPropagator::calendarWidgetSelectedDate (WidgetID widgetID)
{
	QCalendarWidget *widget = (QCalendarWidget*) widgets[widgetID];
	if (!widget) {
		return -1;
	}
	QDate qdate = widget->selectedDate();
	SQDate date = (SQDate) qdate.toJulianDay();
	return date;
}

void CallPropagator::calendarWidgetClearMaximumDate (WidgetID widgetID)
{
	QCalendarWidget *widget = (QCalendarWidget*) widgets[widgetID];
	if (!widget) {
		return;
	}
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
	widget->clearMaximumDate();
#endif
}

void CallPropagator::calendarWidgetClearMinimumDate (WidgetID widgetID)
{
	QCalendarWidget *widget = (QCalendarWidget*) widgets[widgetID];
	if (!widget) {
		return;
	}
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
	widget->clearMinimumDate();
#endif
}

long CallPropagator::calendarWidgetMonthShown (WidgetID widgetID)
{
	QCalendarWidget *widget = (QCalendarWidget*) widgets[widgetID];
	if (!widget) {
		return 0;
	}
	return widget->monthShown();
}

long CallPropagator::calendarWidgetYearShown (WidgetID widgetID)
{
	QCalendarWidget *widget = (QCalendarWidget*) widgets[widgetID];
	if (!widget) {
		return 0;
	}
	return widget->yearShown();
}

long CallPropagator::calendarWidgetHorizontalHeaderFormat (WidgetID widgetID) {
	QCalendarWidget *widget = (QCalendarWidget*) widgets[widgetID];
	if (!widget) {
		return -1;
	}
	return (long) widget->horizontalHeaderFormat ();
}

long CallPropagator::calendarWidgetVerticalHeaderFormat (WidgetID widgetID) {
	QCalendarWidget *widget = (QCalendarWidget*) widgets[widgetID];
	if (!widget) {
		return -1;
	}
	return (long) widget->verticalHeaderFormat ();
}

void CallPropagator::calendarWidgetSetHorizontalHeaderFormat (WidgetID widgetID, long value) {
	QCalendarWidget *widget = (QCalendarWidget*) widgets[widgetID];
	if (!widget) {
		return;
	}
	QCalendarWidget::HorizontalHeaderFormat format;
	switch (value) {
	case 1: format = QCalendarWidget::SingleLetterDayNames; break;
	case 2: format = QCalendarWidget::ShortDayNames; break;
	case 3: format = QCalendarWidget::LongDayNames; break;
	default: format = QCalendarWidget::NoHorizontalHeader; break;
	}
	widget->setHorizontalHeaderFormat (format);
}

void CallPropagator::calendarWidgetSetVerticalHeaderFormat (WidgetID widgetID, long value) {
	QCalendarWidget *widget = (QCalendarWidget*) widgets[widgetID];
	if (!widget) {
		return;
	}
	QCalendarWidget::VerticalHeaderFormat format;
	if (value == 1) {
		format = QCalendarWidget::ISOWeekNumbers;
	} else {
		format = QCalendarWidget::NoVerticalHeader;
	}
	widget->setVerticalHeaderFormat (format);
}

long CallPropagator::calendarWidgetFirstDayOfWeek(WidgetID widgetID)
{
	QCalendarWidget *widget = (QCalendarWidget*) widgets[widgetID];
	if (!widget) {
		return -1;
	}
	return (long) widget->firstDayOfWeek();
}

void CallPropagator::calendarWidgetSetFirstDayOfWeek(WidgetID widgetID, long value)
{
	QCalendarWidget *widget = (QCalendarWidget*) widgets[widgetID];
	if (!widget) {
		return;
	}
	Qt::DayOfWeek day;
	switch (value) {
	default:
	case 1: day = Qt::Monday; break;
	case 2: day = Qt::Tuesday; break;
	case 3: day = Qt::Wednesday; break;
	case 4: day = Qt::Thursday; break;
	case 5: day = Qt::Friday; break;
	case 6: day = Qt::Saturday; break;
	case 7: day = Qt::Sunday; break;
	}
	widget->setFirstDayOfWeek(day);
}

//--------------------
// QSlider
//--------------------
WidgetID CallPropagator::sliderNew (WidgetID parentID) 
{
	QWidget *parent = widgets[parentID];
	if (!parent) {
		return -1;
	}

	QSlider *widget = new QSlider (parent);
	int index = widgetObjectCounter++;
	widgets[index] = widget;

	connect (widget, &QSlider::sliderPressed, this, [index]() {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalSliderPressed;
		event.recipient = index;
		swiftEventHandler (event);
	});
	connect (widget, &QSlider::sliderMoved, this, [index](int value) {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalSliderMoved;
		event.x = value;
		event.recipient = index;
		swiftEventHandler (event);
	});
	connect (widget, &QSlider::sliderReleased, this, [index]() {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalSliderReleased;
		event.recipient = index;
		swiftEventHandler (event);
	});
	connect (widget, &QSlider::valueChanged, this, [index](int value) {
		SQEvent event;
		memset ((void*)&event, 0, sizeof(event));
		event.type = QSignalSliderValueChanged;
		event.x = value;
		event.recipient = index;
		swiftEventHandler (event);
	});

	connect (widget, &QSlider::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

long CallPropagator::sliderTickPosition (WidgetID widgetID) {
	QSlider *widget = (QSlider*) widgets[widgetID];
	if (!widget) {
		return -1;
	}
	return widget->tickPosition();
}

long CallPropagator::sliderTickInterval (WidgetID widgetID) {
	QSlider *widget = (QSlider*) widgets[widgetID];
	if (!widget) {
		return -1;
	}
	return widget->tickInterval();
}

void CallPropagator::sliderSetTickPosition (WidgetID widgetID, long value) {
	QSlider *widget = (QSlider*) widgets[widgetID];
	if (!widget) {
		return;
	}
	QSlider::TickPosition pos = QSlider::NoTicks;
	switch (value) {
	default:
	case 0: pos = QSlider::NoTicks; break;
	case 1: pos = QSlider::TicksAbove; break;
	case 2: pos = QSlider::TicksBelow; break;
	case 3: pos = QSlider::TicksBothSides; break;
	}
	widget->setTickPosition(pos);
}

void CallPropagator::sliderSetTickInterval (WidgetID widgetID, long value) {
	QSlider *widget = (QSlider*) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setTickInterval(value);
}

//--------------------
// QAbstractSlider
//--------------------
long CallPropagator::abstractSliderOrientation (WidgetID widgetID) {
	QAbstractSlider *widget = (QAbstractSlider *) widgets[widgetID];
	if (!widget) {
		return 0;
	}
	Qt::Orientation value = widget->orientation();
	if (value == Qt::Horizontal) {
		return 1;
	} else {
		return 2;
	}
}

void CallPropagator::abstractSliderSetOrientation (WidgetID widgetID, long value) {
	QAbstractSlider *widget = (QAbstractSlider *) widgets[widgetID];
	if (!widget) {
		return;
	}
	Qt::Orientation result = value == 1 ? Qt::Horizontal : Qt::Vertical;
	widget->setOrientation (result);
}

void CallPropagator::abstractSliderSetMaximum (WidgetID widgetID, long maximum) {
	QAbstractSlider *widget = (QAbstractSlider *) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setMaximum (maximum);
}

void CallPropagator::abstractSliderSetMinimum (WidgetID widgetID, long minimum) {
	QAbstractSlider *widget = (QAbstractSlider *) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setMinimum (minimum);
}

void CallPropagator::abstractSliderSetPageStep (WidgetID widgetID, long pageStep) {
	QAbstractSlider *widget = (QAbstractSlider *) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setPageStep (pageStep);
}

void CallPropagator::abstractSliderSetValue (WidgetID widgetID, long value) {
	QAbstractSlider *widget = (QAbstractSlider *) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setValue (value);
}

void CallPropagator::abstractSliderSetSliderDown (WidgetID widgetID, bool value) {
	QAbstractSlider *widget = (QAbstractSlider *) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setSliderDown (value);
}

bool CallPropagator::abstractSliderIsSliderDown (WidgetID widgetID) {
	QAbstractSlider *widget = (QAbstractSlider *) widgets[widgetID];
	if (!widget) {
		return false;
	}
	return widget->isSliderDown ();
}

long CallPropagator::abstractSliderMaximum (WidgetID widgetID) {
	QAbstractSlider *widget = (QAbstractSlider *) widgets[widgetID];
	if (!widget) {
		return 0;
	}
	return widget->maximum ();
}

long CallPropagator::abstractSliderMinimum (WidgetID widgetID) {
	QAbstractSlider *widget = (QAbstractSlider *) widgets[widgetID];
	if (!widget) {
		return 0;
	}
	return widget->minimum ();
}

long CallPropagator::abstractSliderPageStep (WidgetID widgetID) {
	QAbstractSlider *widget = (QAbstractSlider *) widgets[widgetID];
	if (!widget) {
		return 0;
	}
	return widget->pageStep ();
}

long CallPropagator::abstractSliderValue (WidgetID widgetID) {
	QAbstractSlider *widget = (QAbstractSlider *) widgets[widgetID];
	if (!widget) {
		return 0;
	}
	return widget->value ();
}

//--------------------
// QLCDNumber
//--------------------
WidgetID CallPropagator::lcdNumberNew (WidgetID parentID, long numDigits) {
	QWidget *parent = (QWidget*) widgets[parentID];
	if (!parent) {
		return -1;
	}
	QLCDNumber *widget = new QLCDNumber (numDigits, parent);
	if (!widget) {
		return -1;
	}
	int index = widgetObjectCounter++;
	widgets[index] = widget;

	connect (widget, &QLCDNumber::destroyed, this, [this, index]() {
		widgetDestroyed(index);
	});

	return index;
}

void CallPropagator::lcdNumberSetHexMode (WidgetID widgetID) {
	QLCDNumber *widget = (QLCDNumber *) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setHexMode();
}

void CallPropagator::lcdNumberSetBinMode (WidgetID widgetID) {
	QLCDNumber *widget = (QLCDNumber *) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setBinMode();
}

void CallPropagator::lcdNumberSetDecMode (WidgetID widgetID) {
	QLCDNumber *widget = (QLCDNumber *) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setDecMode();
}

void CallPropagator::lcdNumberSetOctMode (WidgetID widgetID) {
	QLCDNumber *widget = (QLCDNumber *) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setOctMode();
}

double CallPropagator::lcdNumberValue (WidgetID widgetID) {
	QLCDNumber *widget = (QLCDNumber *) widgets[widgetID];
	if (!widget) {
		return 0.0;
	}
	return widget->value();
}

long CallPropagator::lcdNumberIntValue (WidgetID widgetID) {
	QLCDNumber *widget = (QLCDNumber *) widgets[widgetID];
	if (!widget) {
		return 0;
	}
	return widget->intValue();
}

long CallPropagator::lcdNumberDigitCount (WidgetID widgetID) {
	QLCDNumber *widget = (QLCDNumber *) widgets[widgetID];
	if (!widget) {
		return 0;
	}
	return widget->digitCount ();
}

void CallPropagator::lcdNumberDisplayInt (WidgetID widgetID, long value) {
	QLCDNumber *widget = (QLCDNumber *) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->display ((int) value);
}

void CallPropagator::lcdNumberDisplayDouble (WidgetID widgetID, double value) {
	QLCDNumber *widget = (QLCDNumber *) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->display (value);
}

bool CallPropagator::lcdNumberSmallDecimalPoint (WidgetID widgetID) {
	QLCDNumber *widget = (QLCDNumber *) widgets[widgetID];
	if (!widget) {
		return false;
	}
	return widget->smallDecimalPoint ();
}

void CallPropagator::lcdNumberSetSmallDecimalPoint (WidgetID widgetID, bool value) {
	QLCDNumber *widget = (QLCDNumber *) widgets[widgetID];
	if (!widget) {
		return;
	}
	widget->setSmallDecimalPoint (value);
}

//---------------------------------------------------------------------
// QScreen
//---------------------------------------------------------------------
long CallPropagator::primaryScreenLogicalDotsPerInch()
{
        QScreen *screen = QGuiApplication::primaryScreen();
	if (!screen) {
		perror (__FUNCTION__);
		return 0;
	}
	int dpi = screen->logicalDotsPerInch();
	printf ("Screen DPI is %d\n", dpi);
	return dpi;
}

long CallPropagator::primaryScreenWidth ()
{
        QScreen *screen = QGuiApplication::primaryScreen();
	if (!screen) {
		perror (__FUNCTION__);
		return 0;
	}
        QRect rect = screen->availableVirtualGeometry();
	return rect.size().width();
}

long CallPropagator::primaryScreenHeight ()
{
        QScreen *screen = QGuiApplication::primaryScreen();
	if (!screen) {
		perror (__FUNCTION__);
		return 0;
	}
        QRect rect = screen->availableVirtualGeometry();
	return rect.size().height ();
}

//--------------------
// QApplication
//--------------------

static int argc = 1;
static char *argv[32] = {
    nullptr
};

ObjectID CallPropagator::applicationNew (long argc_, char *argv[]) 
{
	// We have to keep our own long-lived copies of these.
	// If they aren't long-lived it will cause a crash later.
	argc = argc_;
	for (long i = 0; i < argc_; i++) {
		argv[i] = strdup (argv[i]);
	}

	QApplication *app = new QApplication(argc, (char **) argv);

	qDebug() << "Created QApplication object."; 

	int applicationID = widgetObjectCounter++;
	objects[applicationID] = (QObject*) app;

	connect (app, &QApplication::destroyed, this, [this, applicationID]() {
		objectDestroyed(applicationID);
	});

	return applicationID;
}

bool EventFilter::eventFilter (QObject *object, QEvent *event) 
{
	// Only if the recipient was a QMainWindow should it be conveyed to the Swift side.
	if (auto *window = qobject_cast<QMainWindow *>(object)) {
		// Only if the recipient was a QMainWindow should it be conveyed to the Swift side.
		WidgetID widgetID = sharedCallPropagator->lookupWidget ((QWidget*) object);
		if (widgetID != -1) {
			SQEvent swiftEvent;
			memset ((void*) &swiftEvent, 0, sizeof(swiftEvent));

			swiftEvent.recipient = widgetID;
			swiftEvent.type = static_cast<long>(event->type());

			switch (event->type()) {
			case QEvent::Resize: {
				QResizeEvent *resize = (QResizeEvent*) event;
				swiftEvent.width = resize->size().width();
				swiftEvent.height = resize->size().height ();
				swiftEventHandler (swiftEvent);
				return true;
			}

			case QEvent::Create:
			case QEvent::Destroy:
			case QEvent::Show: 
			case QEvent::Hide: 
			case QEvent::Enter:
			case QEvent::Leave:
			case QEvent::Paint:
			case QEvent::Quit:
			case QEvent::FocusIn:
			case QEvent::FocusOut:
			case QEvent::KeyPress:
			case QEvent::KeyRelease:
			case QEvent::MouseButtonDblClick:
			case QEvent::MouseButtonPress:
			case QEvent::MouseButtonRelease:
			case QEvent::MouseMove:
			case QEvent::Timer:
				swiftEventHandler (swiftEvent);
				return true;

			case QEvent::Move: {
				QMoveEvent *move = (QMoveEvent*) event;
				swiftEvent.type = QEventMove;
				swiftEvent.x = move->pos().x();
				swiftEvent.y = move->pos().y();
				swiftEventHandler (swiftEvent);
				return true;
			}
			case QEvent::Wheel: {
				QWheelEvent *wheel = (QWheelEvent*) event;
				swiftEvent.type = QEventWheel;
				swiftEvent.value = wheel->angleDelta().y();
				swiftEventHandler (swiftEvent);
				return true;
			}

			default:
				break;
			}
		}
	}

	return QObject::eventFilter (object, event);
}

