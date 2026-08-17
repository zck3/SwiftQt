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

import Foundation
@_exported import CShim

@MainActor
public class Qt {
	// Qt::Alignment
	public static let AlignNone = 0
	public static let AlignLeft = 1
	public static let AlignRight = 2
	public static let AlignCenter = 4
	public static let AlignJustify = 8
	public static let AlignTop = 0x20
	public static let AlignBottom = 0x40
	public static let AlignVCenter = 0x80
	public static let AlignMiddle = 0x80
	public static let AlignBaseline = 0x100

	public static let AnchorLeft = 0
	public static let AnchorHorizontalCenter = 1
	public static let AnchorRight = 2
	public static let AnchorTop = 3
	public static let AnchorVerticalCenter	= 4
	public static let AnchorBottom	= 5

	// Qt::Orientation
	public static let Horizontal = 1
	public static let Vertical = 2

	public static let NoArrow = 0
	public static let UpArrow = 1
	public static let DownArrow = 2
	public static let LeftArrow = 3
	public static let RightArrow = 4

	// QSizePolicy::PolicyFlag
	public static let GrowFlag = 1
	public static let ExpandFlag = 2
	public static let ShrinkFlag = 4
	public static let IgnoreFlag = 8

	// QSizePolicy::Policy
	public static let Fixed = 0
	public static let Minimum = GrowFlag
	public static let Maximum = ShrinkFlag
	public static let Preferred = GrowFlag | ShrinkFlag
	public static let Expanding = GrowFlag | ShrinkFlag | ExpandFlag
	public static let MinimumExpanding = GrowFlag | ExpandFlag
	public static let Ignored = ShrinkFlag | GrowFlag | IgnoreFlag

	// Qt::CheckState
	public static let Unchecked = 0
	public static let PartiallyChecked = 1
	public static let Checked = 2

	// Qt::DayOfWeek
	public static let Monday = 1
	public static let Tuesday = 2
	public static let Wednesday = 3
	public static let Thursday = 4
	public static let Friday = 5
	public static let Saturday = 6
	public static let Sunday = 7

	// Qt ItemFlags
	public static let NoItemFlags = 0
	public static let ItemIsSelectable = 1
	public static let ItemIsEditable = 2
	public static let ItemIsDragEnabled = 4
	public static let ItemIsDropEnabled = 8
	public static let ItemIsUserCheckable = 16
	public static let ItemIsEnabled = 32
	public static let ItemIsTristate = 64
}

