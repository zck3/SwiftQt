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
public func swiftEventHandler(event: SQEvent) -> Int 
{
	let id = event.recipient
	if event.type == QWidgetDeallocated {
		let widget = QWidgetStorage.shared.widget(id: id)
		if let widget = widget {
			let type = String(describing: type(of: widget))
			print ("C++ informed Swift that widget \(id) of type \(type) was deallocated.");
			QWidgetStorage.shared.unregister(id: id)
		} else {
			print ("C++ informed Swift that widget \(id) was deallocated, but I don't know it.");
		}
		return 0
	}
	else if event.type == QObjectDeallocated {
		let object = QObjectStorage.shared.object(id: id)
		if let object = object {
			let type = String(describing: type(of: object))
			print ("C++ informed Swift that object \(id) of type \(type) was deallocated.");
			QObjectStorage.shared.unregister(id: id)
		} else {
			print ("C++ informed Swift that object \(id) was deallocated, but I don't know it.");
		}
		return 0
	}
	
	let widget : QWidget? = QWidgetStorage.shared.widget(id: event.recipient)
	if let widget = widget {
		return widget.processEvent (event)
	}

	let object : QObject? = QObjectStorage.shared.object(id: event.recipient)
	if let object = object {
		return object.processEvent (event)
	}
	return -1
}

#if false // Not used.
@_cdecl("swiftEventHandlerForString") 
public func swiftEventHandlerForString(event: SQEventType, parameter1: Int, parameter2: Int) -> UnsafeMutablePointer<CChar>
{
	var response : String

	switch (event) {
	case EventTypeRequireAppNameString:	
		response = app?.name ?? "No Name"

	default:	
		response = ""
	}

	let convertibleResponse : NSString = NSString(string: response)
	let unsafe = UnsafeMutablePointer<CChar>(mutating: convertibleResponse.utf8String)
	return unsafe!
}
#endif

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

