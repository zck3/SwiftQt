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

	public var valueChangedSlot: (_ value: Int)->Void = { value in 
	}
	public var sliderMovedSlot: (_ value: Int)->Void = { value in 
	}
	public var sliderPressedSlot: ()->Void = {
	}
	public var sliderReleasedSlot: ()->Void = {
	}

	public override func event (_ event: QEvent) -> Bool {
		switch (event.type) {
			default: 
				break
		}
		return false
	}

	public override func signal (_ signal: SQSignal) {
		switch (signal.type) {
			case QSignalSliderValueChanged:
				valueChangedSlot(signal.x)
			case QSignalSliderMoved:
				sliderMovedSlot(signal.x)
			case QSignalSliderPressed:
				sliderPressedSlot()
			case QSignalSliderReleased:
				sliderReleasedSlot()
			default: 
				break
		}
	}

}
