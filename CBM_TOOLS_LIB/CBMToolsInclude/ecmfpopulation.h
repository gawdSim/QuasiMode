/*
 * ecmfpopulation.h
 *
 *  Created on: Jul 11, 2014
 *      Author: consciousness
 */

#ifndef ECMFPOPULATION_H_
#define ECMFPOPULATION_H_

#include <vector>
#include <fstream>
#include <iostream>
#include <string>

#include <CXXToolsInclude/stdDefinitions/pstdint.h>
#include <CXXToolsInclude/randGenerators/randomc.h>
#include <CXXToolsInclude/randGenerators/sfmt.h>
//#include <CXXToolsInclude/fileIO/rawbytesrw.h>

//#include <CBMDataInclude/peristimhist/peristimhistfloat.h>
//#include <CBMDataInclude/interfaces/ectrialsdata.h>

class ECMFPopulation
{
public:
	//ECMFPopulation(ECTrialsData *data);
	ECMFPopulation(
		int numMF, int randSeed, float fracCSTMF, float fracCSPMF, float fracCtxtMF, float fracCollNC,
		float bgFreqMin, float csBGFreqMin, float ctxtFreqMin, float csTFreqMin, float csPFreqMin,
		float bgFreqMax, float csBGFreqMax, float ctxtFreqMax, float csTFreqMax, float csPFreqMax,
		bool turnOffColls_, float fracImportCells, bool secondCS, float fracOverlap);
//	ECMFPopulation(std::fstream &infile);

	~ECMFPopulation();

	void writeToFile(std::fstream &outfile);
	void writeMFLabels(std::string labelFileName);

	float *getMFBG();
	float *getMFInCSTonicA();
	float *getMFInCSTonicB();
	float *getMFFreqInCSPhasic();
	
	bool *getContextMFInd();
	bool *getTonicMFInd();
	bool *getTonicMFIndOverlap();
	bool *getPhasicMFInd();
	
private:
	void setMFs(int numTypeMF, int numMF, CRandomSFMT0 *randGen, bool *isAny, bool *isType);
	void setMFsOverlap(int numTypeMF, int numMF, CRandomSFMT0 *randGen, bool *isAny, bool *isTypeA, bool *isTypeB, float fracOverlap);
	ct_uint32_t numMF;
	float *mfFreqBG;
	float *mfFreqInCSTonicA;
	float *mfFreqInCSTonicB;
	float *mfFreqInCSPhasic;
    bool *isCSTonicA;
    bool *isCSTonicB;
    bool *isCSPhasic;
    bool *isContext;
	bool *isCollateral;
	bool *isImport;
	bool *isAny;
	bool turnOffColls;
};



#endif /* ECMFPOPULATION_H_ */
