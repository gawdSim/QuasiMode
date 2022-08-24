NAME = libcxx_tools

CC = gcc

DEFINES = 
#-DINTELCC

CFLAGS = $(DEFINES) -O3 -fpic

RM = rm

INTELLIBPATH = 
#/opt/intel/Compiler/11.1/072/lib/intel64
INTELLIBS = 
#$(INTELLIBPATH)/libirc.so $(INTELLIBPATH)/libcxaguard.so $(INTELLIBPATH)/libimf.so

INCPATH = ./CXXToolsInclude
RANDGENIP = $(INCPATH)/randGenerators
MEMMGMTIP = $(INCPATH)/memoryMgmt
FILEIOIP = $(INCPATH)/fileIO
STDDEFIP = $(INCPATH)/stdDefinitions

DEPLIBPATH = ../libs
DEPLIBS = 

SRCPATH = ./src
RANDGENSP = $(SRCPATH)/randGenerators
MEMMGMTSP = $(SRCPATH)/memoryMgmt
FILEIOSP = $(SRCPATH)/fileIO

OUTPATH = ./intout
LIBPATH = ./lib

RANDGENINC = $(RANDGENIP)/randomc.h $(RANDGENIP)/sfmt.h
MEMMGMTINC = $(MEMMGMTIP)/dynamic2darray.h $(MEMMGMTIP)/arrayvalidate.h
FILEIOINC = $(FILEIOIP)/rawbytesrw.h
STDDEFINC = $(STDDEFIP)/pstdint.h
INC = $(RANDGENINC) $(MEMMGMTINC) $(FILEIOINC) $(STDDEFINC)

RANDGENSRC = $(RANDGENSP)/mersenne.cpp $(RANDGENSP)/mother.cpp $(RANDGENSP)/sfmt.cpp
MEMMGMTSRC = $(MEMMGMTSP)/dynamic2darray.cpp $(MEMMGMTSP)/arrayvalidate.cpp
FILEIOSRC = $(FILEIOSP)/rawbytesrw.cpp
SRC = $(RANDGENSRC) $(MEMMGMTSRC) $(FILEIOSRC)

RANDGENOBJ = $(OUTPATH)/mersenne.obj $(OUTPATH)/mother.obj $(OUTPATH)/sfmt.obj
MEMMGMTOBJ = $(OUTPATH)/dynamic2darray.obj $(OUTPATH)/arrayvalidate.obj
FILEIOOBJ = $(OUTPATH)/rawbytesrw.obj
OBJ = $(RANDGENOBJ) $(MEMMGMTOBJ) $(FILEIOOBJ)

lib: obj
	-$(CC) -g $(OBJ) $(INTELLIBS) -o $(LIBPATH)/$(NAME).so
	-ln -sfn ../CXX_TOOLS_LIB/$(LIBPATH)/$(NAME).so $(DEPLIBPATH)/

obj: randgenobj memmgmtobj fileioobj
	
randgenobj: $(RANDGENINC) $(RANDGENSRC)
	-$(CC) $(CFLAGS) -c $(RANDGENSP)/mersenne.cpp -o $(OUTPATH)/mersenne.obj
	-$(CC) $(CFLAGS) -c $(RANDGENSP)/mother.cpp -o $(OUTPATH)/mother.obj
	-$(CC) $(CFLAGS) -c $(RANDGENSP)/sfmt.cpp -o $(OUTPATH)/sfmt.obj

memmgmtobj: $(MEMMGMTINC) $(MEMMGMTSRC)
	-$(CC) $(CFLAGS) -c $(MEMMGMTSP)/dynamic2darray.cpp -o $(OUTPATH)/dynamic2darray.obj
	-$(CC) $(CFLAGS) -c $(MEMMGMTSP)/arrayvalidate.cpp -o $(OUTPATH)/arrayvalidate.obj
	
fileioobj: $(FILEIOINC) $(FILEIOSRC)
	-$(CC) $(CFLAGS) -c $(FILEIOSP)/rawbytesrw.cpp -o $(OUTPATH)/rawbytesrw.obj	
	
cleanall: cleanlib cleanobj
	
cleanobj:
	-$(RM) $(OBJ)

cleanlib:
	-$(RM) $(LIBPATH)/$(NAME).so

	
