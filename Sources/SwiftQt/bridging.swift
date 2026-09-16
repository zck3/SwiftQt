//=========================================================================
// This file is part of SwiftQt.
// (C) 2023, 2026 Zack T Smith.
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

import Foundation
import CShim

//
// SwiftQt
// bridging.swift
// Links Swift to C code.
// 

@MainActor
public var application : QApplication? = nil

@MainActor
@_cdecl("swiftEventHandler") 
public func swiftEventHandler(event: SQEvent) -> Bool /* true => event handled, false => not handled */
{
	let id = event.recipient

	let widget : QWidget? = QWidgetStorage.shared.widget(id: id)
	if let widget = widget {
		return widget.event (event)
	}

	let object : QObject? = QObjectStorage.shared.object(id: id)
	if let object = object {
		return object.event (event)
	}

	let gadget : QGadget? = QGadgetStorage.shared.gadget(id: id)
	if let gadget = gadget {
		return gadget.event (event)
	}

	print ("Event of type \(event.typeString()) for \(id) not consumed.")

	return false
}

@MainActor
@_cdecl("swiftDestructor") 
public func swiftDestructor(id: Int, hint: Int)
{
	if hint == QWidgetDeallocated {
		let widget = QWidgetStorage.shared.widget(id: id)
		if let widget = widget {
			let typeString = String(describing: type(of: widget))
			print ("C++ informed Swift that widget \(id) of type \(typeString) was deallocated.");
			QWidgetStorage.shared.unregister(id: id)
		} else {
			print ("C++ informed Swift that unfamiliar widget \(id) was deallocated.");
		}
	}
	else if hint == QObjectDeallocated {
		let object = QObjectStorage.shared.object(id: id)
		if let object = object {
			let typeString = String(describing: type(of: object))
			print ("C++ informed Swift that object \(id) of type \(typeString) was deallocated.");
			QObjectStorage.shared.unregister(id: id)
		} else {
			print ("C++ informed Swift that unfamiliar object \(id) was deallocated.");
		}
	}
	else if hint == QGadgetDeallocated {
		let gadget = QGadgetStorage.shared.gadget(id: id)
		if let gadget = gadget {
			let typeString = String(describing: type(of: gadget))
			print ("C++ informed Swift that gadget \(id) of type \(typeString) was deallocated.");
			QGadgetStorage.shared.unregister(id: id)
		} else {
			print ("C++ informed Swift that unfamiliar gadget \(id) was deallocated.");
		}
	}
}

@MainActor
@_cdecl("swiftSignalHandler") 
public func swiftSignalHandler(signal: SQSignal)
{
	let id = signal.recipient

	let widget : QWidget? = QWidgetStorage.shared.widget(id: signal.recipient)
	if let widget = widget {
		return widget.signal (signal)
	}

	let object : QObject? = QObjectStorage.shared.object(id: signal.recipient)
	if let object = object {
		return object.signal (signal)
	}

	print ("Signal of type \(signal.type) for \(id) not consumed.")
}

extension SQPoint {
	mutating func zero() -> SQPoint {
		return SQPoint.zero
	}
}

extension SQSize {
	mutating func zero() -> SQSize {
		return SQSize.zero
	}
	public func equals(_ size: SQSize) -> Bool {
		return SQSize.equals(self, size)
	}
}

extension SQRect {
	mutating func zero() -> SQRect {
		return SQRect.zero
	}
	public func print() -> Void {
		SQRect.print(self)
	}
	public func equals(_ rect: SQRect) -> Bool {
		return SQRect.equals(self, rect)
	}
	public func containsPoint(_ x: Int, _ y: Int) -> Bool {
		return SQRect.containsPoint(self, x, y)
	}
}

extension SQColor {
	public func fromRgb(_ red: Int, _ green: Int, _ blue: Int) -> SQColor {
		return (((red & 255) << 16) | ((green & 255) << 8) | (blue & 255)) as SQColor
	}
	public func fromRgb(_ value: Int) -> SQColor {
		return (value & 0xffffff) as SQColor
	}
}

extension SQDate {
	public func year () -> Int {
		return Conduit.dateYear(self)
	}
	public func month () -> Int {
		return Conduit.dateMonth(self)
	}
	public func day () -> Int {
		return Conduit.dateDay(self)
	}
}

// Make internal value types usable from Swift apps.
public typealias QDate = SQDate
public typealias QRect = SQRect
public typealias QSize = SQSize
public typealias QPoint = SQPoint
public typealias QColor = SQColor
public typealias QKeySequence = SQKeySequence 
public typealias QUrl = String
public typealias QEvent = SQEvent

