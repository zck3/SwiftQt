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
// QPushButton.swift
// 

@MainActor
public class QPushButton : QAbstractButton{
	public convenience init (_ parent: QWidget, _ string: String) {
		self.init ()
		if let parentID = parent.widgetID {
			widgetID = Conduit.pushButtonNew (parentID, string)
			QWidget.registerWidget (widgetID!, self)
		}
	}

	public override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
			case QSignalPushButtonClicked:
				clickedHandler()

			default: 
				print ("QPushButton unknown event.");
		}
		return 0
	}

	public func isFlat () -> Bool {
		if let widgetID = widgetID {
			return Conduit.pushButtonIsFlat(widgetID)
		}
		return false
	}

	public func setFlat (_ flat: Bool) {
		if let widgetID = widgetID {
			Conduit.pushButtonSetFlat (widgetID, flat)
		}
	}

	public func isDefault () -> Bool {
		if let widgetID = widgetID {
			return Conduit.pushButtonIsDefault(widgetID)
		}
		return false
	}

	public func setDefault (_ value: Bool) {
		if let widgetID = widgetID {
			Conduit.pushButtonSetDefault (widgetID, value)
		}
	}

}
