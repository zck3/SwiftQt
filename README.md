
# SwiftQt 

By Zack T Smith, 3 at zs3 dot me         

## What is this?

This is a library for creating Swift Qt 6 GUI applications on GNU/Linux 
and other operating systems.                              

If you want to create a Swift GUI application for an OS such as Linux, 
you cannot use Apple's SwiftUI or AppKit because these only exist on Apple's platforms. 

You'll have to use a library such as SwiftQt.

## Is this for imperative or declarative UIs?

SwiftQt began as a solely imperative UI library.

Lately I'm adding a new layer for declarative UIs, currently embodied in the 
`DeclarativeUI` class.

Qt does have a native declarative UI capability called `QML`, 
but that is not what I'm using. My creation is more similar to the syntax of `SwiftUI`.

Nokia release QML in 2009 and Apple released in 2019. I'm working on mine in 2026.

## How the imperative UI works

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

## How the declarative UI works

Because I'm coding in Swift and I want a syntax like that of SwiftUI,
the language determines the approach. It is based on 
Swift protocols, structs, and the @resultBuilder functionality.

At present, DeclarativeUI is in a very early stage, pre-alpha.
It doesn't yet have a ''differ'' nor proper management of state.
It just builds a GUI based on the specified View hierarchy.

## Package.swift

Writing a proper `Package.swift` was challenging, because as of Swift 6.2, 
mixed-language projects were still not completely supported.
But it was not impossible.

## Compiling 

To use SwiftQt, you should write a `Package.swift` for your application 
that references SwiftQt on Github. SPM will automatically fetch and compile 
SwiftQt's code and link it with your app.

Refer to one of my sample apps for an example of this is done:
* [https://github.com/zck3/SampleSwiftQtApp] SampleSwiftQtApp
* [https://github.com/zck3/zCalculator] zCalculator

## Dependencies

* The Swift compiler, 6.2 or better.
* Qt 6, with all of its packages.
* A C++ compiler such as Clang or G++.

The `configure` script ensures the dependencies are installed.

## Compiler 

The Swift compiler is available at 
[here] https://www.swift.org/install/linux/
or you can compile it yourself, as I've done.

You can build SwiftQt by itself as follows:

1. `cd SwiftQt`
2. `./configure` 
3. `swift build` 

I'll provide a sample application separately from the library.

## Future

SwiftQt is a work in progress and still in the alpha stage of development.
There is much yet to be done.

Currently I need to have more Qt classes represented in Swift.

* QMediaPlayer
* QTabWidget
* QFileDialog
* QTimer
* QDateTime
* Qt-enclosed OpenGL window
* Video playback support
* QPainter for command-line terminal UI.
* QGraphicsView, QGraphicsScene, QGraphicsPixmapItem for zoomable/pannable image viewer.
* Declarative UI.

