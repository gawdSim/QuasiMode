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
		float *vGPU, float *gKCaGPU, float *threshGPU,
		ct_uint32_t *apBufGPU, ct_uint8_t *apOutGRGPU, ct_uint32_t *apGRGPU,
		float *gESumGPU, float *gISumGPU,
		float gLeak, float eLeak, float eGOIn,
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

void callSumGRGOOutKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGOPerBlock,
		unsigned int numGROutRows, ct_uint32_t *grInGOGPU,  size_t grInGOGPUPitch, ct_uint32_t *grInGOSGPU);

//void callUpdateInGRKernel(cudaStream_t &st, unsigned int nBlocks, unsigned int nThreadsPerB,
//		unsigned int *apInGPU, float *gGPU, unsigned int gGPUP,
//		unsigned int *conInGRGPU, unsigned int conInGRGPUP,
//		int *numInPerGRGPU, float *gSumGPU, float gDecay, float gInc);

void callUpdateInGROPKernel(cudaStream_t &st, unsigned int numBlocks, unsigned int numGRPerBlock,
		unsigned int numInCells, ct_uint32_t *apInGPU, float *gGPU, size_t gGPUP,
		ct_uint32_t *conInGRGPU, size_t conInGRGPUP,
		ct_int32_t *numInPerGRGPU, float *gSumGPU, float gDecay, float gInc);

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
