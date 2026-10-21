/*=========================================================================
 * This implements a declarative UI on top of SwiftQt.
 * This file (C) 2026 Zack T Smith.
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

// RULES
// 1. The UI is expressed in the form of a closure.
// 2. Whenever the UI's state changes, this closure needs to be re-executed.
// 3. The closure is comprised of initializers for non-mutating structs.
// 4. The closure generates an immutable struct View hierarchy.
// 5. The immutable View hierarchy is what generates the QWidget hierarchy.
// 6. Closures superficially appear to contain lists of initializers;
//    this curious syntax is implemented using @resultBuilder.
// 7. If there are going to be multiple function parameters, you apply the builder macro
//    to the specific content closure parameter rather than the function.
// 8. In this scheme, "View" is a protocol, not a struct.
// 9. It is not necessary to have both buildBlock and buildPartialBlock; 
//    just the former will do. LLMs recommend a plethora of unnecessary builder functions.
// 10. Only structs that have multiple subviews need a _subviews property e.g. VStack.
// 11. Most structs are leaves e.g. Text, Label, Form, Button.

// NOTES
// * This is a pre-alpha version of the code, there is no diffing.
// * An associatedtype in a protocol is not inherited, so conforming types must add it.
// * Starting with Swift 5.7, a protocol that is used as a value type should use "any".

import CShim
import Foundation

@MainActor
public protocol View {
	func makeWidget (_ parent: QWidget) -> QWidget

	var _style: String { get }
	var _font: QFont { get }
	var _maximumWidth: Int { get }
	var _maximumHeight: Int { get }

	func subviews () -> [any View]
}

@MainActor
public protocol ComparableView: View 
{
	func isEqual (to other: any ComparableView) -> Bool
}

public extension ComparableView 
{
	func isEqual(to other: any ComparableView) -> Bool {
		return false
		//(other as? Self).map { $0 == self } ?? false
	}
}

@resultBuilder
public enum ViewBuilder {
	public static func buildBlock(_ components: any View...) -> [any View] {
		components
	}
}

public struct Font {
	var family: String = ""
	var size: Int = 0

	public init (_ family: String, size: Int) {
		self.family = family
		self.size = size
	}
}

public typealias Color = UInt
public extension Color {
	static let green: UInt = 0x00ff00
	static let blue: UInt = 0x0000ff
	static let lightCyan: UInt = 0xe0ffff

	func make(_ red: UInt, _ green: UInt, _ blue: UInt) -> Color {
		return ((red & 0xff) << 16) | ((green & 0xff) << 8) | (blue & 0xff)
	}
}

let MAX_DIMENSION = Int.max
let FLEXIBLE_HEIGHT = 999 

@MainActor
public struct Form : ComparableView 
{
	public var _placeholder: String = ""
	public var _text: String = ""
	public var _style: String = ""
	public var _font: QFont = QFont()
	public var _maximumWidth: Int = MAX_DIMENSION
	public var _maximumHeight: Int = MAX_DIMENSION

	public func subviews () -> [any View] {
		return []
	}

	public init () {
	}

	public init (_ text: String, _ placeholder: String = "") {
		self._text = text
		self._placeholder = placeholder
	}

	public func makeWidget (_ parent: QWidget) -> QWidget { 
		let widget = QLineEdit(_text, parent) 
		if _font.family.length > 0 || _font.modified {
			widget.setFont(_font)
		}
		if _style.length > 0 {
			widget.setStyleSheet(_style)
		}
		return widget
	}

	public func font(_ value: Font) -> Self {
		var copy = self
		var qfont = QFont()
		qfont.family = value.family
		qfont.pointSize = value.size
		copy._font = qfont
		return copy
	}

	public func bold() -> Self {
		var copy = self
		var qfont: QFont = copy._font
		qfont.weight = Qt.WeightBold
		qfont.modified = true
		copy._font = qfont
		return copy
	}

	public func italic() -> Self {
		var copy = self
		var qfont: QFont = copy._font
		qfont.italic = true
		qfont.modified = true
		copy._font = qfont
		return copy
	}

	public func foregroundColor(_ value: Color) -> Self {
		var copy = self
		let hex : String
		if value > 0xffffff {
			hex = String(format:"color: #%08X;", value)
		} else {
			hex = String(format:"color: #%06X;", value)
		}
		copy._style += hex
		return copy
	}
}

@MainActor
public struct Text: ComparableView 
{
	public var _text: String = ""
	public var _style: String = ""
	public var _font: QFont = QFont()
	public var _maximumWidth: Int = MAX_DIMENSION
	public var _maximumHeight: Int = MAX_DIMENSION
	
	public func subviews () -> [any View] {
		return []
	}

	public init () {
	}

	public init (_ text: String) {
		self._text = text
	}

	public func makeWidget (_ parent: QWidget) -> QWidget { 
		let widget = QTextEdit(_text, parent) 
		if _font.family.length > 0 || _font.modified {
			widget.setFont(_font)
		}
		if _style.length > 0 {
			widget.setStyleSheet(_style)
		}
		return widget
	}

	public func text(_ value: String) -> Text {
		var copy = self
		copy._text = value
		return copy
	}

	public func style(_ value: String) -> Self {
		var copy = self
		copy._style = value
		return copy
	}

	public func foregroundColor(_ value: Color) -> Self {
		var copy = self
		let hex : String
		if value > 0xffffff {
			hex = String(format:"color: #%08X;", value)
		} else {
			hex = String(format:"color: #%06X;", value)
		}
		copy._style += hex
		return copy
	}

	public func font(_ value: Font) -> Self {
		var copy = self
		var qfont = QFont()
		qfont.family = value.family
		qfont.pointSize = value.size
		copy._font = qfont
		return copy
	}

	public func bold() -> Self {
		var copy = self
		var qfont: QFont = copy._font
		qfont.weight = Qt.WeightBold
		qfont.modified = true
		copy._font = qfont
		return copy
	}

	public func italic() -> Self {
		var copy = self
		var qfont: QFont = copy._font
		qfont.italic = true
		qfont.modified = true
		copy._font = qfont
		return copy
	}
}

@MainActor
public struct Label: ComparableView 
{
	public var _text: String = ""
	public var _style: String = ""
	public var _font: QFont = QFont()
	public var _maximumWidth: Int = MAX_DIMENSION
	public var _maximumHeight: Int = MAX_DIMENSION
	
	public func subviews () -> [any View] {
		return []
	}

	public init () {
	}

	public init (_ text: String) {
		self._text = text
	}

	public func makeWidget (_ parent: QWidget) -> QWidget { 
		let widget = QLabel(_text, parent) 
		if _font.family.length > 0 || _font.modified {
			widget.setFont(_font)
		}
		if _style.length > 0 {
			widget.setStyleSheet(_style)
		}
		return widget
	}

	public func font(_ value: Font) -> Self {
		var copy = self
		var qfont = QFont()
		qfont.family = value.family
		qfont.pointSize = value.size
		copy._font = qfont
		return copy
	}

	public func bold() -> Self {
		var copy = self
		var qfont: QFont = copy._font
		qfont.weight = Qt.WeightBold
		qfont.modified = true
		copy._font = qfont
		return copy
	}

	public func italic() -> Self {
		var copy = self
		var qfont: QFont = copy._font
		qfont.italic = true
		qfont.modified = true
		copy._font = qfont
		return copy
	}

	public func foregroundColor(_ value: Color) -> Self {
		var copy = self
		let hex : String
		if value > 0xffffff {
			hex = String(format:"color: #%08X;", value)
		} else {
			hex = String(format:"color: #%06X;", value)
		}
		copy._style += hex
		return copy
	}

}

@MainActor
public struct Button : ComparableView 
{
	public var _text: String = ""
	public var _style: String = ""
	public var _font: QFont = QFont()
	public var _maximumWidth: Int = MAX_DIMENSION
	public var _maximumHeight: Int = MAX_DIMENSION
        public var clickedClosure: ()->Void = { }
	
	public func subviews () -> [any View] {
		return []
	}

	public init () {
	}

	/* Simple initializer with text and callback.
	 */
	public init (_ text: String, _ clicked: @escaping ()->Void = {}) {
		self._text = text
		self.clickedClosure = clicked
	}

	/* TODO Complex initialzier with subview(s) i.e. text, images, icons
	 */
	public init (_ clicked: @escaping ()->Void, label: any View) {
		self._text = ""
		self.clickedClosure = clicked
	}

	public func makeWidget (_ parent: QWidget) -> QWidget { 
		let widget = QPushButton(_text, parent) 
		if _font.family.length > 0 || _font.modified {
			widget.setFont(_font)
		}
		if _style.length > 0 {
			widget.setStyleSheet(_style)
		}
		widget.clickedSlot = self.clickedClosure
		return widget
	}

	public func font(_ value: Font) -> Self {
		var copy = self
		var qfont = QFont()
		qfont.family = value.family
		qfont.pointSize = value.size
		copy._font = qfont
		return copy
	}

	public func bold() -> Self {
		var copy = self
		var qfont: QFont = copy._font
		qfont.weight = Qt.WeightBold
		qfont.modified = true
		copy._font = qfont
		return copy
	}

	public func italic() -> Self {
		var copy = self
		var qfont: QFont = copy._font
		qfont.italic = true
		qfont.modified = true
		copy._font = qfont
		return copy
	}

	public func foregroundColor(_ value: Color) -> Self {
		var copy = self
		let hex : String
		if value > 0xffffff {
			hex = String(format:"color: #%08X;", value)
		} else {
			hex = String(format:"color: #%06X;", value)
		}
		copy._style += hex
		return copy
	}
}

