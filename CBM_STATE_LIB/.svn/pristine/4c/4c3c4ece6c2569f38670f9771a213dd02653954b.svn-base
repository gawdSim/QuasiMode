/*
 * cbmstate.cpp
 *
 *  Created on: Dec 5, 2012
 *      Author: consciousness
 */

#include "../../CBMStateInclude/interfaces/cbmstate.h"

using namespace std;

CBMState::CBMState(fstream &infile)
{
	infile>>numZones;

	conParams=new ConnectivityParams(infile);
	actParams=new ActivityParams(infile);

	infile.seekg(1, ios::cur);
	innetConState=new InNetConnectivityState(conParams, infile);
	mzoneConStates=new MZoneConnectivityState*[numZones];
	for(int i=0; i<numZones; i++)
	{
		mzoneConStates[i]=new MZoneConnectivityState(conParams, infile);
	}

	innetActState=new InNetActivityState(conParams, infile);
	mzoneActStates=new MZoneActivityState*[numZones];
	for(int i=0; i<numZones; i++)
	{
		mzoneActStates[i]=new MZoneActivityState(conParams, actParams, infile);
	}
}

CBMState::CBMState(fstream &actPFile, fstream &conPFile, unsigned int nZones)
{
	int innetCRSeed;
	int *mzoneCRSeed;
	int *mzoneARSeed;

	CRandomSFMT0 randGen(time(0));

	mzoneCRSeed=new int[nZones];
	mzoneARSeed=new int[nZones];

	innetCRSeed=randGen.IRandom(0, INT_MAX);

	for(int i=0; i<nZones; i++)
	{
		mzoneCRSeed[i]=randGen.IRandom(0, INT_MAX);
		mzoneARSeed[i]=randGen.IRandom(0, INT_MAX);
	}

	newState(actPFile, conPFile, nZones, innetCRSeed, mzoneCRSeed, mzoneARSeed);

	delete[] mzoneCRSeed;
	delete[] mzoneARSeed;
}

CBMState::CBMState(fstream &actPFile, fstream &conPFile, unsigned int nZones,
		int innetCRSeed, int *mzoneCRSeed, int *mzoneARSeed)
{
	newState(actPFile, conPFile, nZones, innetCRSeed, mzoneCRSeed, mzoneARSeed);
}

CBMState::~CBMState()
{
	delete actParams;
	delete conParams;

	delete innetConState;
	for(int i=0; i<numZones; i++)
	{
		delete mzoneConStates[i];
	}
	delete[] mzoneConStates;

	delete innetActState;
	for(int i=0; i<numZones; i++)
	{
		delete mzoneActStates[i];
	}
	delete[] mzoneActStates;
}

void CBMState::writeState(fstream &outfile)
{
	outfile<<numZones<<endl;
	conParams->writeParams(outfile);
	actParams->writeParams(outfile);
	innetConState->writeState(outfile);
	for(int i=0; i<numZones; i++)
	{
		cout<<i<<" of "<<numZones<<endl;
		mzoneConStates[i]->writeState(outfile);
		cout<<i<<" done"<<endl;
	}
	innetActState->writeState(outfile);
	for(int i=0; i<numZones; i++)
	{
		mzoneActStates[i]->writeState(outfile);
	}
}

bool CBMState::equivalent(CBMState &compState)
{
	bool eq;

	eq=true;

	eq=(numZones==compState.getNumZones());
	if(!eq)
	{
		cout<<"num zones not equal"<<endl;
		return eq;
	}

	eq=innetConState->equivalent(*(compState.getInnetConStateInternal()));

	return eq;
}


ct_uint32_t CBMState::getNumZones()
{
	return numZones;
}

IConnectivityParams* CBMState::getConnectivityParams()
{
	return (IConnectivityParams *)conParams;
}
IActivityParams* CBMState::getActivityParams()
{
	return (IActivityParams *)actParams;
}

IInNetConState* CBMState::getInnetConState()
{
	return (IInNetConState *)innetConState;
}

IMZoneActState* CBMState::getMZoneActState(unsigned int zoneN)
{
	return (IMZoneActState *)mzoneActStates[zoneN];
}

ActivityParams* CBMState::getActParamsInternal()
{
	return actParams;
}
ConnectivityParams* CBMState::getConParamsInternal()
{
	return conParams;
}

InNetActivityState* CBMState::getInnetActStateInternal()
{
	return innetActState;
}
MZoneActivityState* CBMState::getMZoneActStateInternal
(unsigned int zoneN)
{
	return mzoneActStates[zoneN];
}

InNetConnectivityState* CBMState::getInnetConStateInternal()
{
	return innetConState;
}
MZoneConnectivityState* CBMState::getMZoneConStateInternal(unsigned int zoneN)
{
	return mzoneConStates[zoneN];
}

void CBMState::newState(fstream &actPFile, fstream &conPFile, unsigned int nZones,
			int innetCRSeed, int *mzoneCRSeed, int *mzoneARSeed)
{
	numZones=nZones;

	conParams=new ConnectivityParams(conPFile);
	actParams=new ActivityParams(actPFile);

	cout<<"parameters loaded"<<endl;

	//modified, switch between different innetconstates
//	innetConState=new InNetConStateGGIAltCon(conParams, actParams->msPerTimeStep, innetCRSeed);
	innetConState=new InNetConnectivityState(conParams, actParams->msPerTimeStep, innetCRSeed);

	mzoneConStates=new MZoneConnectivityState*[numZones];
	for(int i=0; i<numZones; i++)
	{
		mzoneConStates[i]=new MZoneConnectivityState(conParams, mzoneCRSeed[i]);
	}
	cout<<"connectivity states constructed"<<endl;

	innetActState=new InNetActivityState(conParams, actParams);
	mzoneActStates=new MZoneActivityState*[numZones];
	for(int i=0; i<numZones; i++)
	{
		mzoneActStates[i]=new MZoneActivityState(conParams, actParams, mzoneARSeed[i]);
	}
	cout<<"activity states constructed"<<endl;
}
