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

import CShim

// TODO: Add QAbstractScrollArea.

@MainActor
public class QScrollArea : QWidget 
{
	public convenience init (_ parent: QWidget) {
		self.init ()
		if let parentID = parent.widgetID {
			let id = Conduit.scrollAreaNew (parentID)
			if id != 0 {
				self.widgetID = id
				QWidget.registerWidget (id, self)
			} else {
				fatalError("Unable to instantiate a QScrollArea.")
			}
		}
	}

	public override func event (_ event: QEvent) -> Bool {
		switch (event.type) {
			default: 
				break
		}
		return false
	}

	public func setWidget (_ widget: QWidget) {
		if let id = self.widgetID, let widgetID = widget.widgetID {
			Conduit.scrollAreaSetWidget (id, widgetID)
		}
	}

	public func horizontalScrollBar () -> QScrollBar? {
		if let areaID = self.widgetID {
			let scrollbarID = Conduit.scrollAreaHorizontalScrollBar (areaID)
			return QScrollBar(withID: scrollbarID)
		}
		return nil
	}

	public func verticalScrollBar () -> QScrollBar? {
		if let areaID = self.widgetID {
			let scrollbarID = Conduit.scrollAreaVerticalScrollBar (areaID)
			return QScrollBar(withID: scrollbarID)
		}
		return nil
	}

	public func setVerticalScrollBarPolicy (_ policy: Int) {
		if let areaID = self.widgetID {
			Conduit.scrollAreaSetVerticalScrollBarPolicy (areaID, policy)
		}
	}

	public func setHorizontalScrollBarPolicy (_ policy: Int) {
		if let areaID = self.widgetID {
			Conduit.scrollAreaSetHorizontalScrollBarPolicy (areaID, policy)
		}
	}
}
