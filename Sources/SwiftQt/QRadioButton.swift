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
// QRadioButton.swift
// 

@MainActor
public class QRadioButton : QAbstractButton{
	public convenience init (_ parent: QWidget, _ string: String) {
		self.init ()
		if let parentID = parent.widgetID {
			widgetID = Conduit.radioButtonNew (parentID, string)
			QWidget.registerWidget (widgetID!, self)
		}
	}

	open override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
			case QSignalRadioButtonToggled:
				toggledHandler()

			default: 
				print ("QRadioButton unknown event.");
		}
		return 0
	}

//	func text () -> String {
//		if let widgetID = widgetID {
//			let unsafeString : UnsafePointer<CChar>? = Conduit.radioButtonText(widgetID)
//			if let unsafeString = unsafeString {
//				let safeString : String = String (cString:unsafeString);
//				unsafeString.deallocate()
//				return safeString
//			}
//		}
//		return ""
//	}
//
//	func setText (_ text: String) {
//		if let widgetID = widgetID {
//			Conduit.radioButtonSetText (widgetID, text)
//		}
//	}
}
