#make simulation core library

NAME = libcbm_core

CC = icpc

NVCC = nvcc

DEFINES = -DINTELCC

CFLAGS = $(DEFINES) -O3 -fpic
#-openmp
NVCFLAGS = -arch=compute_20 -Xcompiler -fPIC

RM = rm

CUDAINCPATH = '/opt/cuda/include/'
CUDALIBPATH = /usr/lib64
CUDARTLIBPATH = /opt/cuda/lib64
CUDALIBS = $(CUDALIBPATH)/libcuda.so $(CUDARTLIBPATH)/libcudart.so

CXXTOOLSIP = '../CXX_TOOLS_LIB/' 
CBMSTATEIP = '../CBM_STATE_LIB/'

EXTINCPATH = -I $(CUDAINCPATH) -I $(CXXTOOLSIP) -I $(CBMSTATEIP)  

DEPLIBPATH = ../libs
DEPLIBS = -Xlinker --library=cxx_tools -Xlinker --library=cbm_state

INCPATH = ./CBMCoreInclude
INTERFACEIP = $(INCPATH)/interface
CUDAIP = $(INCPATH)/cuda
MZMIP = $(INCPATH)/mzonemodules
INMIP = $(INCPATH)/innetmodules

SRCPATH = ./src
INTERFACESP = $(SRCPATH)/interface
CUDASP = $(SRCPATH)/cuda
MZMSP = $(SRCPATH)/mzonemodules
INMSP = $(SRCPATH)/innetmodules

OUTPATH = ./intout

LIBPATH = ./lib

INTERFACEINC = $(INTERFACEIP)/cbmsimcore.h $(INTERFACEIP)/cbmsimx2grgodecouple.h \
$(INTERFACEIP)/innetinterface.h $(INTERFACEIP)/mzoneinterface.h
CUDAINC = $(CUDAIP)/kernels.h
MZMINC = $(MZMIP)/mzone.h
INMINC = $(INMIP)/innet.h $(INMIP)/innetallgrmfgo.h
#$(INMIP)/innetsparsegrgo.h
# \
#$(INMIP)/innetnodelay.h $(INMIP)/innetnogo.h $(INMIP)/innetnogrgo.h $(INMIP)/innetnomfgo.h \
#$(INMIP)/innetsubmfgr.h $(INMIP)/innetallgrgo.h $(INMIP)/innetallgogr.h \
#$(INMIP)/innetallgrgogr.h $(INMIP)/innetnogosubmfgr.h $(INMIP)/innetnomfgosubmfgr.h \
#$(INMIP)/innetallgogrsubmfgr.h $(INMIP)/innetallgrgosubmfgr.h \
#$(INMIP)/innetallgrgogrsubmfgr.h

INCS = $(INTERFACEINC) $(CUDAINC) $(MZMINC) $(INMINC)

INTERFACESRC = $(INTERFACESP)/cbmsimcore.cpp $(INTERFACESP)/cbmsimx2grgodecouple.cpp \
$(INTERFACESP)/innetinterface.cpp $(INTERFACESP)/mzoneinterface.cpp
CUDASRC = $(CUDASP)/kernels.cu
MZMSRC = $(MZMSP)/mzone.cpp
INMSRC = $(INMSP)/innet.cpp $(INMSP)/innetallgrmfgo.cpp
#$(INMSP)/innetsparsegrgo.cpp
# \
#$(INMSP)/innetnodelay.cpp $(INMSP)/innetnogo.cpp $(INMSP)/innetnogrgo.cpp $(INMSP)/innetnomfgo.cpp \
#$(INMSP)/innetsubmfgr.cpp $(INMSP)/innetallgrgo.cpp $(INMSP)/innetallgogr.cpp \
#$(INMSP)/innetallgrgogr.cpp $(INMSP)/innetnogosubmfgr.cpp $(INMSP)/innetnomfgosubmfgr.cpp \
#$(INMSP)/innetallgogrsubmfgr.cpp  $(INMSP)/innetallgrgosubmfgr.cpp \
#$(INMSP)/innetallgrgogrsubmfgr.cpp

