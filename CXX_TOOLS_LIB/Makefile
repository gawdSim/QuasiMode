#############################################################################
# Makefile for building: libcxx_tools.so.1.0.0
# Generated by qmake (2.01a) (Qt 4.8.7) on: Wed Jan 27 13:40:28 2021
# Project:  cxx_tools.pro
# Template: lib
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile cxx_tools.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -m64 -pipe -O2 -fPIC $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -fPIC $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I. -ICXXToolsInclude/fileIO -ICXXToolsInclude/memoryMgmt -ICXXToolsInclude/randGenerators
LINK          = g++
LFLAGS        = -m64 -Wl,-O1 -shared -Wl,-soname,libcxx_tools.so.1
LIBS          = $(SUBLIBS)    
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = intout/

####### Files

SOURCES       = src/fileIO/rawbytesrw.cpp \
		src/memoryMgmt/arrayvalidate.cpp \
		src/memoryMgmt/dynamic2darray.cpp \
		src/randGenerators/mersenne.cpp \
		src/randGenerators/mother.cpp \
		src/randGenerators/sfmt.cpp 
OBJECTS       = intout/rawbytesrw.o \
		intout/arrayvalidate.o \
		intout/dynamic2darray.o \
		intout/mersenne.o \
		intout/mother.o \
		intout/sfmt.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		cxx_tools.pro
QMAKE_TARGET  = cxx_tools
DESTDIR       = ../libs/
TARGET        = libcxx_tools.so.1.0.0
TARGETA       = ../libs/libcxx_tools.a
TARGETD       = libcxx_tools.so.1.0.0
TARGET0       = libcxx_tools.so
TARGET1       = libcxx_tools.so.1
TARGET2       = libcxx_tools.so.1.0

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile  ../libs/$(TARGET)

../libs/$(TARGET):  $(OBJECTS) $(SUBLIBS) $(OBJCOMP)  
	@$(CHK_DIR_EXISTS) ../libs/ || $(MKDIR) ../libs/ 
	-$(DEL_FILE) $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS) $(OBJCOMP)
	-ln -s $(TARGET) $(TARGET0)
	-ln -s $(TARGET) $(TARGET1)
	-ln -s $(TARGET) $(TARGET2)
	-$(DEL_FILE) ../libs/$(TARGET)
	-$(DEL_FILE) ../libs/$(TARGET0)
	-$(DEL_FILE) ../libs/$(TARGET1)
	-$(DEL_FILE) ../libs/$(TARGET2)
	-$(MOVE) $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2) ../libs/



staticlib: $(TARGETA)

$(TARGETA):  $(OBJECTS) $(OBJCOMP) 
	-$(DEL_FILE) $(TARGETA) 
	$(AR) $(TARGETA) $(OBJECTS)

Makefile: cxx_tools.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf
	$(QMAKE) -o Makefile cxx_tools.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
qmake:  FORCE
	@$(QMAKE) -o Makefile cxx_tools.pro

dist: 
	@$(CHK_DIR_EXISTS) intout/cxx_tools1.0.0 || $(MKDIR) intout/cxx_tools1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) intout/cxx_tools1.0.0/ && (cd `dirname intout/cxx_tools1.0.0` && $(TAR) cxx_tools1.0.0.tar cxx_tools1.0.0 && $(COMPRESS) cxx_tools1.0.0.tar) && $(MOVE) `dirname intout/cxx_tools1.0.0`/cxx_tools1.0.0.tar.gz . && $(DEL_FILE) -r intout/cxx_tools1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) ../libs/$(TARGET) 
	-$(DEL_FILE) ../libs/$(TARGET0) ../libs/$(TARGET1) ../libs/$(TARGET2) $(TARGETA)
	-$(DEL_FILE) Makefile


check: first

compiler_clean: 

####### Compile

intout/rawbytesrw.o: src/fileIO/rawbytesrw.cpp CXXToolsInclude/fileIO/rawbytesrw.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o intout/rawbytesrw.o src/fileIO/rawbytesrw.cpp

intout/arrayvalidate.o: src/memoryMgmt/arrayvalidate.cpp CXXToolsInclude/memoryMgmt/arrayvalidate.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o intout/arrayvalidate.o src/memoryMgmt/arrayvalidate.cpp

intout/dynamic2darray.o: src/memoryMgmt/dynamic2darray.cpp CXXToolsInclude/memoryMgmt/dynamic2darray.h \
		CXXToolsInclude/memoryMgmt/arrayvalidate.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o intout/dynamic2darray.o src/memoryMgmt/dynamic2darray.cpp

intout/mersenne.o: src/randGenerators/mersenne.cpp CXXToolsInclude/randGenerators/randomc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o intout/mersenne.o src/randGenerators/mersenne.cpp

intout/mother.o: src/randGenerators/mother.cpp CXXToolsInclude/randGenerators/randomc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o intout/mother.o src/randGenerators/mother.cpp

intout/sfmt.o: src/randGenerators/sfmt.cpp CXXToolsInclude/randGenerators/sfmt.h \
		CXXToolsInclude/randGenerators/randomc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o intout/sfmt.o src/randGenerators/sfmt.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

