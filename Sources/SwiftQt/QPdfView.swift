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

// SwiftQt
// QPdfView.swift

@MainActor
public class QPdfView : QWidget {
	public convenience init (_ parent: QWidget) {
		self.init ()
		if let parentID = parent.widgetID {
			let id = Conduit.pdfViewNew (parentID)
			if id != 0 {
				self.widgetID = id
				QWidget.registerWidget (id, self)
			} else {
				fatalError("Unable to instantiate a QPdfView.")
			}
		}
	}

	public override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
			default: 
				print ("QPdfView unknown event.");
		}
		return 0
	}

	public func setDocument (_ document: QPdfDocument) {
		if let widgetID = widgetID, let documentID = document.objectID {
			Conduit.pdfViewSetDocument (widgetID, documentID)
		}
	}

	// TODO pdfview->setPageMode(QPdfView::PageMode::MultiPage);
	// TODO pdfview->setZoomMode(QPdfView::ZoomMode::FitToWidth);
}
