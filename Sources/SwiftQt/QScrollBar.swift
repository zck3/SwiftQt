/*=========================================================================
 * This file is part of SwiftQt.
 * (C) 2026 Zack T Smith.
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

// QScrollBar
// We're typically given a scrollbar by another object that uses it
// and we don't instantiate scrollbars ourselves.

import CShim

@MainActor
public class QScrollBar : QAbstractSlider 
{
	public convenience init (withID: WidgetID) {
		self.init ()
		if withID != 0 {
			self.widgetID = withID
			QWidget.registerWidget (withID, self)
		} else {
			fatalError("QScrollBar ID is invalid.")
		}
	}

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

	public override func event (_ event: QEvent) -> Bool {
		switch (event.type) {
			case QSignalSliderValueChanged:
				return valueChangedHandler(event.x)
			case QSignalSliderMoved:
				return sliderMovedHandler(event.x)
			case QSignalSliderPressed:
				return sliderPressedHandler()
			case QSignalSliderReleased:
				return sliderReleasedHandler()

			default: 
				break
		}
		return false
	}
}
