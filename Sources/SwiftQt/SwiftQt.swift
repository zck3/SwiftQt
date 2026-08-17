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
import CShim

@MainActor
public class SwiftQt {
	public static let name = String(cString: SQReleaseName())
	public static let release = String(cString: SQReleaseString())
	public static let major : Int = SQReleaseMajor()
	public static let minor : Int = SQReleaseMinor()

	public static func isDarkMode () -> Bool {
		return Conduit.swiftQtIsDarkMode ();
	}

	public static func conveniencePopup (_ title: String, _ message: String) {
		Conduit.swiftQtConveniencePopup (title, message);
	}

	public static func infoPopup (_ message: String) {
		conveniencePopup ("Information", message);
	}

	public static func warningPopup (_ message: String) {
		conveniencePopup ("Warning", message);
	}

	public static func errorPopup (_ message: String) {
		conveniencePopup ("Error", message);
	}

	public static func yesNoQuestion (_ title: String, _ message: String) -> Bool {
		return Conduit.swiftQtConvenienceQuestion (title, message);
	}
}
