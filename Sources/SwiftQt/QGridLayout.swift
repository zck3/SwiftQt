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
// QGridLayout.swift
// 

@MainActor
public class QGridLayout : QLayout{
	public convenience init (_ parent: QWidget) {
		self.init ()
		if let widgetID = parent.widgetID {
			objectID = Conduit.gridLayoutNew (widgetID)
			QWidget.registerObject (objectID!, self)
		}
	}

	public override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
			default: 
				print ("QGridLayout unknown event.");
		}
		return 0
	}

	public func addWidget (_ widget : QWidget, 
				row: Int,
				column: Int,
				alignment: Int = 0) {
		if let objectID = objectID, let subwidgetID = widget.widgetID {
			Conduit.gridLayoutAddWidget (objectID, subwidgetID, row, column, alignment)
		}
	}
	public func addWidget (_ widget : QWidget, 
				row: Int,
				column: Int,
				rowSpan: Int,
				columnSpan: Int,
				alignment: Int = 0) {
		if let objectID = objectID, let subwidgetID = widget.widgetID {
			Conduit.gridLayoutAddWidgetWithSpans (objectID, subwidgetID, row, column, rowSpan, columnSpan, alignment)
		}
	}

	public func cellRect (_ row: Int, _ column: Int) -> QRect {
		if let objectID = objectID {
			return Conduit.gridLayoutCellRect (objectID, row, column)
		}
		return QRect.zero
	}
	public func columnCount () -> Int {
		if let objectID = objectID {
			return Conduit.gridLayoutColumnCount (objectID)
		}
		return 0
	}
	public func rowCount () -> Int {
		if let objectID = objectID {
			return Conduit.gridLayoutRowCount (objectID)
		}
		return 0
	}
	public func columnMinimumWidth (_ column: Int) -> Int {
		if let objectID = objectID {
			return Conduit.gridLayoutColumnMinimumWidth (objectID, column)
		}
		return 0
	}
	public func rowMinimumHeight (_ row: Int) -> Int {
		if let objectID = objectID {
			return Conduit.gridLayoutRowMinimumHeight (objectID, row)
		}
		return 0
	}
	public func columnStretch (_ column: Int) -> Int {
		if let objectID = objectID {
			return Conduit.gridLayoutColumnStretch (objectID, column)
		}
		return 0
	}
	public func rowStretch (_ row: Int) -> Int {
		if let objectID = objectID {
			return Conduit.gridLayoutRowStretch (objectID, row)
		}
		return 0
	}
	public func horizontalSpacing () -> Int {
		if let objectID = objectID {
			return Conduit.gridLayoutHorizontalSpacing (objectID)
		}
		return 0
	}
	public func verticalSpacing () -> Int {
		if let objectID = objectID {
			return Conduit.gridLayoutVerticalSpacing (objectID)
		}
		return 0
	}
	public func setColumnMinimumWidth (column: Int, _ value: Int)  {
		if let objectID = objectID {
			Conduit.gridLayoutSetColumnMinimumWidth (objectID, column, value)
		}
	}
	public func setRowMinimumHeight (row: Int, _ value: Int)  {
		if let objectID = objectID {
			Conduit.gridLayoutSetRowMinimumHeight (objectID, row, value)
		}
	}
	public func setColumnStretch (column: Int, _ value: Int)  {
		if let objectID = objectID {
			Conduit.gridLayoutSetColumnStretch (objectID, column, value)
		}
	}
	public func setRowStretch (row: Int, _ value: Int)  {
		if let objectID = objectID {
			Conduit.gridLayoutSetRowStretch (objectID, row, value)
		}
	}
	public func setHorizontalSpacing (_ value: Int)  {
		if let objectID = objectID {
			Conduit.gridLayoutSetHorizontalSpacing (objectID, value)
		}
	}
	public func setVerticalSpacing (_ value: Int)  {
		if let objectID = objectID {
			Conduit.gridLayoutSetVerticalSpacing (objectID, value)
		}
	}
}
