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
public class QWidgetStorage {
	let idMask : Int = 0x00ffffff

	static let shared = QWidgetStorage()

	private var widgets: [WidgetID: QWidget] = [:]

	public func widget(id: WidgetID) -> QWidget? {
		return widgets[id & idMask]
	}

	public func register(widget: QWidget, id: WidgetID) {
		widgets[id & idMask] = widget
	}

	public func unregister(id: WidgetID) {
		widgets.removeValue(forKey: id & idMask)
	}
}

@MainActor
open class QWidget : QObject 
{
	public var mouseButtonPressEventHandler: (_ event: QEvent) -> Bool = { event in
		return false
	}
	public var mouseButtonReleaseEventHandler: (_ event: QEvent) -> Bool = { event in
		return false
	}
	public var mouseMoveEventHandler: (_ event: QEvent) -> Bool = { event in
		return false
	}
	public var mouseButtonDblClickEventHandler: (_ event: QEvent) -> Bool = { event in
		return false
	}
	public var wheelEventHandler: (_ event: QEvent) -> Bool = { event in
		return false
	}

	@MainActor
	var widgetID : WidgetID?

	public static func isKnownWidget (_ widgetID: WidgetID) -> Bool {
		let idMask : Int = 0x00ffffff
		return QWidgetStorage.shared.widget(id: widgetID & idMask) != nil
	}

	public static func lookupWidget (_ widgetID: WidgetID) -> QWidget? {
		let idMask : Int = 0x00ffffff
		return QWidgetStorage.shared.widget(id: widgetID & idMask)
	}

	public static func registerWidget (_ widgetID: WidgetID, _ widget: QWidget) {
		let idMask : Int = 0x00ffffff
		QWidgetStorage.shared.register (widget: widget, id: widgetID & idMask)
	}

	public static func unregisterWidget (_ widgetID: WidgetID) {
		let idMask : Int = 0x00ffffff
		QWidgetStorage.shared.unregister (id: widgetID & idMask)
	}

	public convenience init (_ parent: QWidget) {
		self.init ()
		if let parentID = parent.widgetID {
			let id = Conduit.widgetNew (parentID)
			if id != 0 {
				self.widgetID = id
				QWidgetStorage.shared.register(widget: self, id: id)
			} else {
				fatalError("Unable to instantiate a QWidget.")
			}
		}
	}

	public func destroy() {
		if let widgetID = widgetID {
			QWidgetStorage.shared.unregister(id: widgetID)
		}
	}

	deinit {
		if let id = widgetID {
			Task { @MainActor in
				QWidget.unregisterWidget(id)
				Conduit.widgetDestroy(id)
				print ("Swift informed C++ that deinit of widget \(id) happened.")
			}
		}
	}

	public func move (_ x: Int, _ y: Int) {
		if let widgetID = widgetID {
			Conduit.move (widgetID, x, y)
		}
	}

	public func raise () {
		if let widgetID = widgetID {
			Conduit.raise (widgetID)
		}
	}

	public func lower () {
		if let widgetID = widgetID {
			Conduit.lower (widgetID)
		}
	}

	public func resize (_ width: Int, _ height: Int) {
		if let widgetID = widgetID {
			Conduit.resize (widgetID, width, height)
		}
	}

	public func frame (_ rect: QRect) -> QRect {
		if let widgetID = widgetID {
			return Conduit.frame (widgetID)
		}
		return QRect.zero
	}

	public func setFrame (_ rect: QRect) {
		if let widgetID = widgetID {
			Conduit.setFrame (widgetID, rect)
		}
	}

	public func isHidden () -> Bool {
		if let widgetID = widgetID {
			return Conduit.isHidden (widgetID)
		}
		return false
	}

	public func isEnabled () -> Bool {
		if let widgetID = widgetID {
			return Conduit.isEnabled (widgetID)
		}
		return false
	}

	public func setHidden (_ value: Bool) {
		if let widgetID = widgetID {
			Conduit.setHidden (widgetID, value)
		}
	}

	public func x () -> Int {
		if let widgetID = widgetID {
			return Conduit.x (widgetID)
		}
		return 0
	}