@MainActor
public struct VStack : View {
	var availableWidth : Int = 0
	var availableHeight : Int = 0
	var _subviews: [any View] = []
	var _spacing : Int = 0
	var backgroundColor: UInt?
	public var _font: QFont = QFont()
	public var _style: String = ""
	public var _maximumWidth: Int = MAX_DIMENSION
	public var _maximumHeight: Int = MAX_DIMENSION
	
	public func subviews () -> [any View] {
		return _subviews
	}

	public init (@ViewBuilder content: (() -> [any View])) {
		self._subviews = content()
		print ("VStack has \(_subviews.count) subviews")
		self.availableWidth = 0
		self.availableHeight = 0
		self._spacing = 0
		self._font = QFont()
		self._style = ""
	}

	public func makeWidget (_ parent: QWidget) -> QWidget { 
		let stack = QWidget (parent) 
		let layout = QVBoxLayout(stack)
		if _spacing > 0 {
			layout.setSpacing(_spacing)
		}
		if let bgcolor = backgroundColor {
			stack.setStyleSheet(String(format: "background-color: #%06x", bgcolor))
		}
		for view in _subviews {
			let widget = view.makeWidget(stack)
			layout.addWidget (widget)
		}
		return stack
	}

	public func spacing(_ value: Int) -> VStack {
		var copy : VStack = self
		copy._spacing = value
		return copy
	}

