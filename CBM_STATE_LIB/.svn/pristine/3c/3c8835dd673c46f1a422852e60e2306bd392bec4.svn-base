/*
 * connectivityparams.h
 *
 *  Created on: Oct 15, 2012
 *      Author: varicella
 */

#ifndef CONNECTIVITYPARAMS_H_
#define CONNECTIVITYPARAMS_H_


#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <cstdlib>

#include <CXXToolsInclude/stdDefinitions/pstdint.h>
#include <CXXToolsInclude/memoryMgmt/dynamic2darray.h>

#include "../interfaces/iconnectivityparams.h"

class ConnectivityParams : public virtual IConnectivityParams
{
public:
	ConnectivityParams(std::fstream &infile);

	virtual ~ConnectivityParams();

	void writeParams(std::fstream &outfile);

	void showParams(std::ostream &outSt);

	ct_uint32_t getGOX();
	ct_uint32_t getGOY();
	ct_uint32_t getGRX();
	ct_uint32_t getGRY();
	ct_uint32_t getGLX();
	ct_uint32_t getGLY();

	ct_uint32_t getNumMF();
	ct_uint32_t getNumGO();
	ct_uint32_t getNumGR();
	ct_uint32_t getNumGL();

	ct_uint32_t getNumSC();
	ct_uint32_t getNumBC();
	ct_uint32_t getNumPC();
	ct_uint32_t getNumNC();
	ct_uint32_t getNumIO();

	std::map<std::string, ct_uint32_t> getParamCopy();

	//glomeruli
//	ct_uint32_t
	ct_uint32_t glX; //read in as power of 2
	ct_uint32_t glY; //read in as power of 2

	ct_uint32_t numGL; //derived = glX*glY

	ct_uint32_t maxnumpGLfromGLtoGR;
	ct_uint32_t lownumpGLfromGLtoGR;
	ct_uint32_t maxnumpGLfromGLtoGO;
	ct_uint32_t maxnumpGLfromGOtoGL;
	//end glomeruli

	//mossy fiber
	ct_uint32_t numMF; //read in as power of 2

	ct_uint32_t numpMFfromMFtoGL; //derived = numGL/numMF
	ct_uint32_t maxnumpMFfromMFtoGO; //derived = numGLOutPerMF*maxNumGODenPerGL
	ct_uint32_t maxnumpMFfromMFtoGR; //derived = numGLOutPerMF*maxNumGRDenPerGL

	ct_uint32_t numpMFfromMFtoNC;

	//end mossy fibers

	//golgi cells
	ct_uint32_t goX; //read in as power of 2
	ct_uint32_t goY; //read in as power of 2

	ct_uint32_t numGO; //derived = goX*goY

	ct_uint32_t maxnumpGOfromGRtoGO;

	ct_uint32_t maxnumpGOfromGLtoGO;
	ct_uint32_t maxnumpGOfromMFtoGO; //derived = maxNumGLInPerGO
	ct_uint32_t maxnumpGOfromGOtoGL;
	ct_uint32_t maxnumpGOfromGOtoGR; //derived = maxNumGLOutPerGO*maxNumGRDenPerGL

	ct_uint32_t spanGODecDenOnGLX;
	ct_uint32_t spanGODecDenOnGLY;

	ct_uint32_t spanGOAscDenOnGRX;
	ct_uint32_t spanGOAscDenOnGRY;

	ct_uint32_t spanGOAxonOnGLX;
	ct_uint32_t spanGOAxonOnGLY;

	//go-go inhibition
	ct_uint32_t maxnumpGOGABAInGOGO;
	ct_uint32_t maxnumpGOGABAOutGOGO;
	float **gogoGABALocalCon;

	//go-go coupling
	ct_uint32_t maxnumpGOCoupInGOGO;
	ct_uint32_t maxnumpGOCoupOutGOGO;
	float **gogoCoupLocalCon;

	//end golgi cells

	//granule cells
	ct_uint32_t grX; //read in as power of 2
	ct_uint32_t grY; //read in as power of 2

	ct_uint32_t numGR; //derived = grX*grY
	ct_uint32_t numGRP2;

	ct_uint32_t grPFVelInGRXPerTStep;
	ct_uint32_t grAFDelayInTStep;
	ct_uint32_t maxnumpGRfromGRtoGO;
	ct_uint32_t maxnumpGRfromGLtoGR;
	ct_uint32_t maxnumpGRfromGOtoGR;
	ct_uint32_t maxnumpGRfromMFtoGR;

//	ct_uint32_t numPCOutPerPF; place holders
//	ct_uint32_t numBCOutPerPF;
//	ct_uint32_t numSCOutPerPF;

	ct_uint32_t spanGRDenOnGLX;
	ct_uint32_t spanGRDenOnGLY;
	//end granule cells

	//stellate cells
	ct_uint32_t numSC; //read in as power of 2
	ct_uint32_t numpSCfromGRtoSC; //derived = numGR/numSC
	ct_uint32_t numpSCfromGRtoSCP2;
	ct_uint32_t numpSCfromSCtoPC;//TODO: new
	//end stellate cells

	//purkinje cells
	ct_uint32_t numPC; //read in as power of 2
	ct_uint32_t numpPCfromGRtoPC; //derived = numGR/numPC
	ct_uint32_t numpPCfromGRtoPCP2;
	ct_uint32_t numpPCfromBCtoPC; //TODO new
	ct_uint32_t numpPCfromPCtoBC; //TODO: new
	ct_uint32_t numpPCfromSCtoPC; //TODO: new
	ct_uint32_t numpPCfromPCtoNC; //TODO: new

	//basket cells
	ct_uint32_t numBC; //read in as power of 2
	ct_uint32_t numpBCfromGRtoBC; //derived = numGR/numBC
	ct_uint32_t numpBCfromGRtoBCP2;
	ct_uint32_t numpBCfromBCtoPC; //TODO: new
	ct_uint32_t numpBCfromPCtoBC; //TODO: new

	//TODO: new below
	//nucleus cells
	ct_uint32_t numNC;
	ct_uint32_t numpNCfromPCtoNC;
	ct_uint32_t numpNCfromNCtoIO;
	ct_uint32_t numpNCfromMFtoNC;

	//inferior olivary cells
	ct_uint32_t numIO;
	ct_uint32_t numpIOfromIOtoPC;
	ct_uint32_t numpIOfromNCtoIO;
	ct_uint32_t numpIOInIOIO;
	ct_uint32_t numpIOOutIOIO;


private:
	ConnectivityParams();

	std::map<std::string, ct_uint32_t> paramMap;
};

#endif /* CONNECTIVITYPARAMS_H_ */