	public func y () -> Int {
		if let widgetID = widgetID {
			return Conduit.y (widgetID)
		}
		return 0
	}

	public func width () -> Int {
		if let widgetID = widgetID {
			return Conduit.width (widgetID)
		}
		return 0
	}

	public func height () -> Int {
		if let widgetID = widgetID {
			return Conduit.height (widgetID)
		}
		return 0
	}

	public func styleSheet () -> String {
		if let widgetID = widgetID {
			let unsafeString : UnsafePointer<CChar>? = Conduit.styleSheet(widgetID)
			if let unsafeString = unsafeString {
				let safeString : String = String (cString:unsafeString);
				unsafeString.deallocate()
				return safeString
			}
		}
		return ""
	}

	public func setStyleSheet (_ string: String) {
		if let widgetID = widgetID {
			Conduit.setStyleSheet(widgetID, string)
		}
	}

	public func minimumSize (_ size: QSize) -> QSize {
		if let widgetID = widgetID {
			return Conduit.minimumSize (widgetID)
		}
		return QSize.zero
	}

	public func setMinimumSize (_ size: QSize) {
		if let widgetID = widgetID {
			Conduit.setMinimumSize (widgetID, size)
		}
	}

	public func setMaximumSize (_ size: QSize) {
		if let widgetID = widgetID {
			Conduit.setMaximumSize (widgetID, size)
		}
	}

	public func setMaximumHeight(_ maxh: Int) {
		if let widgetID = widgetID {
			Conduit.setMaximumHeight (widgetID, maxh)
		}
	}
	public func setMaximumWidth(_ maxw: Int) {
		if let widgetID = widgetID {
			Conduit.setMaximumWidth (widgetID, maxw)
		}
	}
	public func setMinimumHeight(_ minh: Int) {
		if let widgetID = widgetID {
			Conduit.setMinimumHeight (widgetID, minh)
		}
	}

	public func setMinimumWidth(_ minw: Int) {
		if let widgetID = widgetID {
			Conduit.setMinimumWidth (widgetID, minw)
		}
	}

	public func clearFocus() {
		if let widgetID = widgetID {
			Conduit.clearFocus (widgetID)
		}
	}

	public func setFocus() {
		if let widgetID = widgetID {
			Conduit.setFocus (widgetID)
		}
	}

	public func setParent(_ parent: QWidget?) {
		if let widgetID = widgetID {
			if parent != nil {
				if let parentID = parent!.widgetID {
					Conduit.setParent(widgetID, parentID)
				}
			} else {
				// Remove our widget from its parent.
				Conduit.setParent(widgetID, -1)
			}
		}
	}

	public func parentWidget () -> QWidget? {
		if let widgetID = widgetID {
			let parentID = Conduit.parentWidget (widgetID)
			if parentID < 0 {
				return nil
			}
			let idMask : Int = 0x00ffffff
			let parent : QWidget? = QWidgetStorage.shared.widget(id: parentID & idMask) ?? nil
			return parent
		}
		return nil
	}

	public func addAction (_ string: String, _ triggeredHandler: @escaping () -> Void) -> QAction? {
		if let widgetID = widgetID {
			let action = QAction ()
			action.triggeredHandler = triggeredHandler
			let actionID : Int = Conduit.addActionWithString (widgetID, string)
			action.objectID = actionID
			QObject.registerObject(actionID, action)
			return action
		} 
		return nil
	}

	public func addAction (_ action: QAction, _ triggeredHandler: @escaping () -> Void) -> QAction? {
		if let widgetID = widgetID, 
		   let actionID = action.objectID {
			Conduit.addAction (widgetID, actionID)
			action.triggeredHandler = triggeredHandler
			return action
		}
		return nil
	}

	public override func event (_ event: QEvent) -> Bool {
		switch (event.type) {
			case QEventMouseButtonRelease:
				return mouseButtonReleaseEventHandler (event)
			case QEventMouseButtonPress:
				return mouseButtonPressEventHandler (event)
			case QEventMouseButtonDblClick:
				return mouseButtonDblClickEventHandler (event)
			case QEventWheel:
				return wheelEventHandler (event)
			case QEventMouseMove:
				return mouseMoveEventHandler (event)
			default: 
				break
		}
		return false
	}

}
