NAME = libcbm_visual

CC = gcc

DEFINES = -DINTELCC

CFLAGS = $(DEFINES) -O3 -fpic

RM = rm
MOC = moc
UIC = uic

QTINCPATH = '/usr/include/qt4/'
QTLIBPATH = /usr/lib/x86_64-linux-gnu
QTLIBS = $(QTLIBPATH)/libQtGui.so $(QTLIBPATH)/libQtCore.so

CXXTOOLSIP ='../CXX_TOOLS_LIB'

EXTINCPATH = -I $(CXXTOOLSIP) -I $(QTINCPATH)

DEPLIBPATH = ../libs
DEPLIBS = -Xlinker --library=cxx_tools

INCPATH = ./CBMVisualInclude
MOCIPATH = $(INCPATH)/moc
UIIPATH = $(INCPATH)/uic
UIPATH = $(INCPATH)/ui

SRCPATH = ./src

OUTPATH = ./output
LIBPATH = ./lib

UI = $(UIPATH)/bufdispwindow.ui $(UIPATH)/actspatialview.ui $(UIPATH)/acttemporalview.ui
UII = $(UIIPATH)/ui_bufdispwindow.h $(UIIPATH)/ui_actspatialview.h $(UIIPATH)/ui_acttemporalview.h
MOCI = $(MOCIPATH)/moc_bufdispwindow.h $(MOCIPATH)/moc_actspatialview.h $(MOCIPATH)/moc_acttemporalview.h \
$(MOCIPATH)/moc_connectivityview.h $(MOCIPATH)/moc_spatialview.h
INC = $(INCPATH)/bufdispwindow.h $(INCPATH)/actspatialview.h $(INCPATH)/acttemporalview.h \
$(INCPATH)/connectivityview.h $(INCPATH)/spatialview.h

ALLINC = $(UII) $(MOCI) $(INC)

SRC = $(SRCPATH)/bufdispwindow.cpp $(SRCPATH)/actspatialview.cpp $(SRCPATH)/acttemporalview.cpp \
$(SRCPATH)/connectivityview.cpp $(SRCPATH)/spatialview.cpp

OBJ = $(OUTPATH)/bufdispwindow.obj $(OUTPATH)/actspatialview.obj $(OUTPATH)/acttemporalview.obj \
$(OUTPATH)/connectivityview.obj $(OUTPATH)/spatialview.obj


lib: obj
	-$(CC) -g $(OBJ) $(QTLIBS) -o $(LIBPATH)/$(NAME).so \
	-Xlinker -rpath=$(DEPLIBPATH) -Xlinker --library-path=$(DEPLIBPATH) \
	$(DEPLIBS)
	-ln -sfn ../CBM_VISUAL_LIB/$(LIBPATH)/$(NAME).so $(DEPLIBPATH)/
	
obj: mocs uics $(ALLINC) $(SRC)
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(SRCPATH)/bufdispwindow.cpp -o $(OUTPATH)/bufdispwindow.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(SRCPATH)/actspatialview.cpp -o $(OUTPATH)/actspatialview.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(SRCPATH)/acttemporalview.cpp -o $(OUTPATH)/acttemporalview.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(SRCPATH)/spatialview.cpp -o $(OUTPATH)/spatialview.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(SRCPATH)/connectivityview.cpp -o $(OUTPATH)/connectivityview.obj
mocs: $(INC)
	-$(MOC) $(INCPATH)/bufdispwindow.h -o $(MOCIPATH)/moc_bufdispwindow.h
	-$(MOC) $(INCPATH)/actspatialview.h -o $(MOCIPATH)/moc_actspatialview.h
	-$(MOC) $(INCPATH)/acttemporalview.h -o $(MOCIPATH)/moc_acttemporalview.h
	-$(MOC) $(INCPATH)/spatialview.h -o $(MOCIPATH)/moc_spatialview.h
	-$(MOC) $(INCPATH)/connectivityview.h -o $(MOCIPATH)/moc_connectivityview.h

uics: $(UI)
	-$(UIC) $(UIPATH)/bufdispwindow.ui -o $(UIIPATH)/ui_bufdispwindow.h
	-$(UIC) $(UIPATH)/actspatialview.ui -o $(UIIPATH)/ui_actspatialview.h
	-$(UIC) $(UIPATH)/acttemporalview.ui -o $(UIIPATH)/ui_acttemporalview.h
	
cleanall: cleanlib cleanobj

cleanobj:
	-$(RM) $(OBJ)
	
cleanlib:
	-$(RM) $(LIBPATH)/$(NAME).so
