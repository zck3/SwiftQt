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

import CShim

@MainActor
open class QMainWindow : QWidget 
{
	let menuBarHeight = 44
	var statusBar : QStatusBar? = nil

	public var windowCreatedHandler: ()->Bool = {
		return false
	}
	public var windowClosedHandler: ()->Bool = {
		return false
	}
	public var windowShownHandler: ()->Bool = {
		return false
	}
	public var windowHiddenHandler: ()->Bool = {
		return false
	}
	public var windowResizedHandler: (_ event: QEvent)->Bool = { event in
		return false
	}
	public var windowMovedHandler: (_ event: QEvent)->Bool = { event in
		return false
	}
	public var windowKeyPressHandler: (_ event: QEvent)->Bool = { event in
		return false
	}
	public var windowKeyReleaseHandler: (_ event: QEvent)->Bool = { event in
		return false
	}
	public var windowEnteredHandler: ()->Bool = {
		return false
	}
	public var windowLeftHandler: ()->Bool = {
		return false
	}
	public var windowPaintedHandler: ()->Bool = {
		return false
	}
	public var windowDidQuitHandler: ()->Bool = {
		return false
	}

	public required init (x: Int, y: Int, width: Int, height: Int) {
		super.init ()
		let id = Conduit.windowNew (x, y, width, height)
		if id != 0 {
			self.widgetID = id
			QWidget.registerWidget (id, self)
		} else {
			fatalError("Unable to instantiate a QMainWindow.")
		}
	}

	open override func event (_ event: QEvent) -> Bool {
		switch (event.type) {
		case QEventCreate:
			return windowCreatedHandler()
		case QEventClose:
			return windowClosedHandler()
		case QEventShow:
			return windowShownHandler()
		case QEventHide:
			return windowHiddenHandler()
		case QEventResize:
			return windowResizedHandler(event)
		case QEventMove:
			return windowMovedHandler(event)
		case QEventKeyPress:
			return windowKeyPressHandler(event)
		case QEventKeyRelease:
			return windowKeyReleaseHandler(event)
		case QEventEnter:
			return windowEnteredHandler()
		case QEventLeave:
			return windowLeftHandler()
		case QEventPaint:
			return windowPaintedHandler()
		case QEventQuit:
			return windowDidQuitHandler()
		default: 
			break
		}

		return false
	}

	public override func signal (_ signal: SQSignal) {
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
	public func setCentralWidget (_ central: QWidget?) {
		if let widgetID = widgetID {
			if central == nil {
				Conduit.windowSetCentralWidget (widgetID, 0)
			} else if let centralID = central!.widgetID {
				Conduit.windowSetCentralWidget (widgetID, centralID)
			}
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

