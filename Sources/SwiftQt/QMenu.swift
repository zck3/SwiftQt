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

// SwiftQt
// QMenu.swift
// 

@MainActor
public class QMenu : QWidget{
	public convenience init (_ title:String) {
		self.init ()

		widgetID = Conduit.menuNew (title)
		QWidget.registerWidget (widgetID!, self)
	}

	public override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
			default: 
				print ("QMenu unknown event.")
		}
		return 0
	}

	public func title () -> String {
		if let widgetID = widgetID {
			let unsafeString : UnsafePointer<CChar>? = Conduit.menuTitle(widgetID)
                        if let unsafeString = unsafeString {
                                let safeString : String = String (cString:unsafeString);
                                unsafeString.deallocate()
                                return safeString
                        }
		}
		return ""
	}

	public func setTitle (_ string: String) {
		if let widgetID = widgetID {
			Conduit.menuSetTitle (widgetID, string)
		}
	}

	public func addSeparator () {
		if let widgetID = widgetID {
			Conduit.menuAddSeparator (widgetID)
		}
	}

	public func addAction (_ string: String) -> QAction? {
		let action = QAction (string)
		if let widgetID = widgetID {
			if let actionID = action.objectID {
				Conduit.menuAddAction (widgetID, actionID)
			} 
		}
		return action
	}

	public func addAction (_ string: String, triggeredHandler: () -> Void?) -> QAction? {
		let action = QAction (string)
		if let widgetID = widgetID {
			if let actionID = action.objectID {
				Conduit.menuAddAction (widgetID, actionID)
			} 
		}
		return action
	}
}
