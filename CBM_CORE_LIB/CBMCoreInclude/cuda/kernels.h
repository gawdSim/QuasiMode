/*
 * kernels.h
 *
 *  Created on: Jun 6, 2011
 *      Author: consciousness
 */

#ifndef KERNELS_H_
#define KERNELS_H_

#include <cuda.h>
#include <cuda_runtime.h>
#include <device_functions.h>

#include <iostream>

#include <CXXToolsInclude/stdDefinitions/pstdint.h>

void callTestKernel(cudaStream_t &st, float *a, float *b, float *c);

void callGRActKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		float *vGPU, float *gKCaGPU, float *gLeakGRPGU, float *gNMDAGRGPU, float*gNMDAIncGRGPU, float *threshGPU,
		ct_uint32_t *apBufGPU, ct_uint8_t *apOutGRGPU, ct_uint32_t *apGRGPU,
		int *apMFtoGRGPU, int *apUBCtoGRGPU, float *gESumGPU, float *gUBCESum, float *gISumGPU,
		float eLeak, float eGOIn, float gAMPAInc,
		float threshBase, float threshMax, float threshDecay);

template<typename Type, bool inMultiP, bool outMultiP>
void callSumKernel(cudaStream_t &st, Type *inGPU, size_t inGPUP, Type *outSumGPU, size_t outSumGPUP,
		unsigned int nOutCells, unsigned int nOutCols, unsigned int rowLength);

template<typename Type>
void callBroadcastKernel(cudaStream_t &st, Type *broadCastVal, Type *outArray,
		unsigned int nBlocks, unsigned int rowLength);

void callUpdateGROutGOKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock, unsigned int numGO,
		ct_uint32_t *apBufGPU, ct_uint32_t *grInGOGPU, ct_uint32_t grInGOGPUPitch,
		ct_uint32_t *delayMasksGPU, ct_uint32_t delayMasksGPUPitch,
		ct_uint32_t *conGRtoGOGPU, size_t conGRtoGOGPUPitch,
		ct_int32_t *numGOPerGRGPU);
void callUpdateGROutBCKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock, unsigned int numBC,
		ct_uint32_t *apBufGPU, ct_uint32_t *grInBCGPU, ct_uint32_t grInBCGPUPitch,
		ct_uint32_t *delayMasksGPU, ct_uint32_t delayMasksGPUPitch,
		ct_uint32_t *conGRtoBCGPU, size_t conGRtoBCGPUPitch,
		ct_int32_t *numBCPerGRGPU);

void callSumGRGOOutKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGOPerBlock,
		unsigned int numGROutRows, ct_uint32_t *grInGOGPU,  size_t grInGOGPUPitch, ct_uint32_t *grInGOSGPU);
void callSumGRBCOutKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGOPerBlock,
		unsigned int numGROutRows, ct_uint32_t *grInBCGPU,  size_t grInBCGPUPitch, ct_uint32_t *grInBCSGPU);



void callUpdateUBCInGRDepressionOPKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		unsigned int numInCells, float *depAmpGPU,
		ct_uint32_t *conInGRGPU, size_t conInGRGPUP,
		ct_int32_t *numInPerGRGPU, int *numUBCperGR, float *depAmpUBCGRGPU);



void callUpdateMFInGRDepressionOPKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		unsigned int numInCells, float *depAmpGPU,
		ct_uint32_t *conInGRGPU, size_t conInGRGPUP,
		ct_int32_t *numInPerGRGPU, int *numMFperGR, float *depAmpMFGRGPU);

void callUpdateGOInGRDepressionOPKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		unsigned int numInCells, float *depAmpGPU,
		ct_uint32_t *conInGRGPU, size_t conInGRGPUP,
		ct_int32_t *numInPerGRGPU, float *depAmpGOGRGPU);

void callUpdateGOInGRDynamicSpillOPKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		unsigned int numInCells, float *dynamicAmpGPU,
		ct_uint32_t *conInGRGPU, size_t conInGRGPUP,
		ct_int32_t *numInPerGRGPU, float *dynamicAmpGOGRGPU);




//void callUpdateInGRKernel(cudaStream_t &st, unsigned int nBlocks, unsigned int nThreadsPerB,
//		unsigned int *apInGPU, float *gGPU, unsigned int gGPUP,
//		unsigned int *conInGRGPU, unsigned int conInGRGPUP,
//		int *numInPerGRGPU, float *gSumGPU, float gDecay, float gInc);

void callUpdateInGROPKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		unsigned int numInCells, ct_uint32_t *apInGPU, float *dynamicAmpGPU, float *gGPU, size_t gGPUP,
		ct_uint32_t *conInGRGPU, size_t conInGRGPUP,
		ct_int32_t *numInPerGRGPU, float *gSumGPU, float *gDirectGPU, float *gSpilloverGPU, 
		float gDecayD, float gIncD, float gDecayS, float gIncFracS);

void callUpdateUBCInGROPKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		unsigned int numInCells, ct_uint32_t *apInGPU, float *depAmpGPU, float *gGPU, size_t gGPUP,
		ct_uint32_t *conInGRGPU, size_t conInGRGPUP,
		ct_int32_t *numInPerGRGPU, int *apUBCtoGRGPU, float *gSumGPU, float *gDirectGPU, float *gSpilloverGPU,
		float gDecayDirect, float gIncDirect, float gDecaySpill, float gIncFracSpill);

void callUpdateMFInGROPKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		unsigned int numInCells, ct_uint32_t *apInGPU, float *depAmp, float *gGPU, size_t gGPUP,
		ct_uint32_t *conInGRGPU, size_t conInGRGPUP,
		ct_int32_t *numInPerGRGPU, int *apMFtoGRGPU, float *gSumGPU, float *gDirectGPU, float *gSpilloverGPU,
		float gDecayDirect, float gIncDirect, float gDecaySpill, float gIncFracSpill);

//void callupdateInSumGRKernel(cudaStream_t &st, unsigned int nBlocks, unsigned int nThreadsPerB,
//		float *gGPU, float gDecay, float gInc, float inSum);

void callUpdatePFBCSCOutKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		ct_uint32_t *apBufGPU, ct_uint32_t *delayMaskGPU,
		ct_uint32_t *inPFBCGPU, size_t inPFBCGPUPitch, unsigned int numPFInPerBCP2,
		ct_uint32_t *inPFSCGPU, size_t inPFSCGPUPitch, unsigned int numPFInPerSCP2);

void callUpdatePFPCOutKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		ct_uint32_t *apBufGPU, ct_uint32_t *delayMaskGPU,
		float *pfPCSynWGPU, float *inPFPCGPU, size_t inPFPCGPUPitch, unsigned int numPFInPerPCP2);

void callUpdateGRHistKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		ct_uint32_t *apBufGPU, ct_uint64_t *historyGPU, ct_uint32_t apBufGRHistMask);

void callUpdatePFPCPlasticityIOKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		float *synWeightGPU, ct_uint64_t *historyGPU, unsigned int pastBinNToCheck,
		int offSet, float pfPCPlastStep);

//void callUpdatePSHGPU(unsigned int *apBufGPU, unsigned int *pshGPU, unsigned int pshGPUP,
//		int nBins, int tsPerBin, unsigned int extrashift, unsigned int nBlocks, unsigned int nThreadPerB);

#endif /* KERNELS_H_ */
