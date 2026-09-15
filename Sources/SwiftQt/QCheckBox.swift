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

// SwiftQt
// QCheckBox.swift
// 

@MainActor
public class QCheckBox : QAbstractButton
{
	public var stateChangedHandler : ()->Bool = {
		return false
	}

	public convenience init (_ parent: QWidget, _ string: String) {
		self.init ()
		if let parentID = parent.widgetID {
			let id = Conduit.checkBoxNew (parentID, string)
			if id != 0 {
				self.widgetID = id
				QWidget.registerWidget (id, self)
			} else {
				fatalError("Unable to instantiate a QCheckBox.")
			}
		}
	}

	public override func event (_ event: QEvent) -> Bool {
		switch (event.type) {
			case QSignalCheckBoxStateChanged:
				return stateChangedHandler()

			default: 
				break
		}
		return false
	}

	public func isTristate () -> Bool {
		if let widgetID = widgetID {
			return Conduit.checkBoxIsTristate(widgetID)
		}
		return false
	}

	public func setTristate (_ value: Bool) {
		if let widgetID = widgetID {
			Conduit.checkBoxSetTristate (widgetID, value)
		}
	}

	public func checkState () -> Int {
		if let widgetID = widgetID {
			return Conduit.checkBoxCheckState(widgetID)
		}
		return Qt.Unchecked
	}

	public func setCheckState (_ value: Int) {
		if value != Qt.Checked && value != Qt.Unchecked && value != Qt.PartiallyChecked {
			return
		}
		if let widgetID = widgetID {
			Conduit.checkBoxSetCheckState (widgetID, value)
		}
	}

}
