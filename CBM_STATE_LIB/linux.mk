NAME = libcbm_state

CC = icpc

DEFINES = -DINTELCC

CFLAGS = $(DEFINES) -O3 -fpic

RM = rm

CXXTOOLSIP = '../CXX_TOOLS_LIB/'
EXTINCPATH = -I $(CXXTOOLSIP)  

DEPLIBPATH = ../libs
DEPLIBS = -Xlinker --library=cxx_tools


INCPATH = ./CBMStateInclude
PARAMSIP = $(INCPATH)/params
STATEIP = $(INCPATH)/state
INTFIP=$(INCPATH)/interfaces

SRCPATH = ./src
PARAMSSP = $(SRCPATH)/params
STATESP = $(SRCPATH)/state
INTFSP = $(SRCPATH)/interfaces

OUTPATH = ./intout
LIBPATH = ./lib

PARAMSINC = $(PARAMSIP)/connectivityparams.h $(PARAMSIP)/activityparams.h
STATEINC = $(STATEIP)/innetconnectivitystate.h $(STATEIP)/innetconstateggialtcon.h \
$(STATEIP)/innetactivitystate.h \
$(STATEIP)/mzoneconnectivitystate.h $(STATEIP)/mzoneactivitystate.h
INTFINC = $(INTFIP)/cbmstate.h $(INTFIP)/cbmstatex2grgodecouple.h $(INTFIP)/iconnectivityparams.h \
$(INTFIP)/iactivityparams.h $(INTFIP)/iinnetconstate.h $(INTFIP)/imzoneactstate.h
INC = $(PARAMSINC) $(STATEINC) $(INTFINC)

PARAMSSRC = $(PARAMSSP)/connectivityparams.cpp $(PARAMSSP)/activityparams.cpp
STATESRC = $(STATESP)/innetconnectivitystate.cpp $(STATESP)/innetconstateggialtcon.cpp \
$(STATESP)/innetactivitystate.cpp \
$(STATESP)/mzoneconnectivitystate.cpp $(STATESP)/mzoneactivitystate.cpp
INTFSRC = $(INTFSP)/cbmstatex2grgodecouple.cpp $(INTFSP)/cbmstate.cpp $(INTFSP)/iconnectivityparams.cpp \
$(INTFSP)/iactivityparams.cpp $(INTFSP)/iinnetconstate.cpp $(INTFSP)/imzoneactstate.cpp
SRC = $(PARAMSSRC) $(STATESRC) $(INTFSRC)

PARAMSOBJ = $(OUTPATH)/connectivityparams.obj $(OUTPATH)/activityparams.obj
STATEOBJ = $(OUTPATH)/innetconnectivitystate.obj $(OUTPATH)/innetconstateggialtcon.obj \
$(OUTPATH)/innetactivitystate.obj \
$(OUTPATH)/mzoneconnectivitystate.obj $(OUTPATH)/mzoneactivitystate.obj
INTFOBJ = $(OUTPATH)/cbmstatex2grgodecouple.obj $(OUTPATH)/cbmstate.obj $(OUTPATH)/iconnectivityparams.obj \
$(OUTPATH)/iactivityparams.obj $(OUTPATH)/iinnetconstate.obj $(OUTPATH)/imzoneactstate.obj
OBJ = $(PARAMSOBJ) $(STATEOBJ) $(INTFOBJ)

lib: obj
	-$(CC) -G $(OBJ) -o $(LIBPATH)/$(NAME).so \
	-Xlinker -rpath=$(DEPLIBPATH) -Xlinker --library-path=$(DEPLIBPATH) \
	$(DEPLIBS)
	-ln -sfn ../CBM_STATE_LIB/$(LIBPATH)/$(NAME).so $(DEPLIBPATH)/

obj: paramsobj stateobj intfobj
	
paramsobj: $(PARAMSINC) $(PARAMSSRC) 
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(PARAMSSP)/connectivityparams.cpp -o $(OUTPATH)/connectivityparams.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(PARAMSSP)/activityparams.cpp -o $(OUTPATH)/activityparams.obj

stateobj: $(STATEINC) $(PARAMSINC) $(STATESRC)
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(STATESP)/innetconnectivitystate.cpp -o $(OUTPATH)/innetconnectivitystate.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(STATESP)/innetconstateggialtcon.cpp -o $(OUTPATH)/innetconstateggialtcon.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(STATESP)/innetactivitystate.cpp -o $(OUTPATH)/innetactivitystate.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(STATESP)/mzoneconnectivitystate.cpp -o $(OUTPATH)/mzoneconnectivitystate.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(STATESP)/mzoneactivitystate.cpp -o $(OUTPATH)/mzoneactivitystate.obj
	
intfobj: $(PARAMSINC) $(STATEINC) $(INTFINC) $(INTFSRC)
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INTFSP)/cbmstate.cpp -o $(OUTPATH)/cbmstate.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INTFSP)/cbmstatex2grgodecouple.cpp -o $(OUTPATH)/cbmstatex2grgodecouple.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INTFSP)/iconnectivityparams.cpp -o $(OUTPATH)/iconnectivityparams.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INTFSP)/iactivityparams.cpp -o $(OUTPATH)/iactivityparams.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INTFSP)/iinnetconstate.cpp -o $(OUTPATH)/iinnetconstate.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INTFSP)/imzoneactstate.cpp -o $(OUTPATH)/imzoneactstate.obj
	
	
cleanall: cleanlib cleanobj
	
cleanobj:
	-$(RM) $(OBJ)

cleanlib:
	-$(RM) $(LIBPATH)/$(NAME).so

	
