#ifndef CONTROL_H_
#define CONTROL_H_

#include <iostream>
#include <fstream>
#include "setsim.h"

#include <CXXToolsInclude/stdDefinitions/pstdint.h>

#include <CBMStateInclude/interfaces/cbmstate.h>
#include <CBMStateInclude/interfaces/iconnectivityparams.h>
#include <CBMStateInclude/interfaces/iactivityparams.h>
#include <CBMStateInclude/state/innetconnectivitystate.h>

#include <CBMCoreInclude/interface/cbmsimcore.h>

#include <CBMToolsInclude/ecmfpopulation.h>
#include <CBMToolsInclude/poissonregencells.h>
#include <CBMDataInclude/interfaces/ectrialsdata.h>
#include <CBMToolsInclude/eyelidintegrator.h>

#include <CBMStateInclude/state/innetactivitystate.h>

class Control {

public:
	Control();
	~Control();


// Objects
//SetSim *simulation;
CBMState *joestate;
CBMSimCore *joesim;
ECMFPopulation *joeMFFreq;
PoissonRegenCells *joeMFs;
EyelidIntegrator* joeeyelidInt;
ECTrialsData* joeData;


float *mfBackRate;
ct_uint8_t **mfRaster_chunk;
const ct_uint8_t *mfSpks;
//InNetConnectivityState cs;
const ct_uint8_t* bcSpks;
const ct_uint8_t* scSpks;
const ct_uint8_t* pcSpks;
const ct_uint8_t* ncSpks;
const ct_uint8_t* grSpks;
const float* gogoG;
const float* grgoG;


float **mfNoiseRatesLearn;
float **mfNoiseRates;
float *mfR;
	
float findMed(int *arr);

// Training Parameters
int msPreCS = 400;
int msPostCS = 400;

	const ct_uint8_t *mfAP;
	int tts;
	int trial; 	
	int numGO = 4096;//2048;
	int numGR = 5000000;//1048576;
	//int numUBC = 1024;
	int numMF = 4096;
	ct_uint8_t *grPSTHPreCS;
	ct_uint8_t *grPSTHCS;


int csStart = 2000;
int csPhasicSize = 50;

int trialTime = 10000;

int NUM_MF = 4096;	
int numPC = 32;
int numBC = 128;
int numSC = 512;
int numNC = 8;
int numIO = 4;
	
const float *mfGO;
const float *grGO;
const float *goGO;
float **grGOconductancePSTH;
float **mfGOconductancePSTH;

float **allGRGORaster;
float **goGOgRaster;
float **mfGOgRaster;
float **grGOgPSTH; 

ct_uint8_t **allMFPSTH;
ct_uint8_t **allGOPSTH;
ct_uint8_t **allGRPSTH;

const float *GRtoPC_weight;
float **GRtoPC_Weights;

ct_uint8_t **allPCRaster;

float **allGORaster_gogoG; 
ct_uint8_t **allNCRaster;
ct_uint8_t **allBCRaster;
ct_uint8_t **allSCRaster;
ct_uint8_t **allIORaster;
float **eyelidPos;

float **allGOInhInput;
float **allGOExInput;

float **allGOgSumMFGO;
float **allGOgSumGOGO;
float **allGOgSumGRGO;
float **allGOgGOGOcouple;
float **allGOVoltage;
ct_uint8_t *granuleCSSpkCount;
ct_uint8_t **preGRRaster;
ct_uint8_t **preGRPSTHPreCS;
ct_uint8_t **preGRPSTHCS;

int GR_PSTHsum;
ct_uint8_t *activeGranuleIndex;

ct_uint8_t **allGORaster_Trial;
ct_uint8_t *goSpkCount_Trial;;

const ct_uint8_t* goSpks; 
void runTuningSimulation(int tuningTrials, int numTrials, int simNum, int csSize, float csFracMFs, float goMin);
void runSimulation(int tuningTrials, int numTrials, int simNum, int csSize, float csFracMFs, float goMin);
void runSimulationWithGRdata(int fileNum, int goRecipParam, int tuningTrials, int grDetectionTrials, int numTrials, int simNum, int csSize, float csFracMFs, float goMin, float GOGR, float GRGO, float MFGO, float csMinRate, float csMaxRate, float gogoW, int inputWeight, float spillFrac);

float **activeGRgISum;
void train(int selectState, int filename, int ISIs, int numTrials, int numCon, int tunedConNumber);
int* getGRIndicies(float CStonicMFfrac);
int getNumGRIndicies(float CStonicMFfrac);


};

#endif
