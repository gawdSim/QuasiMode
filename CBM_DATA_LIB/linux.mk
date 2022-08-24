#make simulation data library

NAME=libcbm_data

CC = gcc

DEFINES = -DINTELCC

CFLAGS = $(DEFINES) -O3 -fpic

rm = rm

CXXTOOLSIP = '../CXX_TOOLS_LIB/'
EXTINCPATH = -I $(CXXTOOLSIP)

DEPLIBPATH = ../libs
DEPLIBS = -Xlinker --library=cxx_tools

INCPATH = ./CBMDatainclude
SPIKERIP = $(INCPATH)/spikeraster
OUTPUTIP = $(INCPATH)/outdata
INTERFIP = $(INCPATH)/interfaces
PERISTIP = $(INCPATH)/peristimhist

SRCPATH = ./src
SPIKERSP = $(SRCPATH)/spikeraster
OUTPUTSP = $(SRCPATH)/outdata
INTERFSP = $(SRCPATH)/interfaces
PERISTSP = $(SRCPATH)/peristimhist

OBJPATH = ./intout
LIBPATH = ./lib

SPIKERINC = $(SPIKERIP)/spikerasterbitarray.h
OUTPUTINC = $(OUTPUTIP)/eyelidout.h $(OUTPUTIP)/rawuintdata.h
INTERFINC = $(INTERFIP)/ectrialsdata.h $(INTERFIP)/ispikeraster.h
PERISTINC = $(PERISTIP)/peristimhist.h $(PERISTIP)/peristimhistfloat.h

INCS = $(SPIKERINC) $(OUTPUTINC) $(INTERFINC)

SPIKERSRC = $(SPIKERSP)/spikerasterbitarray.cpp
OUTPUTSRC = $(OUTPUTSP)/eyelidout.cpp $(OUTPUTSP)/rawuintdata.cpp
INTERFSRC = $(INTERFSP)/ectrialsdata.cpp $(INTERFSP)/ispikeraster.cpp
PERISTSRC = $(PERISTSP)/peristimhist.cpp $(PERISTSP)/peristimhistfloat.cpp

SPIKEROBJ = $(OBJPATH)/spikerasterbitarray.obj
OUTPUTOBJ = $(OBJPATH)/eyelidout.obj $(OBJPATH)/rawuintdata.obj
INTERFOBJ = $(OBJPATH)/ectrialsdata.obj $(OBJPATH)/ispikeraster.obj
PERISTOBJ = $(OBJPATH)/peristimhist.obj $(OBJPATH)/peristimhistfloat.obj

OBJ = $(SPIKEROBJ) $(OUTPUTOBJ) $(INTERFOBJ) $(PERISTOBJ)

lib: spikeraster output interfaces peristim
	-$(CC) -g $(OBJ) -o $(LIBPATH)/$(NAME).so \
	-Xlinker -rpath=$(DEPLIBPATH) -Xlinker --library-path=$(DEPLIBPATH) \
	$(DEPLIBS)
	-ln -sfn ../CBM_DATA_LIB/$(LIBPATH)/$(NAME).so $(DEPLIBPATH)/
	
spikeraster: $(INC) $(SPIKERSRC)
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(SPIKERSP)/spikerasterbitarray.cpp -o $(OBJPATH)/spikerasterbitarray.obj
	
output: $(INC) $(OUTPUTSRC)
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(OUTPUTSP)/eyelidout.cpp -o $(OBJPATH)/eyelidout.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(OUTPUTSP)/rawuintdata.cpp -o $(OBJPATH)/rawuintdata.obj
	
interfaces: $(INC) $(INTERFSRC)
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INTERFSP)/ispikeraster.cpp -o $(OBJPATH)/ispikeraster.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INTERFSP)/ectrialsdata.cpp -o $(OBJPATH)/ectrialsdata.obj
	
peristim: $(INC) $(PERISTSRC)
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(PERISTSP)/peristimhist.cpp -o $(OBJPATH)/peristimhist.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(PERISTSP)/peristimhistfloat.cpp -o $(OBJPATH)/peristimhistfloat.obj
	
cleanall: cleanlib cleanobj

cleanobj:
	-$(RM) $(OBJ)
	
cleanlib:
	-$(RM) $(LIBPATH)/$(NAME).so
