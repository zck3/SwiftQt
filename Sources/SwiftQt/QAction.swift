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
// QAction.swift

@MainActor
public class QAction : QObject {
	public var triggeredHandler: ()->Void = {
		// RULE: Action handlers don't return anything.
	}

	public required convenience init (_ text: String, _ handler: @escaping ()->Void) {
		self.init ()
		let id = Conduit.actionNew (text)
		if id != 0 {
			self.objectID = id
			QObject.registerObject (id, self)
			triggeredHandler = handler
		} else {
			fatalError("Unable to instantiate a QAction.")
		}
	}

	public required convenience init (_ text: String) {
		self.init ()
		let id = Conduit.actionNew (text)
		if id != 0 {
			self.objectID = id
			QObject.registerObject (id, self)
		} else {
			fatalError("Unable to instantiate a QAction.")
		}
	}

	public override func event (_ event: QEvent) -> Bool {
		switch (event.type) {
			case QSignalActionTriggered:
				triggeredHandler ()

			// TODO
			// Changed
			// Hovered
			// Toggled
			default: 
				print ("QAction unknown event.");
		}
		return false
	}

	public func setShortcut (_ sequence: QKeySequence) {
		if let objectID = objectID {
			Conduit.actionSetShortcut (objectID, sequence)
		}
	}

	public func checked () -> Bool {
		// TODO
		return false
	}
	public func setChecked (_ value:Bool) {
		// TODO
	}
	public func enabled () -> Bool {
		// TODO
		return false
	}
	public func setEnabled (_ value:Bool) {
		// TODO
	}

}
