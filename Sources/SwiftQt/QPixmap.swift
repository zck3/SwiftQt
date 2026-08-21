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
// QPixmap.swift

@MainActor
public class QPixmap : QGadget {
	public convenience init (_ path: String?) {
		self.init ()
		gadgetID = Conduit.pixmapWithPathNew (path ?? "")
		if let gadgetID = gadgetID {
			QGadget.registerGadget (gadgetID, self)
		} else {
			print ("QPixmap is missing an gadget ID.")
		}
	}

	public convenience init (_ width: Int, _ height: Int) {
		self.init ()
		gadgetID = Conduit.pixmapWithSizeNew (width, height)
		if let gadgetID = gadgetID {
			QGadget.registerGadget (gadgetID, self)
		} else {
			print ("QPixmap is missing an gadget ID.")
		}
	}

	public func load (_ path: String) -> Bool {
		if let gadgetID = gadgetID {
			return Conduit.pixmapLoad (gadgetID, path)
		}
		return false
	}

	public func width () -> Int {
		if let gadgetID = gadgetID {
			return Conduit.pixmapWidth (gadgetID)
		}
		return 0 
	}
	public func height () -> Int {
		if let gadgetID = gadgetID {
			return Conduit.pixmapHeight (gadgetID)
		}
		return 0 
	}
	public func depth () -> Int {
		if let gadgetID = gadgetID {
			return Conduit.pixmapDepth (gadgetID)
		}
		return 0 
	}
}
