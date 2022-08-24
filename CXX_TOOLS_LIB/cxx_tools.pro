######################################################################
# Automatically generated by qmake (2.01a) Wed Aug 24 16:04:03 2022
######################################################################

INCLUDEPATH+=
LIBS+= 
CONFIG=release
DESTDIR=../libs
OBJECTS_DIR=intout
TEMPLATE = lib
TARGET = cxx_tools
DEPENDPATH += . \
              CXXToolsInclude/fileIO \
              CXXToolsInclude/memoryMgmt \
              CXXToolsInclude/randGenerators \
              CXXToolsInclude/stdDefinitions \
              src/fileIO \
              src/memoryMgmt \
              src/randGenerators
INCLUDEPATH += . \
               CXXToolsInclude/fileIO \
               CXXToolsInclude/memoryMgmt \
               CXXToolsInclude/randGenerators

# Input
HEADERS += CXXToolsInclude/fileIO/rawbytesrw.h \
           CXXToolsInclude/memoryMgmt/arraycopy.h \
           CXXToolsInclude/memoryMgmt/arrayinitalize.h \
           CXXToolsInclude/memoryMgmt/arrayvalidate.h \
           CXXToolsInclude/memoryMgmt/dynamic2darray.h \
           CXXToolsInclude/randGenerators/randomc.h \
           CXXToolsInclude/randGenerators/sfmt.h \
           CXXToolsInclude/stdDefinitions/pstdint.h
SOURCES += src/fileIO/rawbytesrw.cpp \
           src/memoryMgmt/arrayvalidate.cpp \
           src/memoryMgmt/dynamic2darray.cpp \
           src/randGenerators/mersenne.cpp \
           src/randGenerators/mother.cpp \
           src/randGenerators/sfmt.cpp
