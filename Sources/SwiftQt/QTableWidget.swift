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

@MainActor
public class QTableWidget : QWidget{
        public var cellChangedHandler: (_ row:Int, _ column:Int)->Void = { row, column in
                print ("QTableWidget cellChanged at \(row),\(column)")
        }

        public var cellClickedHandler : (_ row:Int, _ column:Int)->Void = { row, column in
                print ("QTableWidget cellClicked at \(row),\(column)")
        }

        public var cellDoubleClickedHandler : (_ row:Int, _ column:Int)->Void = { row, column in
                print ("QTableWidget cellDoubleClicked at \(row),\(column)")
        }
	//----------

        public var currentCellChangedHandler: (_ row:Int, _ column:Int, _ previousRow:Int, _ previousColumn:Int)->Void = { row, column, previousRow, previousColumn in
                print ("QTableWidget currentCellChanged to \(row),\(column)")
        }

	public var itemSelectionChangedHandler: ()->Void = {
                print ("QTableWidget itemSelectionChanged");
	}

	public convenience init (_ parent: QMainWindow) {
		self.init ()
		if let windowID = parent.widgetID {
			widgetID = Conduit.tableWidgetNew (windowID)
			QWidget.registerWidget (widgetID!, self)
		}
	}

	public override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
		case QSignalTableCellChanged:
			cellChangedHandler(event.y, event.x)

		case QSignalTableCellClicked:
			cellClickedHandler(event.y, event.x)

		case QSignalTableCellDoubleClicked:
			cellDoubleClickedHandler(event.y, event.x)

		case QSignalTableCurrentCellChanged:
			currentCellChangedHandler(event.y, event.x, event.previousRow, event.previousColumn)

		case QSignalTableItemSelectionChanged:
			itemSelectionChangedHandler()

		default: 
			print ("QTableWidget unknown event.");
		}

		return 0
	}

	public func columnCount () -> Int {
		if let widgetID = widgetID {
			return Conduit.tableWidgetColumnCount(widgetID)
                }
		return 0
	}
	public func setColumnCount (_ count:Int) {
		if let widgetID = widgetID {
			return Conduit.tableWidgetSetColumnCount(widgetID, count)
                }
	}
	public func rowCount () -> Int {
		if let widgetID = widgetID {
			return Conduit.tableWidgetRowCount(widgetID)
                }
		return 0
	}
	public func setRowCount (_ count:Int) {
		if let widgetID = widgetID {
			return Conduit.tableWidgetSetRowCount(widgetID, count)
                }
	}
	public func currentColumn () -> Int {
		if let widgetID = widgetID {
			return Conduit.tableWidgetCurrentColumn(widgetID)
                }
		return -1
	}
	public func currentRow () -> Int {
		if let widgetID = widgetID {
			return Conduit.tableWidgetCurrentRow(widgetID)
                }
		return -1
	}
	public func setCurrentCell (_ row:Int, _ column:Int) {
		if let widgetID = widgetID {
			return Conduit.tableWidgetSetCurrentCell(widgetID, row, column)
                }
	}
	public func setHorizontalHeaderLabels (_ labels:[String]) {
		// The C++ Qt code takes a QStringList. Maybe support that later. TODO
		if let widgetID = widgetID {
			let count = labels.count
			var index = 0
			for label in labels {
				Conduit.tableWidgetSetHorizontalHeaderLabels (widgetID, label, index == count-1)
				index = index+1
			}
                }
	}
	public func setVerticalHeaderLabels (_ labels:[String]) {
		// The C++ Qt code takes a QStringList. Maybe support that later. TODO
		if let widgetID = widgetID {
			let count = labels.count
			var index = 0
			for label in labels {
				Conduit.tableWidgetSetVerticalHeaderLabels (widgetID, label, index == count-1)
				index = index+1
			}
                }
	}
	public func setItem (_ row:Int, _ column:Int, _ item:QTableWidgetItem) {
		if let widgetID = widgetID, let itemID = item.objectID {
			Conduit.tableWidgetSetItem(widgetID, row, column, itemID)
		}
	}
	public func item (_ row:Int, _ column:Int) -> QTableWidgetItem? {
		if let widgetID = widgetID {
			let itemID = Conduit.tableWidgetItem(widgetID, row, column)
			if itemID < 0 {
				return nil
			} else {
				let item = QObject.lookupObject(itemID)
				if let item = item {
					// Object should always be a QTableWidgetItem.
					return (item as! QTableWidgetItem)
				} else {
					let newItem = QTableWidgetItem()
					newItem.objectID = itemID
					QObject.registerObject (itemID, newItem)
					return newItem
				} 
			} 
                }
		return nil
	}
	public func currentItem () -> QTableWidgetItem? {
		if let widgetID = widgetID {
			let itemID = Conduit.tableWidgetCurrentItem(widgetID)
			if itemID < 0 {
				return nil
			} else {
				let item = QObject.lookupObject(itemID)
				if let item = item {
					// Object should always be a QTableWidgetItem.
					return (item as! QTableWidgetItem)
				} else {
					let newItem = QTableWidgetItem()
					newItem.objectID = itemID
					QObject.registerObject (itemID, newItem)
					return newItem
				} 
			} 
                }
		return nil
	}
	public func cellWidget (_ row:Int, _ column:Int) -> QWidget? {
		if let widgetID = widgetID {
			let cellWidgetID = Conduit.tableWidgetCellWidget(widgetID, row, column)
			if cellWidgetID < 0 {
				return nil
			} else {
				let cellWidget = QWidget.lookupWidget(cellWidgetID)
				if let cellWidget = cellWidget {
					return cellWidget
				} else {
					// We should not reach here, because
					// all widgets placed into the table 
					// cells are ones that were created
					// in Swift code.
					return nil
				} 
			} 
                }
		return nil
	}
	public func setCellWidget (_ row: Int, _ column: Int, _ widget: QWidget) {
		if let tableID = widgetID, let widgetID = widget.widgetID {
			Conduit.tableWidgetSetCellWidget (tableID, row, column, widgetID)
		}
	}
	public func insertColumn (_ column:Int) {
		if let widgetID = widgetID {
			return Conduit.tableWidgetInsertColumn(widgetID, column)
                }
	}
	public func insertRow (_ row:Int) {
		if let widgetID = widgetID {
			return Conduit.tableWidgetInsertRow(widgetID, row)
                }
	}
}

