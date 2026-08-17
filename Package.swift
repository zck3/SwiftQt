// swift-tools-version: 6.2
//===========================================================================
// This file is a part of SwiftQt.
// (C) 2026 Zack T Smith.
//
// This is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this software.  If not, see <http://www.gnu.org/licenses/>.
//
// The author may be reached at 3 at zs3 dot me.
//===========================================================================

import PackageDescription

let package = Package(
    name: "SwiftQt",
    platforms: [
        .iOS(.v15),
        .macOS(.v13)
    ],
    products: [
        .library(
            name: "SwiftQt",
	    type: .static,
            targets: ["SwiftQt", "CShim", "Cpp"]
        ),
    ],
    dependencies: [
    ],
    targets: [
	// C++ target
	.target(
		name: "Cpp",
		path: "Sources/Cpp",
		publicHeadersPath: "include",
		cxxSettings: [
                     .headerSearchPath("include"),
                     .unsafeFlags([
				"-std=c++17",

				// This keeps things relatively simple versus switching to scripts or cmake.
				"-I/usr/include/x86_64-linux-gnu/qt6/", // Debian x64
				"-I/usr/include/aarch64-linux-gnu/qt6/", // Debian aarch64 
				"-I/usr/include/riscv64-linux-gnu/qt6/", // Debian riscv64
				"-I/usr/include/qt6/", // Fedora, Arch, Gentoo x64
			])
		]
	       ),

	// C target
	.target(
		name: "CShim",
		dependencies: ["Cpp"],
		path: "Sources/CShim",
		publicHeadersPath: "include",
		cSettings: [
                     .unsafeFlags([ ]),
                     .headerSearchPath("include"),
		]
	       ),

        // Swift target
        .target(
		name: "SwiftQt",
		dependencies: ["CShim", "Cpp"],
		path: "Sources/SwiftQt",
		swiftSettings: [
			.interoperabilityMode(.Cxx),
		],
		linkerSettings: [.unsafeFlags([ 
			"-L/usr/lib/x86_64-linux-gnu/",  // Debian Intel/AMD64
			"-L/usr/lib/aarch64-linux-gnu/", // Debian ARM 64
			"-L/usr/lib/riscv64-linux-gnu/", // Debian RISC-V
			"-lQt6Core",
			"-lQt6Gui",
			"-lQt6Network",
			"-lQt6Positioning",
			"-lQt6PrintSupport",
			"-lQt6Qml",
			"-lQt6QmlModels",
			"-lQt6Quick",
			"-lQt6WebChannel",
			"-lQt6WebChannelQuick",
			"-lQt6WebEngineCore",
			"-lQt6WebEngineQuick",
			"-lQt6WebEngineWidgets",
			"-lQt6Widgets",
		])], 
        ),

        // Test target
//        .testTarget(
//            name: "SwiftQtTests",
//            dependencies: ["SwiftQt"],
//            path: "Tests/SwiftQtTests"
//        ),
    ]
)