INTERFACEOBJ = $(OUTPATH)/cbmsimcore.obj $(OUTPATH)/cbmsimx2grgodecouple.obj \
$(OUTPATH)/innetinterface.obj $(OUTPATH)/mzoneinterface.obj
CUDAOBJ = $(OUTPATH)/kernels.obj
MZMOBJ = $(OUTPATH)/mzone.obj
INMOBJ = $(OUTPATH)/innet.obj $(OUTPATH)/innetallgrmfgo.obj
#$(OUTPATH)/innetsparsegrgo.obj
# \
#$(OUTPATH)/innetnodelay.obj $(OUTPATH)/innetnogo.obj $(OUTPATH)/innetnogrgo.obj $(OUTPATH)/innetnomfgo.obj \
#$(OUTPATH)/innetsubmfgr.obj $(OUTPATH)/innetallgrgo.obj $(OUTPATH)/innetallgogr.obj \
#$(OUTPATH)/innetallgrgogr.obj $(OUTPATH)/innetnogosubmfgr.obj $(OUTPATH)/innetnomfgosubmfgr.obj \
#$(OUTPATH)/innetallgogrsubmfgr.obj $(OUTPATH)/innetallgrgosubmfgr.obj \
$(OUTPATH)/innetallgrgogrsubmfgr.obj

OBJ = $(INTERFACEOBJ) $(CUDAOBJ) $(MZMOBJ) $(INMOBJ)

lib: interface cuda mzm inm
	-$(CC) $(CFLAGS) -G $(OBJ) $(CUDALIBS) -o $(LIBPATH)/$(NAME).so \
	-Xlinker -rpath=$(DEPLIBPATH) -Xlinker --library-path=$(DEPLIBPATH) \
	$(DEPLIBS)
	-ln -sfn ../CBM_CORE_LIB/$(LIBPATH)/$(NAME).so $(DEPLIBPATH)/
	
interface: $(INC) $(INTERFACESRC)
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INTERFACESP)/cbmsimcore.cpp -o $(OUTPATH)/cbmsimcore.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INTERFACESP)/cbmsimx2grgodecouple.cpp -o $(OUTPATH)/cbmsimx2grgodecouple.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INTERFACESP)/innetinterface.cpp -o $(OUTPATH)/innetinterface.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INTERFACESP)/mzoneinterface.cpp -o $(OUTPATH)/mzoneinterface.obj
	
cuda: $(INC) $(CUDASRC)
	-$(NVCC) $(NVCFLAGS) $(EXTINCPATH) -c $(CUDASP)/kernels.cu -o $(OUTPATH)/kernels.obj
	
mzm: $(INC) $(MZMSRC)
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(MZMSP)/mzone.cpp -o $(OUTPATH)/mzone.obj
	
inm: $(INC) $(INMSRC)
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INMSP)/innet.cpp -o $(OUTPATH)/innet.obj
	-$(CC) $(CFLAGS) $(EXTINCPATH) -c $(INMSP)/innetallgrmfgo.cpp -o $(OUTPATH)/innetallgrmfgo.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetsparsegrgo.cpp -o $(OUTPATH)/innetsparsegrgo.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetnodelay.cpp -o $(OUTPATH)/innetnodelay.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetnogo.cpp -o $(OUTPATH)/innetnogo.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetnogrgo.cpp -o $(OUTPATH)/innetnogrgo.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetnomfgo.cpp -o $(OUTPATH)/innetnomfgo.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetsubmfgr.cpp -o $(OUTPATH)/innetsubmfgr.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetallgrgo.cpp -o $(OUTPATH)/innetallgrgo.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetallgogr.cpp -o $(OUTPATH)/innetallgogr.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetallgrgogr.cpp -o $(OUTPATH)/innetallgrgogr.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetnogosubmfgr.cpp -o $(OUTPATH)/innetnogosubmfgr.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetnomfgosubmfgr.cpp -o $(OUTPATH)/innetnomfgosubmfgr.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetallgogrsubmfgr.cpp -o $(OUTPATH)/innetallgogrsubmfgr.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetallgrgosubmfgr.cpp -o $(OUTPATH)/innetallgrgosubmfgr.obj
#	-$(CC) $(CFLAGS) -I $(CUDAINCPATH) -c $(INMSP)/innetallgrgogrsubmfgr.cpp -o $(OUTPATH)/innetallgrgogrsubmfgr.obj

cleanall: cleanlib cleanobj

cleanobj:
	-$(RM) $(OBJ)
	
cleanlib:
	-$(RM) $(LIBPATH)/$(NAME).so
	