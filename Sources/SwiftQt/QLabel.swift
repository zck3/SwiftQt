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
// QLabel.swift

@MainActor
public class QLabel : QWidget{
	public convenience init (_ parent: QWidget, _ text: String?) {
		self.init ()
		if let parentID = parent.widgetID {
			widgetID = Conduit.labelNew (parentID, text ?? "")
			QWidget.registerWidget (widgetID!, self)
		}
	}

	public override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
			case QSignalLabelHovered:
				print ("QLabel hover event."); // TODO

			default: 
				print ("QLabel unknown event.");
		}
		return 0
	}

	public func clear () {
		if let widgetID = widgetID {
			Conduit.labelClear (widgetID)
		}
	}
	public func text () -> String {
		if let widgetID = widgetID {
			let unsafeString : UnsafePointer<CChar>? = Conduit.labelText (widgetID)
			if let unsafeString = unsafeString {
				let safeString : String = String (cString:unsafeString);
				unsafeString.deallocate()
				return safeString
			}
		}
		return ""
	}
	public func setText (_ text: String) {
		if let widgetID = widgetID {
			Conduit.labelSetText (widgetID, text)
		}
	}
	public func setImage (_ image: QImage) {
		if let widgetID = widgetID, let imageID = image.objectID {
			Conduit.labelSetImage (widgetID, imageID)
		}
	}
	public func setPixmap (_ pixmap: QPixmap) {
		if let widgetID = widgetID, let pixmapID = pixmap.objectID {
			Conduit.labelSetPixmap (widgetID, pixmapID)
		}
	}

	public func wordWrap () -> Bool {
		if let widgetID = widgetID {
			return Conduit.labelWordWrap (widgetID)
		}
		return false
	}
	public func setWordWrap (_ value: Bool) {
		if let widgetID = widgetID {
			return Conduit.labelSetWordWrap (widgetID, value)
		}
	}
	public func indent () -> Int {
		if let widgetID = widgetID {
			return Conduit.labelIndent (widgetID)
		}
		return 0
	}
	public func setIndent (_ value: Int) {
		if let widgetID = widgetID {
			return Conduit.labelSetIndent (widgetID, value)
		}
	}
	public func margin () -> Int {
		if let widgetID = widgetID {
			return Conduit.labelMargin (widgetID)
		}
		return 0
	}
	public func setMargin (_ value: Int) {
		if let widgetID = widgetID {
			return Conduit.labelSetMargin (widgetID, value)
		}
	}
	public func alignment () -> Int {
		if let widgetID = widgetID {
			return Conduit.labelAlignment (widgetID)
		}
		return Qt.AlignNone
	}
	public func setAlignment (_ value: Int) {
		if let widgetID = widgetID {
			return Conduit.labelSetAlignment (widgetID, value)
		}
	}
}
