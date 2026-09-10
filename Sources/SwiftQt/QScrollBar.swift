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
// We're typically given a scroll bar, we don't instantiate them ourselves.

import CShim

@MainActor
public class QScrollBar : QAbstractSlider {
	public convenience init (withID: WidgetID) {
		self.init ()
		self.widgetID = withID
		QWidget.registerWidget (withID, self)
	}

	public var valueChangedHandler: (_ value: Int)->Void = { value in 
		print ("QScrollBar value changed to \(value)!");
	}
	public var sliderMovedHandler: (_ value: Int)->Void = { value in 
		print ("QScrollBar moved! New value=\(value)");
	}
	public var sliderPressedHandler: ()->Void = {
		print ("QScrollBar pressed!");
	}
	public var sliderReleasedHandler: ()->Void = {
		print ("QScrollBar released!");
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
				print ("QScrollBar unknown event.");
		}
		return 0
	}
}
