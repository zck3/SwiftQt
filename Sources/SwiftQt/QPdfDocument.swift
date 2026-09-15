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

@MainActor
public class QPdfDocument : QObject 
{
	public convenience init (_ parent: QObject) {
		self.init ()
		if let parentID = parent.objectID {
			// Case 1: Parent is a QObject, not descended from QWidget.
			let id = Conduit.pdfDocumentNew (parentID)
			if id != 0 {
				self.objectID = id
				QObject.registerObject (id, self)
			} else {
				fatalError("Unable to instantiate a QPdfDocument.")
			}
		}
		else if let widget = parent as? QWidget, let parentID = widget.widgetID {
			// Case 2: Parent is descended from QWidget.
			let id = Conduit.pdfDocumentNew (parentID)
			if id != 0 {
				self.objectID = id
				QObject.registerObject (id, self)
			} else {
				fatalError("Unable to instantiate a QPdfDocument.")
			}
		}
		else {
			print ("QPdfDocument invalid parent object.")
		}
	}

	public func load (_ filename: String) -> Int {
		if let objectID = self.objectID {
			return Conduit.pdfDocumentLoad (objectID, filename)
		}
		return 0
	}

	public func close () {
		if let objectID = self.objectID {
			Conduit.pdfDocumentClose (objectID)
		}
	}

	public func pageCount () -> Int {
		if let objectID = self.objectID {
			return Conduit.pdfDocumentPageCount (objectID)
		}
		return 0
	}
}
