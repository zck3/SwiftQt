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

/* This is a parent class for Qt classes that are without a parent class,
 * such as QPainter.
 */

@MainActor
public class QGadgetStorage {
	static let shared = QGadgetStorage()

	private var gadgets: [GadgetID: QGadget] = [:]

	public func gadget(id: GadgetID) -> QGadget? {
		return gadgets[id]
	}

	public func register(gadget: QGadget, id: GadgetID) {
		gadgets[id] = gadget
	}

	public func unregister(id: GadgetID) {
		gadgets.removeValue(forKey: id)
	}
}

@MainActor
open class QGadget 
{
	var gadgetID : GadgetID?

	public static func isKnownGadget (_ gadgetID: GadgetID) -> Bool {
		return QGadgetStorage.shared.gadget(id: gadgetID) != nil
	}

	public static func lookupGadget (_ gadgetID: GadgetID) -> QGadget? {
		return QGadgetStorage.shared.gadget(id: gadgetID) 
	}

	public static func registerGadget (_ gadgetID: GadgetID, _ gadget: QGadget) {
		QGadgetStorage.shared.register (gadget: gadget, id: gadgetID)
	}

	public static func unregisterGadget (_ gadgetID: GadgetID) {
		QGadgetStorage.shared.unregister (id: gadgetID)
	}

	open func event (_ event: QEvent) -> Bool
	{
		switch (event.type) {
		default: 
			break
		}
		return false
	}
}
