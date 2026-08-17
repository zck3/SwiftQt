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

@MainActor
public class QTextEdit : QWidget{
	public var formatChangedHandler: ()->Void = {
		print ("QTextEdit format changed!");
	}
	public var cursorMovedHandler: ()->Void = {
		print ("QTextEdit cursor moved!");
	}
	public var modifiedHandler: ()->Void = {
		print ("QTextEdit modified!");
	}
	public var textChangedHandler: ()->Void = {
		print ("QTextEdit text changed!");
	}
	//----------

	public convenience init (_ parent: QMainWindow) {
		self.init ()
		if let windowID = parent.widgetID {
			widgetID = Conduit.textEditNew (windowID)
			QWidget.registerWidget (widgetID!, self)
		}
	}

	public override func processEvent (_ event: SQEvent) -> Int {
		switch (event.type) {
			case QSignalTextEditCharFormatChanged:
				formatChangedHandler()

			case QSignalTextEditCursorMoved:
				cursorMovedHandler()

			case QSignalTextEditModified:
				modifiedHandler()

			case QSignalTextEditTextChanged:
				textChangedHandler()

			default: 
				print ("QTextEdit unknown event.");
		}
		return 0
	}

	public func toPlainText () -> String {
		if let widgetID = widgetID {
			let unsafeString : UnsafePointer<CChar>? = Conduit.textEditToPlainText(widgetID)
			if let unsafeString = unsafeString {
				let safeString : String = String (cString:unsafeString);
				unsafeString.deallocate()
				return safeString
			}
		}
		return ""
	}

	public func toHtml () -> String {
		if let widgetID = widgetID {
			let unsafeString : UnsafePointer<CChar>? = Conduit.textEditToHTML(widgetID)
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
			Conduit.textEditSetText (widgetID, text)
		}
	}


}
