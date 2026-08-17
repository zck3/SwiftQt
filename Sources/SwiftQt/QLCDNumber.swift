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
// QLCDNumber.swift

@MainActor
public class QLCDNumber : QWidget{
	public convenience init (_ parent: QMainWindow, numberOfDigits: Int) {
		self.init ()
		if let windowID = parent.widgetID {
			widgetID = Conduit.lcdNumberNew (windowID, numberOfDigits)
			QWidget.registerWidget (widgetID!, self)
		}
	}

	public override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
			default: 
				print ("QLCDNumber unknown event.");
		}
		return 0
	}

	public func setHexMode () {
		if let widgetID = widgetID {
			Conduit.lcdNumberSetHexMode (widgetID)
		}
	}
	public func setBinMode () {
		if let widgetID = widgetID {
			Conduit.lcdNumberSetBinMode (widgetID)
		}
	}
	public func setDecMode () {
		if let widgetID = widgetID {
			Conduit.lcdNumberSetDecMode (widgetID)
		}
	}
	public func setOctMode () {
		if let widgetID = widgetID {
			Conduit.lcdNumberSetOctMode (widgetID)
		}
	}
	public func value () -> Double {
		if let widgetID = widgetID {
			return Conduit.lcdNumberValue (widgetID)
		}
		return 0.0
	}
	public func intValue () -> Int {
		if let widgetID = widgetID {
			return Conduit.lcdNumberIntValue (widgetID)
		}
		return 0
	}
	public func digitCount () -> Int {
		if let widgetID = widgetID {
			return Conduit.lcdNumberDigitCount (widgetID)
		}
		return 0
	}
	public func smallDecimalPoint () -> Bool {
		if let widgetID = widgetID {
			return Conduit.lcdNumberSmallDecimalPoint (widgetID)
		}
		return false
	}
	public func setSmallDecimalPoint (_ value: Bool) {
		if let widgetID = widgetID {
			return Conduit.lcdNumberSetSmallDecimalPoint (widgetID, value)
		}
	}
	public func display (_ value: Int) {
		if let widgetID = widgetID {
			Conduit.lcdNumberDisplayInt (widgetID, value)
		}
	}
	public func display (_ value: Double) {
		if let widgetID = widgetID {
			Conduit.lcdNumberDisplayDouble (widgetID, value)
		}
	}
}
