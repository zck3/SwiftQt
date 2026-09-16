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
// QCalendarWidget.swift

@MainActor
public class QCalendarWidget : QWidget
{
	// QCalendarWidget::HorizontalHeaderFormat
	public static let SingleLetterDayNames	= 1
	public static let ShortDayNames = 2
	public static let LongDayNames	= 3
	public static let NoHorizontalHeader = 0

	// QCalendarWidget::VerticalHeaderFormat
	public static let NoVerticalHeader = 0
	public static let ISOWeekNumbers = 1

	// QCalendarWidget::SelectionMode
	public static let NoSelection = 0
	public static let SingleSelection = 1

        public var selectionChangedSlot: ()->Void = {
        }

	public convenience init (_ parent: QWidget) {
		self.init ()
		if let parentID = parent.widgetID {
			let id = Conduit.calendarWidgetNew (parentID)
			if id != 0 {
				self.widgetID = id
				QWidget.registerWidget (id, self)
			} else {
				fatalError("Unable to instantiate a QCalendarWidget.")
			}
		}
	}

	public override func event (_ event: QEvent) -> Bool {
		return false
	}

	public override func signal (_ event: SQSignal) {
		switch (event.type) {
			case QSignalCalendarSelectionChanged:
				selectionChangedSlot()
			default: 
				break
		}
	}

	public func horizontalHeaderFormat() -> Int {
		if let widgetID = widgetID {
			return Conduit.calendarWidgetHorizontalHeaderFormat(widgetID)
		}
		return -1
	}
	public func verticalHeaderFormat() -> Int {
		if let widgetID = widgetID {
			return Conduit.calendarWidgetVerticalHeaderFormat(widgetID)
		}
		return -1
	}
	public func setHorizontalHeaderFormat(_ value : Int) {
		if let widgetID = widgetID {
			Conduit.calendarWidgetSetHorizontalHeaderFormat(widgetID, value)
		}
	}
	public func setVerticalHeaderFormat(_ value: Int) {
		if let widgetID = widgetID {
			Conduit.calendarWidgetSetVerticalHeaderFormat(widgetID, value)
		}
	}
	public func clearMaximumDate() {
		if let widgetID = widgetID {
			Conduit.calendarWidgetClearMaximumDate(widgetID)
		}
	}
	public func clearMinimumDate() {
		if let widgetID = widgetID {
			Conduit.calendarWidgetClearMinimumDate(widgetID)
		}
	}
	public func monthShown() -> Int {
		if let widgetID = widgetID {
			return Conduit.calendarWidgetMonthShown(widgetID)
		}
		return 0
	}
	public func yearShown() -> Int {
		if let widgetID = widgetID {
			return Conduit.calendarWidgetYearShown(widgetID)
		}
		return 0
	}

	public func firstDayOfWeek () -> Int {
		if let widgetID = widgetID {
			return Conduit.calendarWidgetFirstDayOfWeek(widgetID)
		}
		return -1
	}
	public func setFirstDayOfWeek (_ value : Int) {
		if let widgetID = widgetID {
			Conduit.calendarWidgetSetFirstDayOfWeek(widgetID, value)
		}
	}
	public func selectedDate () -> QDate? {
		if let widgetID = widgetID {
			let date = Conduit.calendarWidgetSelectedDate(widgetID) 
			if date <= 0 {
				return nil
			}
			return date
		}
		return nil
	}
}
