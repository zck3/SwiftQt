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
// QLayout.swift
// QLayout is an abstract class.
// 

@MainActor
public class QLayout : QObject{
	public override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
			default: 
				print ("QLayout unknown event.");
		}
		return 0
	}

	public func addWidget (_ widget : QWidget) {
		if let objectID = objectID, let widgetID = widget.widgetID {
			Conduit.layoutAddWidget (objectID, widgetID)
		}
	}

	public func removeWidget (_ widget : QWidget) {
		if let objectID = objectID, let widgetID = widget.widgetID {
			Conduit.layoutRemoveWidget (objectID, widgetID)
		}
	}

	public func spacing () -> Int {
		if let objectID = objectID {
			return Conduit.layoutSpacing (objectID)
		}
		return 0
	}

	public func setSpacing (_ value: Int) {
		if let objectID = objectID {
			Conduit.layoutSetSpacing (objectID, value)
		}
	}

}
