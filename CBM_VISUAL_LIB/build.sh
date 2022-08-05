#!/bin/bash
set -e

CBM_INC="../CXX_TOOLS_LIB/"
CBM_LIB_PATH="-L../libs"
CBM_LIB="-lcxx_tools"

QT_INC="/opt/apps/qt/4.7.0/include /usr/local/Trolltech/Qt-4.7.2/include /usr/include/qt4"
QT_LIB_PATH="-L/opt/apps/qt/4.7.0/lib -L/usr/local/Trolltech/Qt-4.7.2/lib -L/usr/lib/qt4"
QT_LIB="-lQtGui -lQtCore"

INC_PATH="$CBM_INC $QT_INC"
LIB_PATH="$CBM_LIB_PATH $QT_LIB_PATH"
LIBS="$CBM_LIB $QT_LIB"

make -f linux.mk
make -f linux.mk cleanall

# Create the project file. Use CONFIG="debug" to debug
qmake -project -t lib INCLUDEPATH+="$INC_PATH" LIBS+="$LIB_PATH $LIBS" CONFIG="release" DESTDIR="../libs" OBJECTS_DIR="intout" -o cbm_visual.pro
# Create the makefile
qmake 
# Make the code
make
