#=========================================================================
# This file is a part of SwiftQt.
# (C) 2023, 2024, 2026 Zack T Smith.
#
# This is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this software.  If not, see <http://www.gnu.org/licenses/>.

# The author may be reached at 3 at zs3 dot me.
#=========================================================================
#
# SwiftQt
# 

# This script generates the MOC C++ file that is needed 
# to support Qt's signals and slots, etc.

QT_INC=/usr/include/x86_64-linux-gnu/qt6/
QT_LIB=/usr/lib/x86_64-linux-gnu/qt6/
MOC=/usr/lib/qt6/libexec/moc

SRC=Sources/Cpp/
INC=Sources/Cpp/include/
DUMMY=$QT_LIB/mkspecs/features/data/dummy.cpp
DEST=Sources/Cpp/

input=qt-c++.h
intermediate=moc_predefs.h
output=moc_qt.cpp

clang -g -O2 -Wall -Wextra -dM -E -o $intermediate $DUMMY

$MOC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB --include $intermediate -I$QT_LIB/mkspecs/linux-g++ -I. -I$QT_INC -I$QT_INC/QtWidgets -I$QT_INC/QtGui -I$QT_INC/QtCore -I/usr/include/c++/10 -I/usr/include/aarch64-linux-gnu/c++/10 -I/usr/include/c++/10/backward -I/usr/lib/gcc/aarch64-linux-gnu/10/include -I/usr/local/include -I/usr/include/aarch64-linux-gnu -I/usr/include $INC/$input -o $DEST/$output

rm -f $intermediate
