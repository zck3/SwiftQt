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
public class QObjectStorage{
	static let shared = QObjectStorage()

	private var objects: [ObjectID: QObject] = [:]

	public func object(id: ObjectID) -> QObject? {
		return objects[id]
	}

	public func register(object: QObject, id: ObjectID) {
		objects[id] = object
	}

	public func unregister(id: ObjectID) {
		objects.removeValue(forKey: id)
	}
}

@MainActor
open class QObject 
{
	var objectID : ObjectID?

	public static func isKnownObject (_ objectID: ObjectID) -> Bool {
		return QObjectStorage.shared.object(id: objectID) != nil
	}

	public static func lookupObject (_ objectID: ObjectID) -> QObject? {
		return QObjectStorage.shared.object(id: objectID) 
	}

	public static func registerObject (_ objectID: ObjectID, _ object: QObject) {
		QObjectStorage.shared.register (object: object, id: objectID)
	}

	public static func unregisterObject (_ objectID: ObjectID) {
		QObjectStorage.shared.unregister (id: objectID)
	}

	public init () {

	}

	deinit {

	}

	open func processEvent (_ event: SQEvent) -> Int
	{
		return 0
	}
}