public extension SQKeySequence {
	func count () -> Int {
		return 1
	}
	func isEmpty () -> Bool {
		return false
	}
}

public extension QKeySequence {
	static func New ()->String	{ return "Ctrl+n"; }
	static func Open ()->String	{ return "Ctrl+o"; }
	static func Close ()->String	{ return "Ctrl+w"; }
	static func Save ()->String	{ return "Ctrl+s"; }
	static func SaveAs ()->String	{ return "Ctrl+Shift+s"; }
	static func Print ()->String	{ return "Ctrl+p"; }
	static func Quit ()->String	{ return "Ctrl+q"; }
	static func SelectAll()->String	{ return "Ctrl+a"; }
	static func Copy ()->String	{ return "Ctrl+c"; }
	static func Cut ()->String	{ return "Ctrl+x"; }
	static func Paste ()->String	{ return "Ctrl+v"; }
	static func Undo ()->String	{ return "Ctrl+z"; }
	static func AddTab ()->String	{ return "Ctrl+t"; }
	static func ZoomIn ()->String	{ return "Ctrl+Plus"; }
	static func ZoomOut ()->String	{ return "Ctrl+Minus"; }
	static func Find ()->String	{ return "Ctrl+f"; }
	static func FindNext ()->String	{ return "Ctrl+g"; }
	static func Bold ()->String	{ return "Ctrl+b"; }
	static func Italic ()->String	{ return "Ctrl+i"; }
	static func Underline()->String	{ return "Ctrl+u"; }
}

public extension QUrl {
	func isValid () -> Bool {
		return Conduit.urlIsValid (self)
	}
	func isLocalFile () -> Bool {
		return Conduit.urlIsLocalFile (self)
	}
}

public extension SQEvent {
	func typeString() -> String {
		var string : String
		switch (self.type) {
		case 1: string = "QEventTimer"
		case 2: string = "QEventMouseButtonPress"
		case 3: string = "QEventMouseButtonRelease"
		case 4: string = "QEventMouseButtonDblClick"
		case 5: string = "QEventMouseMove"
		case 6: string = "QEventKeyPress"
		case 7: string = "QEventKeyRelease"
		case 8: string = "QEventFocusIn"
		case 9: string = "QEventFocusOut"
		case 10: string = "QEventEnter"
		case 11: string = "QEventLeave"
		case 12: string = "QEventPaint"
		case 13: string = "QEventMove"
		case 14: string = "QEventResize"
		case 15: string = "QEventCreate"
		case 16: string = "QEventDestroy"
		case 17: string = "QEventShow"
		case 18: string = "QEventHide"
		case 19: string = "QEventClose"
		case 20: string = "QEventQuit"
		case 21: string = "QEventParentChange"
		case 22: string = "QEventThreadChange"
		case 23: string = "QEventFocusAboutToChange"
		case 24: string = "QEventWindowActivate"
		case 25: string = "QEventWindowDeactivate"
		case 26: string = "QEventShowToParent"
		case 27: string = "QEventHideToParent"
		case 31: string = "QEventWheel"
		case 33: string = "QEventWindowTitleChange"
		case 34: string = "QEventWindowIconChange"
		case 35: string = "QEventApplicationWindowIconChange"
		case 36: string = "QEventApplicationFontChange"
		case 37: string = "QEventApplicationLayoutDirectionChange"
		case 38: string = "QEventApplicationPaletteChange"
		case 39: string = "QEventPaletteChange"
		case 40: string = "QEventClipboard"
		case 42: string = "QEventSpeech"
		case 43: string = "QEventMetaCall"
		case 50: string = "QEventSockAct"
		case 52: string = "QEventDeferredDelete"
		case 60: string = "QEventDragEnter"
		case 61: string = "QEventDragMove"
		case 62: string = "QEventDragLeave"
		case 63: string = "QEventDrop"
		case 64: string = "QEventDragResponse"
		case 68: string = "QEventChildAdded"
		case 69: string = "QEventChildPolished"
		case 71: string = "QEventChildRemoved"
		case 73: string = "QEventShowWindowRequest"
		case 74: string = "QEventPolishRequest"
		case 75: string = "QEventPolish"
		case 76: string = "QEventLayoutRequest"
		case 77: string = "QEventUpdateRequest"
		case 78: string = "QEventUpdateLater"
		case 131: string = "QEventParentAboutToChange"
		case 132: string = "QEventWinEventAct"
		default: string = "?"
		}
		return string
	}

}
