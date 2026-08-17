/*=========================================================================
 * This file is part of SwiftQt.
 * (C) 2023, 2026 Zack T Smith.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * The author may be reached at 3 at zs3 dot me.
 *=======================================================================*/

// SwiftQt
// Types shared between C and Swift sides of the library and used by the C++ code.

#ifndef SWIFTQT_COMMON_TYPES_H
#define SWIFTQT_COMMON_TYPES_H

#define kKitName "SwiftQt"
#define kKitRelease "0.26"
#define kKitReleaseMajor 0
#define kKitReleaseMinor 26

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

// Each sides has their own version of window and font structs and classes.
typedef long WidgetID;
typedef long ObjectID;
typedef long SQCoord;
typedef long SQColor;
typedef const char * const SQKeySequence; // e.g. "Ctrl+w" or a name such as "Redo"
typedef long long SQDate; // Qt represents a date as a 64-bit Julian day number.

typedef struct {
	SQCoord x;
	SQCoord y;
} SQPoint;

typedef struct {
	SQCoord width;
	SQCoord height;
} SQSize;

typedef struct {
	SQPoint origin;
	SQSize size;
} SQRect;

enum : long {
	// Types of events sent from C++ side to Swift side.
	QEventNone = 0,                              
	QEventTimer = 1,                             
	QEventMouseButtonPress = 2,                  
	QEventMouseButtonRelease = 3,                
	QEventMouseButtonDblClick = 4,               
	QEventMouseMove = 5,                         
	QEventKeyPress = 6,                          
	QEventKeyRelease = 7,                        
	QEventFocusIn = 8,                           
	QEventFocusOut = 9,                          
	QEventFocusAboutToChange = 23,               
	QEventEnter = 10,                            
	QEventLeave = 11,                            
	QEventPaint = 12,                            
	QEventMove = 13,                             
	QEventResize = 14,                           
	QEventCreate = 15,                           
	QEventDestroy = 16,                          
	QEventShow = 17,                             
	QEventHide = 18,                             
	QEventClose = 19,                            
	QEventQuit = 20,                             
	QEventParentChange = 21,                     
	QEventParentAboutToChange = 131,             
	QEventThreadChange = 22,                     
	QEventWindowActivate = 24,                   
	QEventWindowDeactivate = 25,                 
	QEventShowToParent = 26,                     
	QEventHideToParent = 27,                     
	QEventWheel = 31,                            
	QEventWindowTitleChange = 33,                
	QEventWindowIconChange = 34,                 
	QEventApplicationWindowIconChange = 35,      
	QEventApplicationFontChange = 36,            
	QEventApplicationLayoutDirectionChange = 37, 
	QEventApplicationPaletteChange = 38,         
	QEventPaletteChange = 39,                    
	QEventClipboard = 40,                        
	QEventSpeech = 42,                           
	QEventMetaCall =  43,                        
	QEventSockAct = 50,                          
	QEventWinEventAct = 132,                     
	QEventDeferredDelete = 52,                   
	QEventDragEnter = 60,                        
	QEventDragMove = 61,                         
	QEventDragLeave = 62,                        
	QEventDrop = 63,                             
	QEventDragResponse = 64,                     
	QEventChildAdded = 68,                       
	QEventChildPolished = 69,                    
	QEventChildRemoved = 71,                     
	QEventShowWindowRequest = 73,                
	QEventPolishRequest = 74,                    
	QEventPolish = 75,                           
	QEventLayoutRequest = 76,                    
	QEventUpdateRequest = 77,                    
	QEventUpdateLater = 78,                      

	// Messages from C++ to Swift telling it to deallocate Swift widgets and objects.
	QWidgetDeallocated = 600,
	QObjectDeallocated = 601,

	//----------------------------------------
	// The following convey to the Swift side
	// that a Signal in the C++ code
	// triggered a call to the associated
	// C++ closure (Slot). 
	// The means by which the equivalent 
	// Swift closure is invoked is by passing
	// one of the below faux events to the
	// Swift side.
	//----------------------------------------

	QSignalActionTriggered = 602,

	QSignalPushButtonClicked,
	QSignalRadioButtonToggled, 
	QSignalCheckBoxStateChanged, 

	QSignalCalendarSelectionChanged,

	QSignalTextEditCharFormatChanged,
	QSignalTextEditCursorMoved,
	QSignalTextEditModified,
	QSignalTextEditTextChanged,

	QSignalTableCellChanged,
	QSignalTableCellClicked,
	QSignalTableCellDoubleClicked,
	QSignalTableCurrentCellChanged,
	QSignalTableItemSelectionChanged,

	QSignalVerticalScrollbarChanged,

	QSignalSliderValueChanged,
	QSignalSliderMoved,
	QSignalSliderPressed,
	QSignalSliderReleased,

	QSignalLabelHovered,
};

typedef struct event
{
	long recipient; // can be WidgetID or ObjectID
	long type;
	SQCoord x; // or column in the case of table
	SQCoord y; // or row in the case of table
	SQCoord width;
	SQCoord height;
	float value;
	long previousRow;
	long previousColumn;
	//const char _Nonnull **argv;
	//int argc;
} SQEvent;

SQPoint SQPoint_new(SQCoord,SQCoord) 	__attribute__((swift_name("SQPoint.init(_:_:)")));
SQPoint SQPoint_zero(void) 	__attribute__((swift_name("getter:SQPoint.zero()")));

SQSize SQSize_new(SQCoord,SQCoord) 	__attribute__((swift_name("SQSize.init(_:_:)")));
SQSize SQSize_zero(void) 	__attribute__((swift_name("getter:SQSize.zero()")));
bool SQSize_equals(SQSize, SQSize)	__attribute__((swift_name("SQSize.equals(_:_:)")));

SQRect SQRect_new(SQCoord,SQCoord,SQCoord,SQCoord)  	__attribute__((swift_name("SQRect.new(_:_:_:_:)")));
SQRect SQRect_zero(void)	__attribute__((swift_name("getter:SQRect.zero()")));
void SQRect_print(SQRect)	__attribute__((swift_name("SQRect.print(_:)")));
bool SQRect_equals(SQRect, SQRect)	__attribute__((swift_name("SQRect.equals(_:_:)")));
bool SQRect_containsPoint (SQRect rect, SQCoord x, SQCoord y)	__attribute__((swift_name("SQRect.containsPoint(_:_:_:)")));

//SQColor SQColor_fromRGB(RGB)	__attribute__((swift_name("SQColor.fromRGB(_:)")));
//SQColor SQColor_fromRgb(int,int,int)	__attribute__((swift_name("SQColor.fromRgb(_:_:_:)")));

extern int swiftEventHandler (SQEvent);

const char * _Nonnull SQReleaseName(void);
const char * _Nonnull SQReleaseString(void);
long SQReleaseMajor(void);
long SQReleaseMinor(void);

#ifdef __cplusplus
}
#endif

#endif 