	public func background(_ value: Color) -> Self {
		var copy = self
		copy.backgroundColor = value
		return copy
	}
}

@MainActor
public struct HStack : View {
	var availableWidth : Int = 0
	var availableHeight : Int = 0
	var _subviews: [any View] = []
	var _spacing: Int = 0
	var backgroundColor: UInt?
	public var _style: String = ""
	public var _font: QFont = QFont()
	public var _maximumWidth: Int = MAX_DIMENSION
	public var _maximumHeight: Int = MAX_DIMENSION
	
	public func subviews () -> [any View] {
		return _subviews
	}

	public init (@ViewBuilder content: (() -> [any View])) {
		self._subviews = content()
		print ("HStack has \(_subviews.count) subviews")
		self.availableWidth = 0
		self.availableHeight = 0
		self._spacing = 0
		self._font = QFont()
		self._style = ""
	}

	public func makeWidget (_ parent: QWidget) -> QWidget { 
		let stack = QWidget (parent) 
		let layout = QHBoxLayout(stack)
		if _spacing > 0 {
			layout.setSpacing(_spacing)
		}
		if let bgcolor = backgroundColor {
			stack.setStyleSheet(String(format: "background-color: #%06x", bgcolor))
		}
		for view in _subviews {
			let widget = view.makeWidget(stack)
			layout.addWidget (widget)
		}
		return stack
	}

	public func spacing(_ value: Int) -> HStack {
		var copy : HStack = self
		copy._spacing = value
		return copy
	}

	public func background(_ value: Color) -> Self {
		var copy = self
		copy.backgroundColor = value
		return copy
	}
}

@MainActor
public struct UIDetails {
	public var window : QMainWindow? 
	public var state : [String: Any]
	public var body : (any View)?
	public init () {
		window = nil
		state = [String: Any]()
		body = nil
	}
	public init (_ window: QMainWindow, _ state: [String: Any], _ body: some View) {
		self.window = window
		self.state = state
		self.body = body
	}
}

@MainActor
public class DeclarativeUI 
{
	var window : QMainWindow?
	var state : [String: Any]
	public var body : (any View)?

	public init () {
		self.window = nil
		self.state = [:]
		self.body = nil
	}

	public convenience init (_ window: QMainWindow, _ details: UIDetails) {
		self.init()
		self.window = window
		state = details.state
		body = details.body
	}
}

