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
// QImage.swift

@MainActor
public class QImage : QGadget 
{
	public required convenience init (_ path: String?) {
		self.init ()
		let id = Conduit.imageNew (path ?? "")
		if id > 0 {
			gadgetID = id
			QGadget.registerGadget (id, self)
		} else {
			fatalError("Unable to instantiate a QImage.")
		}
	}

	public func load (_ path: String) -> Bool {
		if let gadgetID = gadgetID {
			return Conduit.imageLoad (gadgetID, path)
		}
		return false
	}

	public func width () -> Int {
		if let gadgetID = gadgetID {
			return Conduit.imageWidth (gadgetID)
		}
		return 0 
	}

	public func height () -> Int {
		if let gadgetID = gadgetID {
			return Conduit.imageHeight (gadgetID)
		}
		return 0 
	}

	public func depth () -> Int {
		if let gadgetID = gadgetID {
			return Conduit.imageDepth (gadgetID)
		}
		return 0 
	}

	public func isGrayscale () -> Bool {
		if let gadgetID = gadgetID {
			return Conduit.imageIsGrayscale (gadgetID)
		}
		return false 
	}

	public func setPixel(x: Int, y: Int, color: Int) {
		if let gadgetID = gadgetID {
			Conduit.imageSetPixel (gadgetID, x, y, color)
		}
	}
}
