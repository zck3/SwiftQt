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
// QAbstractSlider.swift
// 

@MainActor
public class QAbstractSlider : QWidget{
	public var valueChangedHandler: (_ value: Int)->Void = { value in 
		//print ("Slider value changed to \(value)!");
	}
	public var sliderMovedHandler: (_ value: Int)->Void = { value in 
		//print ("Slider moved! New value=\(value)");
	}
	public var sliderPressedHandler: ()->Void = {
		//print ("Slider pressed!");
	}
	public var sliderReleasedHandler: ()->Void = {
		//print ("Slider released!");
	}

	public override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
			case QSignalSliderValueChanged:
				valueChangedHandler(event.x)
			case QSignalSliderMoved:
				sliderMovedHandler(event.x)
			case QSignalSliderPressed:
				sliderPressedHandler()
			case QSignalSliderReleased:
				sliderReleasedHandler()

			default: 
				print ("QAbstractSlider unknown event.");
		}
		return 0
	}

	public func value () -> Int {
		if let widgetID = widgetID {
			return Conduit.abstractSliderValue (widgetID)
		}
		return 0
	}
	public func setValue (_ value: Int) {
		if let widgetID = widgetID {
			Conduit.abstractSliderSetValue (widgetID, value)
		}
	}
	public func orientation () -> Int {
		if let widgetID = widgetID {
			return Conduit.abstractSliderOrientation (widgetID)
		}
		return 0
	}
	public func setOrientation (_ orientation: Int) {
		if let widgetID = widgetID {
			Conduit.abstractSliderSetOrientation (widgetID, orientation)
		}
	}
	public func maximum () -> Int {
		if let widgetID = widgetID {
			return Conduit.abstractSliderMaximum (widgetID)
		}
		return 0
	}
	public func setMaximum (_ maximum: Int) {
		if let widgetID = widgetID {
			Conduit.abstractSliderSetMaximum (widgetID, maximum)
		}
	}
	public func minimum () -> Int {
		if let widgetID = widgetID {
			return Conduit.abstractSliderMinimum (widgetID)
		}
		return 0
	}
	public func setMinimum (_ minimum: Int) {
		if let widgetID = widgetID {
			Conduit.abstractSliderSetMinimum (widgetID, minimum)
		}
	}
	public func pageStep () -> Int {
		if let widgetID = widgetID {
			return Conduit.abstractSliderPageStep (widgetID)
		}
		return 0
	}
	public func setPageStep (_ pageStep: Int) {
		if let widgetID = widgetID {
			Conduit.abstractSliderSetPageStep (widgetID, pageStep)
		}
	}

	public func isSliderDown () -> Bool {
		if let widgetID = widgetID {
			return Conduit.abstractSliderIsSliderDown(widgetID)
		}
		return false
	}
	public func setSliderDown (_ value: Bool) {
		if let widgetID = widgetID {
			Conduit.abstractSliderSetSliderDown (widgetID, value)
		}
	}

}
