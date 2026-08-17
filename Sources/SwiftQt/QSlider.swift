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
// QSlider.swift

@MainActor
public class QSlider : QAbstractSlider{
	public static let NoTicks = 0
	public static let TicksBothSides = 3
	public static let TicksAbove = 1
	public static let TicksBelow = 2	
	public static let TicksLeft = TicksAbove	
	public static let TicksRight = TicksBelow

	public convenience init (_ parent: QMainWindow) {
		self.init ()
		if let windowID = parent.widgetID {
			widgetID = Conduit.sliderNew (windowID)
			QWidget.registerWidget (widgetID!, self)
		}
	}

	public override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
			case QSignalSliderValueChanged:
				valueChangedHandler (event.x)
			case QSignalSliderMoved:
				sliderMovedHandler (event.x)
			case QSignalSliderPressed:
				sliderPressedHandler ()
			case QSignalSliderReleased:
				sliderReleasedHandler ()

			default: 
				print ("QSlider unknown event.");
		}
		return 0
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
