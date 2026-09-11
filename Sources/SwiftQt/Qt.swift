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

	// Qt::AnchorPoint
	public static let AnchorLeft = 0
	public static let AnchorHorizontalCenter = 1
	public static let AnchorRight = 2
	public static let AnchorTop = 3
	public static let AnchorVerticalCenter	= 4
	public static let AnchorBottom	= 5

	// Qt::Orientation
	public static let Horizontal = 1
	public static let Vertical = 2

	// Qt::ArrowType
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

	// Qt::Modifier
        public static let NoModifier = 0x00000000
        public static let ShiftModifier = 0x02000000
        public static let ControlModifier = 0x04000000
        public static let AltModifier = 0x08000000
        public static let MetaModifier = 0x10000000
        public static let KeypadModifier = 0x20000000
        public static let GroupSwitchModifier = 0x40000000

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

	// Qt::ScrollBarPolicy
	public static let ScrollBarAsNeeded = 0
	public static let ScrollBarAlwaysOff = 1
	public static let ScrollBarAlwaysOn = 2

	// Qt::ItemFlags
	public static let NoItemFlags = 0
	public static let ItemIsSelectable = 1
	public static let ItemIsEditable = 2
	public static let ItemIsDragEnabled = 4
	public static let ItemIsDropEnabled = 8
	public static let ItemIsUserCheckable = 16
	public static let ItemIsEnabled = 32
	public static let ItemIsTristate = 64

	// QPdfDocument::Error
	public static let PdfNone = 0
	public static let PdfUnknown = 1
	public static let PdfDataNotYetAvailable = 2
	public static let PdfFileNotFound = 3
	public static let PdfInvalidFileFormat = 4
	public static let PdfIncorrectPassword = 5
	public static let PdfUnsupportedSecurityScheme = 6

	// Key codes
	public static let Key_Space = 0x20
	public static let Key_Any = Key_Space
	public static let Key_Exclam = 0x21
	public static let Key_QuoteDbl = 0x22
	public static let Key_NumberSign = 0x23
	public static let Key_Dollar = 0x24
	public static let Key_Percent = 0x25
	public static let Key_Ampersand = 0x26
	public static let Key_Apostrophe = 0x27
	public static let Key_ParenLeft = 0x28
	public static let Key_ParenRight = 0x29
	public static let Key_Asterisk = 0x2a
	public static let Key_Plus = 0x2b
	public static let Key_Comma = 0x2c
	public static let Key_Minus = 0x2d
	public static let Key_Period = 0x2e
	public static let Key_Slash = 0x2f
	public static let Key_0 = 0x30
	public static let Key_1 = 0x31
	public static let Key_2 = 0x32
	public static let Key_3 = 0x33
	public static let Key_4 = 0x34
	public static let Key_5 = 0x35
	public static let Key_6 = 0x36
	public static let Key_7 = 0x37
	public static let Key_8 = 0x38
	public static let Key_9 = 0x39
	public static let Key_Colon = 0x3a
	public static let Key_Semicolon = 0x3b
	public static let Key_Less = 0x3c
	public static let Key_Equal = 0x3d
	public static let Key_Greater = 0x3e
	public static let Key_Question = 0x3f
	public static let Key_At = 0x40
	public static let Key_A = 0x41
	public static let Key_B = 0x42
	public static let Key_C = 0x43
	public static let Key_D = 0x44
	public static let Key_E = 0x45
	public static let Key_F = 0x46
	public static let Key_G = 0x47
	public static let Key_H = 0x48
	public static let Key_I = 0x49
	public static let Key_J = 0x4a
	public static let Key_K = 0x4b
	public static let Key_L = 0x4c
	public static let Key_M = 0x4d
	public static let Key_N = 0x4e
	public static let Key_O = 0x4f
	public static let Key_P = 0x50
	public static let Key_Q = 0x51
	public static let Key_R = 0x52
	public static let Key_S = 0x53
	public static let Key_T = 0x54
	public static let Key_U = 0x55
	public static let Key_V = 0x56
	public static let Key_W = 0x57
	public static let Key_X = 0x58
	public static let Key_Y = 0x59
	public static let Key_Z = 0x5a
	public static let Key_BracketLeft = 0x5b
	public static let Key_Backslash = 0x5c
	public static let Key_BracketRight = 0x5d
	public static let Key_AsciiCircum = 0x5e
	public static let Key_Underscore = 0x5f
	public static let Key_QuoteLeft = 0x60
	public static let Key_BraceLeft = 0x7b
	public static let Key_Bar = 0x7c
	public static let Key_BraceRight = 0x7d
	public static let Key_AsciiTilde = 0x7e
	public static let Key_Escape = 0x01000000                
	public static let Key_Tab = 0x01000001
	public static let Key_Backtab = 0x01000002
	public static let Key_Backspace = 0x01000003
	public static let Key_Return = 0x01000004
	public static let Key_Enter = 0x01000005
	public static let Key_Insert = 0x01000006
	public static let Key_Delete = 0x01000007
	public static let Key_Pause = 0x01000008
	public static let Key_Print = 0x01000009               
	public static let Key_SysReq = 0x0100000a
	public static let Key_Clear = 0x0100000b
	public static let Key_Home = 0x01000010               
	public static let Key_End = 0x01000011
	public static let Key_Left = 0x01000012
	public static let Key_Up = 0x01000013
	public static let Key_Right = 0x01000014
	public static let Key_Down = 0x01000015
	public static let Key_PageUp = 0x01000016
	public static let Key_PageDown = 0x01000017
	public static let Key_Shift = 0x01000020             
	public static let Key_Control = 0x01000021
	public static let Key_Meta = 0x01000022
	public static let Key_Alt = 0x01000023
	public static let Key_CapsLock = 0x01000024
	public static let Key_NumLock = 0x01000025
	public static let Key_ScrollLock = 0x01000026
	public static let Key_F1 = 0x01000030               
	public static let Key_F2 = 0x01000031
	public static let Key_F3 = 0x01000032
	public static let Key_F4 = 0x01000033
	public static let Key_F5 = 0x01000034
	public static let Key_F6 = 0x01000035
	public static let Key_F7 = 0x01000036
	public static let Key_F8 = 0x01000037
	public static let Key_F9 = 0x01000038
	public static let Key_F10 = 0x01000039
	public static let Key_F11 = 0x0100003a
	public static let Key_F12 = 0x0100003b
	public static let Key_Super_L = 0x01000053                
	public static let Key_Super_R = 0x01000054
	public static let Key_Menu = 0x01000055
	public static let Key_Hyper_L = 0x01000056
	public static let Key_Hyper_R = 0x01000057
	public static let Key_Help = 0x01000058
	public static let Key_AltGr = 0x01001103
}

