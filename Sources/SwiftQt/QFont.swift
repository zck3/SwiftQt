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

@MainActor
public struct QFont {
	var family: String
	var fixedPitch: Bool
	var italic: Bool
	var pixelSize: Int
	var pointSize: Int
	var strikeOut: Bool
	var underline: Bool 
	var weight: Int
	var modified: Bool

	func bold () -> Bool {
		return self.weight > Qt.WeightMedium
	}

	init () {
		family = ""
		fixedPitch = false
		italic = false
		pixelSize = 0
		pointSize = 0
		strikeOut = false
		underline = false
		weight = 0
		modified = false
	}

	public mutating func setUnderline (_ value : Bool) {
		self.underline = value
	}

	public mutating func setStrikeOut (_ value : Bool) {
		self.strikeOut = value
	}

	public mutating func setItalic (_ value : Bool) {
		self.italic = value
	}

	public mutating func setPointSize (_ value : Int) {
		self.pointSize = value
	}

	public mutating func setFamily (_ value : String) {
		self.family = value
	}

	public mutating func setWeight (_ value : Int) {
		switch value {
		case Qt.WeightThin,
		     Qt.WeightExtraLight,
		     Qt.WeightLight,
		     Qt.WeightNormal,
		     Qt.WeightMedium,
		     Qt.WeightDemiBold,
		     Qt.WeightBold,
		     Qt.WeightExtraBold,
		     Qt.WeightBlack:
			self.weight = value
		default:
			return
		}
	}
}

public extension QFont {
	init (_ family: String, _ size: Int, _ weight: Int, _ italic: Bool) {
		self.init()
		self.family = family
		self.pointSize = size
		self.weight = weight
		self.italic = italic
	}
}
