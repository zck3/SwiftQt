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
// QApplication.swift

@MainActor
public class QApplication : QObject {

        public var aboutToQuitHandler: ()->Void = {
                print ("QApplication is exiting!");
        }

	public required convenience init (argc: Int, argv: [String]) {
		self.init ()

		print ("argc=\(argc), argv=\(argv)")

		//--------------------------------------------
		// Allocate C strings for the argv parameters.
		//
		var cStrings: [UnsafeMutablePointer<CChar>?] = []
		for argString in argv {
    			guard let c_str = argString.cString(using: .utf8) else {
				fatalError("String conversion failed")
			}
			let ptr = UnsafeMutablePointer<CChar>.allocate(capacity: c_str.count + 1)
			ptr.initialize(from: c_str, count: c_str.count)
			ptr[c_str.count] = 0
			cStrings.append(ptr)
		}
		let c_array = UnsafeMutablePointer<UnsafeMutablePointer<CChar>?>.allocate(capacity: cStrings.count)
		c_array.initialize(from: cStrings, count: cStrings.count)

		objectID = Conduit.applicationNew (argc, c_array)

		for ptr in cStrings {
			ptr?.deallocate()
		}
		c_array.deallocate()

		if let objectID = objectID {
			QObject.registerObject (objectID, self)
		} else {
			print ("QApplicaiton is missing an object ID.")
		}
	}

	public override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
		case QEventQuit:
			aboutToQuitHandler()
			break;

		default: 
			print ("QApplication unknown event type.");
		}
		return 0
	}

	deinit {
	}

	public static func exec () {
		Conduit.applicationExec()
	}

	public static func quit () {
		Conduit.applicationQuit()
	}

	public static func beep () {
		Conduit.applicationBeep()
	}

	public static func totalMainWindows () -> Int {
		return Conduit.applicationTotalMainWindows ()
	}

}
