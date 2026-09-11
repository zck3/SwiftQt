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
public class QTextEdit : QWidget {
	public var formatChangedHandler: ()->Void = {
	}
	public var cursorMovedHandler: ()->Void = {
	}
	public var modifiedHandler: ()->Void = {
	}
	public var textChangedHandler: ()->Void = {
	}
	//----------

	public convenience init (_ parent: QMainWindow) {
		self.init ()
		if let windowID = parent.widgetID {
			let id = Conduit.textEditNew (windowID)
			if id != 0 {
				self.widgetID = id
				QWidget.registerWidget (id, self)
			} else {
				fatalError("Unable to instantiate a QTextEdit.")
			}
		}
	}

	deinit {
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

	public func setReadOnly (_ readOnly: Bool) {
		if let widgetID = widgetID {
			Conduit.textEditSetReadOnly (widgetID, readOnly)
		}
	}

	public func isReadOnly () -> Bool {
		if let widgetID = widgetID {
			return Conduit.textEditIsReadOnly (widgetID)
		}
		return false
	}

	public func setAlignment (_ value: Int) {
		if let widgetID = widgetID {
			Conduit.textEditSetAlignment (widgetID, value)
		}
	}

	public func alignment () -> Int {
		if let widgetID = widgetID {
			return Conduit.textEditAlignment (widgetID)
		}
		return 0
	}

	public func verticalScrollBar () -> QScrollBar? {
		if let widgetID = widgetID {
			let scrollbarID = Conduit.textEditVerticalScrollBar (widgetID)
			return QScrollBar(withID: scrollbarID)
		}
		return nil
	}

	public func horizontalScrollBar () -> QScrollBar? {
		if let widgetID = widgetID {
			let scrollbarID = Conduit.textEditHorizontalScrollBar (widgetID)
			return QScrollBar(withID: scrollbarID)
		}
		return nil
	}

	/* Convenience function.
	 */
	public func scrollToBottom () {
		if let widgetID = widgetID {
			Conduit.textEditScrollToBottom (widgetID)
		}
	}
}
