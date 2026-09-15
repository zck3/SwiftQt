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
// QSlider.swift

@MainActor
public class QSlider : QAbstractSlider {
	public static let NoTicks = 0
	public static let TicksBothSides = 3
	public static let TicksAbove = 1
	public static let TicksBelow = 2	
	public static let TicksLeft = TicksAbove	
	public static let TicksRight = TicksBelow

	public var valueChangedHandler: (_ value: Int)->Bool = { value in 
		return false
	}
	public var sliderMovedHandler: (_ value: Int)->Bool = { value in 
		return false
	}
	public var sliderPressedHandler: ()->Bool = {
		return false
	}
	public var sliderReleasedHandler: ()->Bool = {
		return false
	}

	public convenience init (_ parent: QMainWindow) {
		self.init ()
		if let windowID = parent.widgetID {
			let id = Conduit.sliderNew (windowID)
			if id != 0 {
				self.widgetID = id
				QWidget.registerWidget (id, self)
			} else {
				fatalError("Unable to instantiate a QSlider.")
			}
		}
	}

	public override func event (_ event: QEvent) -> Bool {
		switch (event.type) {
			case QSignalSliderValueChanged:
				return valueChangedHandler (event.x)
			case QSignalSliderMoved:
				return sliderMovedHandler (event.x)
			case QSignalSliderPressed:
				return sliderPressedHandler ()
			case QSignalSliderReleased:
				return sliderReleasedHandler ()

			default: 
				break
		}
		return false
	}

	public func tickerPosition () -> Int {
		if let widgetID = widgetID {
			return Conduit.sliderTickPosition (widgetID)
		}
		return 0
	}

	public func tickerInterval () -> Int {
		if let widgetID = widgetID {
			return Conduit.sliderTickInterval (widgetID)
		}
		return 0
	}

	public func setTickPosition (_ value: Int) {
		if let widgetID = widgetID {
			Conduit.sliderSetTickPosition (widgetID, value)
		}
	}

	public func setTickInterval (_ value: Int) {
		if let widgetID = widgetID {
			Conduit.sliderSetTickInterval (widgetID, value)
		}
	}
}
