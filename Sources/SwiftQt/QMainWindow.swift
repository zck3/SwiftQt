/*=========================================================================
 * This file is part of SwiftQt.
 * (C) 2023 Zack T Smith.
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

import CShim

@MainActor
open class QMainWindow : QWidget {
	let menuBarHeight = 44
	var statusBar : QStatusBar? = nil

	public var windowCreatedHandler: ()->Void = {
	}
	public var windowClosedHandler: ()->Void = {
	}
	public var windowShownHandler: ()->Void = {
	}
	public var windowHiddenHandler: ()->Void = {
	}
	public var windowResizedHandler: ()->Void = {
	}
	public var windowEnteredHandler: ()->Void = {
	}
	public var windowLeftHandler: ()->Void = {
	}
	public var windowPaintedHandler: ()->Void = {
	}
	public var windowMovedHandler: ()->Void = {
	}
	public var windowDidQuitHandler: ()->Void = {
	}

	public required init (x: Int, y: Int, width: Int, height: Int) {
		super.init ()
		widgetID = Conduit.windowNew (x, y, width, height)
		QWidget.registerWidget (widgetID!, self)
	}

	open override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
		case QEventCreate:
			windowCreatedHandler()
			return 0
		case QEventClose:
			windowClosedHandler()
			return 0
		case QEventShow:
			windowShownHandler()
			return 0
		case QEventHide:
			windowHiddenHandler()
			return 0
		case QEventResize:
			windowResizedHandler()
			return 0
		case QEventEnter:
			windowEnteredHandler()
			return 0
		case QEventLeave:
			windowLeftHandler()
			return 0
		case QEventPaint:
			windowPaintedHandler()
			return 0
		case QEventMove:
			windowMovedHandler()
			return 0
		case QEventQuit:
			windowDidQuitHandler()
			return 0
		default: 
			break
		}

		return super.processEvent(event)
	}

	public func setTitle (_ title : String) {
		if let widgetID = widgetID {
			Conduit.windowSetTitle (widgetID, title)
		}
	}

	public func show () {
		if let widgetID = widgetID {
			Conduit.windowShow (widgetID)
		}
	}

	public func hide () {
		if let widgetID = widgetID {
			Conduit.windowHide (widgetID)
		}
	}

	public func close () {
		if let widgetID = widgetID {
			Conduit.windowClose (widgetID)
		}
	}

	/*! This is necessary in order to provide an alternative layout.
	 *  First create the central widget, then apply desired layout to it,
	 *  then call setCentralWidget. (Note, this isn't necessary for QWindow.)
	 */
	public func setCentralWidget (_ widget: QWidget) {
		if let widgetID = widgetID, let subwidgetID = widget.widgetID {
			Conduit.windowSetCentralWidget (widgetID, subwidgetID)
		}
	}

	public func setMinimumSize (_ width: Int, _ height: Int) {
		if let widgetID = widgetID {
			Conduit.windowSetMinimumSize (widgetID, width, height)
		}
	}
	public func setMaximumSize (_ width: Int, _ height: Int) {
		if let widgetID = widgetID {
			Conduit.windowSetMaximumSize (widgetID, width, height)
		}
	}

	public func windowWidth () -> Int {
		if let widgetID = widgetID {
			return Conduit.windowWidth (widgetID)
		}
		return 0
	}

	public func windowHeight () -> Int {
		if let widgetID = widgetID {
			return Conduit.windowHeight (widgetID)
		}
		return 0
	}

	public func setMenuBar (_ menuBar: QMenuBar?) {
		if let windowID = widgetID { 
			if let menuBar = menuBar {
				if let menuBarID = menuBar.widgetID {
					Conduit.windowSetMenuBar (windowID, menuBarID)
				}
			} else {
				Conduit.windowSetMenuBar (windowID, 0)
			}
		}
	}

	public func setStatusBar (_ statusBar: QStatusBar) {
		if let windowID = widgetID { 
			if let statusBarID = statusBar.widgetID {
				Conduit.windowSetStatusBar (windowID, statusBarID)
			}
		}
	}

	public func windowTitle () -> String {
		if let widgetID = widgetID {
			let unsafeString : UnsafePointer<CChar>? = Conduit.windowTitle(widgetID)
			if let unsafeString = unsafeString {
				let safeString : String = String (cString:unsafeString);
				unsafeString.deallocate()
				return safeString
			}
		}
		return ""
	}

	public func setWindowTitle (_ title: String) {
		if let widgetID = widgetID {
			Conduit.windowSetTitle (widgetID, title)
		}
	}
}

