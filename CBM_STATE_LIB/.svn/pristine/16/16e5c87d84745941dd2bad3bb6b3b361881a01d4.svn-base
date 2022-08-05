/*
 * innetactivitystate.h
 *
 *  Created on: Nov 6, 2012
 *      Author: consciousness
 */

#ifndef INNETACTIVITYSTATE_H_
#define INNETACTIVITYSTATE_H_

#include <fstream>

#include <CXXToolsInclude/memoryMgmt/dynamic2darray.h>
#include <CXXToolsInclude/memoryMgmt/arrayinitalize.h>
#include <CXXToolsInclude/memoryMgmt/arrayvalidate.h>
#include <CXXToolsInclude/fileIO/rawbytesrw.h>
#include <CXXToolsInclude/stdDefinitions/pstdint.h>

#include "../params/connectivityparams.h"
#include "../params/activityparams.h"

class InNetActivityState
{
public:
	InNetActivityState(ConnectivityParams *conParams, ActivityParams *actParams);
	InNetActivityState(ConnectivityParams *conParams, std::fstream &infile);
	InNetActivityState(const InNetActivityState &state);

	virtual ~InNetActivityState();

	void writeState(std::fstream &outfile);

	bool equivalent(const InNetActivityState &compState);

	bool validateState();

	void resetState(ActivityParams *ap);

	ConnectivityParams *cp;

	//mossy fiber
	ct_uint8_t *histMF;
	ct_uint32_t *apBufMF;

	//golgi cells
	ct_uint8_t *apGO;
	ct_uint32_t *apBufGO;
	float *vGO;
	float *vCoupleGO;
	float *threshCurGO;
	ct_uint32_t *inputMFGO;
	ct_uint32_t *inputGOGO;

	//todo: synaptic depression test
	float *inputGOGABASynDepGO;
	float *goGABAOutSynScaleGOGO;

	float *gMFGO;
	float *gGRGO;
	float *gGOGO;
	float *gMGluRGO;
	float *gMGluRIncGO;
	float *mGluRGO;
	float *gluGO;

	//granule cells
	ct_uint8_t *apGR;
	ct_uint32_t *apBufGR;

	float **gMFGR;
	float *gMFSumGR;

	float **gGOGR;
	float *gGOSumGR;

	float *threshGR;
	float *vGR;
	float *gKCaGR;
	ct_uint64_t *historyGR;

	//stellate cells
	ct_uint8_t *apSC;
	ct_uint32_t *apBufSC;

	float *gPFSC;
	float *threshSC;
	float *vSC;

	ct_uint32_t *inputSumPFSC;

private:
	InNetActivityState();

	void allocateMemory();

	void stateRW(bool read, std::fstream &file);

	void initializeVals(ActivityParams *ap);
};


#endif /* INNETACTIVITYSTATE_H_ */
