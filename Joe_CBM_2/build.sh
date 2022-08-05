#!/bin/bash
set -e

LD_LIBRARY_PATH="../libs"


CBM_INC="../CXX_TOOLS_LIB/ ../CBM_STATE_LIB ../CBM_DATA_LIB/ ../CBM_CORE_LIB ../CBM_TOOLS_LIB"
CUDA_INC="/usr/local/cuda/include/"
CBM_LIB_PATH="-L../libs"
CBM_LIB="-lcxx_tools -lcbm_state -lcbm_data -lcbm_core -lcbm_tools"

INC_PATH="$CBM_INC $CUDA_INC"
LIB_PATH="$CBM_LIB_PATH"
LIBS="$CBM_LIB"

# Create the project file.
qmake -project -t app INCLUDEPATH+="$INC_PATH" LIBS+="$LIB_PATH $LIBS" DESTDIR="." OBJECTS_DIR="objs" QMAKE_CXXFLAGS+="-std=c++11 -O3 -fopenmp -g" QMAKE_LFLAGS+="-Wl,-rpath,../libs/"
# Create the makefile
qmake 
# Make the code
make -j2 
