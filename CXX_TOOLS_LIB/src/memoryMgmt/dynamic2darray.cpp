 /*
 * dynamic2darray.cpp
 *
 *  Created on: Mar 9, 2013
 *      Author: consciousness
 */

#include "../../CXXToolsInclude/memoryMgmt/dynamic2darray.h"
#include "../../CXXToolsInclude/memoryMgmt/arrayvalidate.h"

bool validate2DfloatArray(float ** array, unsigned int numElements)
{
	return validateFloatArray(array[0], numElements);
}

bool validate2DdoubleArray(double **array, unsigned int numElements)
{
	return validateDoubleArray(array[0], numElements);
}
