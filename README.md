
# SwiftQt 

By Zack T Smith, 3 at zs3 dot me         

## What is this?

This is a library for creating Swift Qt 6 GUI applications on GNU/Linux 
and other operating systems.                              

If you want to create a Swift GUI application on an OS such as Linux, 
you cannot use Apple's SwiftUI or AppKit because these only exist on Apple's platforms. 

You'll have to use a library such as SwiftQt.

## What is this not?

SwiftQt is currently not an attempt at producing an open-source equivalent of `SwiftUI`, 
which is the declarative GUI building system that Apple released around 2019.

Nor is SwiftQt an attempt to create a Swift variant of `QML`, which is Qt's
declarative GUI building system introduced by Nokia in 2009.

## Implementation details

First, to let Swift interact with Qt requires writing two mechanisms, one to let Swift
code talk to the underlying C++ code via a C shim layer, and another to let C++ 
talk to the Swift side.

On the Swift side, equivalent classes must be written for each of the 
Qt classes and methods that are deemed useful. There are numerous classes in Qt.
I support a subset that may grow over time.

Qt 6 has some C++ value types that must be translated into Swift value types
and vice versa. It also has some very simple classes that are effectively 
value types (e.g. `QDate`) that I implement as Swift value types.

Swift object lifetimes have to match those of the C++ objects they are representing.
Thus C++ needs to tell Swift whenever it deletes an object so that the Swift side
can deinit its equivalent.

Qt has its quirks, specifically ''signals and slots'' for class-specific GUI events and 
concomitant callbacks. In SwiftQt, I implemented signals internally as events 
and the slots are Swift closures.

Note that Swift's C++ interoperability feature cannot be used for SwiftQt, 
because it is geared toward simpler C++ code. It wouldn't be able to understand
Qt's expansive C++ codebase, nor its MOC files and signals and slots.

## Package.swift

Writing a proper `Package.swift` was challenging, because as of Swift 6.2, 
mixed-language projects were still not completely supported.
But it was not impossible.

## Compiling 

To use SwiftQt, you should write a `Package.swift` for your application 
that references SwiftQt on Github. SPM will automatically fetch and compile 
SwiftQt's code and link it with your app.

SwiftQt depends on:

* The Swift compiler, 6.2 or better.
* Qt 6, with all of its packages.
* A C++ compiler such as Clang or G++.

The `configure` script ensures the dependencies are installed.

The Swift compiler is available at 
[here] https://www.swift.org/install/linux/
or you can compile it yourself, as I did.

You can build SwiftQt by itself as follows:

1. `cd SwiftQt`
2. `./configure` 
3. `swift build` 

I'll provide a sample application separately from the library.

## Future

SwiftQt is a work in progress and still in the alpha stage of development.
There is much yet to be done.

Shall I attempt a declarative UI some day? Time will tell.

Currently I need to have more Qt classes represented in Swift.

* QMediaPlayer
* QTabWidget
* QPdfDocument, QPdfView
* QFileDialog
* QTimer
* QDateTime
* Qt-enclosed OpenGL window
* Video playback support
* QGraphicsView, QGraphicsScene, QGraphicsPixmapItem for zoomable/pannable image viewer.
* Struct traversal for declarative UI.

