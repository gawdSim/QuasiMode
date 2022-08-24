#include "control.h"
#include <string>
#include <time.h>
using namespace std;


Control::Control(){};

Control::~Control(){};



void Control::runSimulationWithGRdata(int fileNum, int goRecipParam, int grDetectionTrials, int numTrials, int numTrainingTrials, int simNum, int csSize, float csFracMFs, float goMin, float GOGR, float GRGO, float MFGO, float csMinRate, float csMaxRate, float gogoW, int inputStrength, float spillFrac){
	

	cout << "fileNum:  " << fileNum << endl;
	SetSim simulation(fileNum, goRecipParam);
	joestate = simulation.getstate();
	joesim = simulation.getsim();
	joeMFFreq = simulation.getMFFreq(csMinRate, csMaxRate);
	joeMFs = simulation.getMFs();	
	
	cout << "Done filling MF arrays" << endl;	

	int recipName[25] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50};

//Set up granule cell data collection
	//Find granule cells with CS MF input	
	int* granuleIndWithInput =  getGRIndicies(csFracMFs); 
	int numpActiveGranule = getNumGRIndicies(csFracMFs);	
	cout << "Number of Granule cells w/ inputs	" << numpActiveGranule << endl;	
	//Allocate and Initialize 
	int activeCounter=0;
	int *activeGranuleIndex;
	activeGranuleIndex = new int[numpActiveGranule];
	for(int i=0; i<numpActiveGranule; i++){activeGranuleIndex[i] = false;}
	grPSTHCS = new ct_uint8_t[numpActiveGranule];
	for(int i=0; i<numpActiveGranule; i++){grPSTHCS[i] = 0;}
	grPSTHPreCS = new ct_uint8_t[numpActiveGranule];
	for(int i=0; i<numpActiveGranule; i++){grPSTHPreCS[i] = 0;}
	preGRPSTHCS=allocate2DArray<ct_uint8_t>(numpActiveGranule, csSize);
	arrayInitialize<ct_uint8_t>(preGRPSTHCS[0], 0, numpActiveGranule*csSize);
	preGRPSTHPreCS=allocate2DArray<ct_uint8_t>(numpActiveGranule, csSize);
	arrayInitialize<ct_uint8_t>(preGRPSTHPreCS[0], 0, numpActiveGranule*csSize);

	int grSaveNumber = 30000;


// Allocate and Initialize granule to PC weight arrays
	GRtoPC_Weights = allocate2DArray<float>(numGR, numTrials);
	arrayInitialize<float>(GRtoPC_Weights[0], 0, numGR*numTrials);
	
// Allocate and Initialize PSTH and Raster arrays
	allMFPSTH = allocate2DArray<ct_uint8_t>(NUM_MF, (csSize+msPreCS+msPostCS));
	arrayInitialize<ct_uint8_t>(allMFPSTH[0], 0, NUM_MF*(csSize+msPreCS+msPostCS) );

	allPCRaster = allocate2DArray<ct_uint8_t>(numPC, (csSize+msPreCS+msPostCS)*(numTrials));	
	arrayInitialize<ct_uint8_t>(allPCRaster[0], 0, numPC*(csSize+msPreCS+msPostCS)*(numTrials) );
	
	allNCRaster = allocate2DArray<ct_uint8_t>(numNC, (csSize+msPreCS+msPostCS)*(numTrials));	
	arrayInitialize<ct_uint8_t>(allNCRaster[0], 0, numNC*(csSize+msPreCS+msPostCS)*(numTrials) );
	
	allIORaster = allocate2DArray<ct_uint8_t>(numIO, (5000)*(numTrials));	
	arrayInitialize<ct_uint8_t>(allIORaster[0], 0, numIO*(5000)*(numTrials) );
	
	allGRPSTH = allocate2DArray<ct_uint8_t>(numGR, (csSize+msPreCS+msPostCS));
	arrayInitialize<ct_uint8_t>(allGRPSTH[0], 0, numGR*(csSize+msPreCS+msPostCS) );		
				
cout << "PSTH and Raster arrays initialized" << endl;	


	
	float medTrials;

	clock_t T;
	int rasterCounter = 0;
	int rasterCounterIO = 0;
	//clock_t tt;
	int grSpkCounter = 0;
	int grSpkCounterPre = 0;

	
	
	float r;
	int tsCSCounter = 0;
	//mfBackRate = new float[4096]; 
	for (trial = 0; trial < numTrials; trial++){
		T = clock();

		int PSTHCounter = 0;	
		int grPSTHCounter = 0;	
		int preCounterGRCS = 0;
		int preCounterGRPre = 0;
		int rasterCounter = 0;
		

		// For-loop runs all trails for the full sum of numTrials. They start with acquisition trials. It is necessary that training trials are the beginning. 
		// If-statements run for the training trails  then 
			
			
			
		if (trial<=numTrainingTrials){	
//TRIAL LOOP BEGINS RUNNING FOR TRAINNG (I.E. ACQUISITION) TRIALS
			for (tts = 0 ; tts <trialTime; tts++){			
				mfAP = joeMFs->calcPoissActivity(mfR, joesim->getMZoneList());
				// Deliver US 
				if (tts == csSize + csStart  ){joesim->updateErrDrive(0,0.3);}
				// Background MF activity in the Pre and Post CS period
				if(tts < csStart || tts >= csStart+csSize){ mfAP = joeMFs->calcPoissActivity(joeMFFreq->getMFBG(), joesim->getMZoneList() ); }	
				// Phasic MF activity during the CS for a duration set in control.h 
				else if(tts >= csStart && tts < csStart + csPhasicSize){mfAP = joeMFs->calcPoissActivity(joeMFFreq->getMFFreqInCSPhasic(), joesim->getMZoneList());}
				// Tonic MF activity during the CS period
				else{mfAP = joeMFs->calcPoissActivity(joeMFFreq->getMFInCSTonicA(), joesim->getMZoneList());}

				bool *isTrueMF = joeMFs->calcTrueMFs(joeMFFreq->getMFBG());
				joesim->updateTrueMFs(isTrueMF);
				joesim->updateMFInput(mfAP);
				joesim->calcActivity(goMin, simNum, GOGR, GRGO, MFGO, gogoW, spillFrac);	

				
				if(tts>=csStart-msPreCS && tts<csStart+csSize+msPostCS){
				//Mossy Fiber array filling as control to confirm that CS is being delivered
					const ct_uint8_t *mfAP = joeMFs->calcPoissActivity(joeMFFreq->getMFInCSTonicA(), joesim->getMZoneList());
					for (int i = 0; i < NUM_MF; i++){
						allMFPSTH[i][PSTHCounter] += mfAP[i];
					}

				//Granule Cell array filling
					const ct_uint8_t* grSpks = joesim->getInputNet()->exportAPGR();			
					for(int i=0; i<numGR; i++){	
						allGRPSTH[i][PSTHCounter] = allGRPSTH[i][PSTHCounter] + grSpks[i]; 
					}

				//Purkinje Cell array filling
					const ct_uint8_t* pcSpks=joesim->getMZoneList()[0]->exportAPPC();
					for(int i=0; i<numPC; i++){
						allPCRaster[i][rasterCounter] = pcSpks[i];
					}
					
				//Deep Nuclei Cell array filling
					const ct_uint8_t* ncSpks=joesim->getMZoneList()[0]->exportAPNC();
					for(int i=0; i<numNC; i++){
						allNCRaster[i][rasterCounter] = ncSpks[i];
					}

				PSTHCounter++;
				rasterCounter++;

				//Basket Cells array filling
	  				/*const ct_uint8_t* bcSpks=joesim->getMZoneList()[0]->exportAPBC();
					for(int i=0; i<numBC; i++){
						allBCRaster[i][rasterCounter] = bcSpks[i];
					}
				//Stellate Cells array filling
	  				const ct_uint8_t* scSpks=joesim->getInputNet()->exportAPSC();
					for(int i=0; i<numSC; i++){
						allSCRaster[i][rasterCounter] = scSpks[i];
					}*/	

					//Golgi Cell array filling
				//	for(int i=0; i<numGO; i++){
				//		allGORaster[i][rasterCounter] = mfAP[i];
				//	}

				//gogoG = joesim->getInputNet()->exportgSum_GOGO();
				//	grgoG = joesim->getInputNet()->exportgSum_GRGO(); 
				//	goSpks = joesim->getInputNet()->exportAPGO();
				//		for(int i=0; i<numGO; i++){	
						//	allGRGORaster[i][rasterCounter] = grgoG[i];
					//		allGORaster[i][rasterCounter] = goSpks[i];
				//			allGOPSTH[i][PSTHCounter] = allGOPSTH[i][PSTHCounter] + goSpks[i];
				//		}
					

				}

			}
		} else {
//IF FORGETTING TRIALS IS NOT ZERO, TRIAL LOOP WILL CONTINUE RUNNING AS FORGETTING TRIALS WITHIN THE else STATEMENT
			for (tts = 0 ; tts <trialTime; tts++){
			//	for(int i=0; i<numGO; i++){
			//		mfR[i] =  mfNoiseRates[tts][i];
			//	}
				//tsCSCounter++;			
				mfAP = joeMFs->calcPoissActivity(mfR, joesim->getMZoneList());
				// Commented out to NOT deliver US 
					//if (tts == csSize + csStart  ){joesim->updateErrDrive(0,0.3);}
				// Background MF activity in the Pre and Post CS period
				if(tts < csStart || tts >= csStart+csSize){ mfAP = joeMFs->calcPoissActivity(joeMFFreq->getMFBG(), joesim->getMZoneList() ); }	
				// Continue  activity during the CS for a duration set in control.h 
				else if(tts >= csStart && tts < csStart + csPhasicSize){mfAP = joeMFs->calcPoissActivity(joeMFFreq->getMFFreqInCSPhasic(), joesim->getMZoneList());}
				// Tonic MF activity during the CS period
				else{mfAP = joeMFs->calcPoissActivity(joeMFFreq->getMFBG(), joesim->getMZoneList());}

				bool *isTrueMF = joeMFs->calcTrueMFs(joeMFFreq->getMFBG());
				joesim->updateTrueMFs(isTrueMF);
				joesim->updateMFInput(mfAP);
				joesim->calcActivity(goMin, simNum, GOGR, GRGO, MFGO, gogoW, spillFrac);	

				
				if(tts>=csStart-msPreCS && tts<csStart+csSize+msPostCS){
				//Mossy Fiber array filling as control to confirm that CS is being delivered
					const ct_uint8_t *mfAP = joeMFs->calcPoissActivity(joeMFFreq->getMFInCSTonicA(), joesim->getMZoneList());
					for (int i = 0; i < NUM_MF; i++){
						allMFPSTH[i][PSTHCounter] += mfAP[i];
					}

				// Granule Cell array filling
					const ct_uint8_t* grSpks = joesim->getInputNet()->exportAPGR();			
					for(int i=0; i<grSaveNumber; i++){	
						allGRPSTH[i][PSTHCounter] = allGRPSTH[i][PSTHCounter] + grSpks[ activeGranuleIndex[i]  ]; 
					}

				//Purkinje Cell array filling
					const ct_uint8_t* pcSpks=joesim->getMZoneList()[0]->exportAPPC();
					for(int i=0; i<numPC; i++){
						allPCRaster[i][rasterCounter] = pcSpks[i];
					}
					
				//Deep Nuclei Cell array filling
					const ct_uint8_t* ncSpks=joesim->getMZoneList()[0]->exportAPNC();
					for(int i=0; i<numNC; i++){
						allNCRaster[i][rasterCounter] = ncSpks[i];
					}

				PSTHCounter++;
				rasterCounter++;

				//Basket Cells array filling
	  				/*const ct_uint8_t* bcSpks=joesim->getMZoneList()[0]->exportAPBC();
					for(int i=0; i<numBC; i++){
						allBCRaster[i][rasterCounter] = bcSpks[i];
					}
				//Stellate Cells array filling
	  				const ct_uint8_t* scSpks=joesim->getInputNet()->exportAPSC();
					for(int i=0; i<numSC; i++){
						allSCRaster[i][rasterCounter] = scSpks[i];
					}*/	

					//Golgi Cell array filling
				//	for(int i=0; i<numGO; i++){
				//		allGORaster[i][rasterCounter] = mfAP[i];
				//	}

				//gogoG = joesim->getInputNet()->exportgSum_GOGO();
				//	grgoG = joesim->getInputNet()->exportgSum_GRGO(); 
				//	goSpks = joesim->getInputNet()->exportAPGO();
				//		for(int i=0; i<numGO; i++){	
						//	allGRGORaster[i][rasterCounter] = grgoG[i];
					//		allGORaster[i][rasterCounter] = goSpks[i];
				//			allGOPSTH[i][PSTHCounter] = allGOPSTH[i][PSTHCounter] + goSpks[i];
				//		}
					

				}

			}
		}
						
	// Granule to Purkinje Cells Weight array filling
		GRtoPC_weight = joesim->getMZoneList()[0]->exportPFPCWeights();
		for (int i = 0; i < numGR; i++)	{
			GRtoPC_Weights[i][trial] = GRtoPC_weight[i];
		}
	
	//Exporting GR PSTHs made in 100 trial chunks
	if (trial%100==0 || trial == numTrials-1){
		cout << "Filling GR PSTH" << endl;

		ofstream myfileGRpsthbin("allGRPSTH_"+to_string(simNum)+"_"+to_string(trial)+".bin", ios::out | ios::binary);	
		for(int i=0; i<numGR; i++){
			for(int j=0; j<(csSize+msPreCS+msPostCS); j++){
				myfileGRpsthbin.write((char*) &allGRPSTH[i][j], sizeof(ct_uint8_t));
			}
		}
		myfileGRpsthbin.close();
		arrayInitialize<ct_uint8_t>(allGRPSTH[0], 0, numGR*(csSize+msPreCS+msPostCS) );	
	}

	// Exporting the MF PSTH only for all the acquistion trials and then all the forgetting trials
	if (trial==numTrainingTrials){
		cout << "Exporting acquisition MF PSTH" << endl;

		ofstream myfileMFpsthbin("allMFPSTH_"+to_string(simNum)+"_Acquisition.bin", ios::out | ios::binary);	
		for(int i=0; i<numMF; i++){
			for(int j=0; j<(csSize+msPreCS+msPostCS); j++){
				myfileMFpsthbin.write((char*) &allMFPSTH[i][j], sizeof(ct_uint8_t));
			}
		}
		myfileMFpsthbin.close();
		arrayInitialize<ct_uint8_t>(allMFPSTH[0], 0, numMF*(csSize+msPreCS+msPostCS) );	
	} else if (trial == numTrials-1){
		cout << "Exporting forgetting MF PSTH" << endl;

		ofstream myfileMFpsthbin("allMFPSTH_"+to_string(simNum)+"_Forgetting.bin", ios::out | ios::binary);	
		for(int i=0; i<numMF; i++){
			for(int j=0; j<(csSize+msPreCS+msPostCS); j++){
				myfileMFpsthbin.write((char*) &allMFPSTH[i][j], sizeof(ct_uint8_t));
			}
		}
		myfileMFpsthbin.close();
		delete2DArray<ct_uint8_t>(allMFPSTH);
	}


	T = clock() - T;
	cout << "Trial time seconds:	" << ((float)T)/CLOCKS_PER_SEC << endl;

	}
	

	delete joestate;
	delete joesim;
	delete joeMFFreq;
	delete joeMFs;
	//delete2DArray<float>(mfNoiseRates);
	//`delete[] mfR;	 



// Save Data 
	cout << "Filling weight files" << endl;
	ofstream myfileWbin("GRtoPC_Weights_ISI"+to_string(csSize)+"_"+to_string(simNum)+".bin", ios::out | ios::binary);	
	for(int i=0; i<numGR; i++){
		for(int j=0; j<numTrials; j++){
			myfileWbin.write((char*) &GRtoPC_Weights[i][j], sizeof(float));
		}
	}
	myfileWbin.close();
	delete2DArray<float>(GRtoPC_Weights);
	

        cout << "Filling PC files" << endl;
	ofstream myfilePCbin("allPCRaster_ISI"+to_string(csSize)+"_"+to_string(simNum)+".bin", ios::out | ios::binary);	
	for(int i=0; i<numPC; i++){
		for(int j=0; j<(numTrials)*(csSize+msPreCS+msPostCS); j++){
			myfilePCbin.write((char*) &allPCRaster[i][j], sizeof(ct_uint8_t));
		}
	}
	myfilePCbin.close();
	delete2DArray<ct_uint8_t>(allPCRaster);
	
	
	cout << "Filling NC files" << endl;
	ofstream myfileNCbin("allNCRaster_ISI"+to_string(csSize)+"_"+to_string(simNum)+".bin", ios::out | ios::binary);	
	for(int i=0; i<numNC; i++){
		for(int j=0; j<(numTrials)*(csSize+msPreCS+msPostCS); j++){
			myfileNCbin.write((char*) &allNCRaster[i][j], sizeof(ct_uint8_t));
		}
	}
	myfileNCbin.close();
	delete2DArray<ct_uint8_t>(allNCRaster);

	
	cout << "Filling IO files" << endl;
	ofstream myfileIObin("allIORaster_ISI_"+to_string(csSize)+"_"+to_string(simNum)+".bin", ios::out | ios::binary);	
	for(int i=0; i<numIO; i++){
		for(int j=0; j<(numTrials)*(5000); j++){
			myfileIObin.write((char*) &allIORaster[i][j], sizeof(ct_uint8_t));
		}
	}
	myfileIObin.close();
	delete2DArray<ct_uint8_t>(allIORaster);

/*	cout << "Filling BC files" << endl;
	ofstream myfileBCbin("allBCRaster.bin", ios::out | ios::binary);	
	for(int i=0; i<numBC; i++){
		for(int j=0; j<(numTrials-preTrialNumber)*(csSize+msPreCS+msPostCS); j++){
			myfileBCbin.write((char*) &allBCRaster[i][j], sizeof(ct_uint8_t));
		}
	}
	myfileBCbin.close();
	delete2DArray<ct_uint8_t>(allBCRaster);

	cout << "Filling SC files" << endl;
	ofstream myfileSCbin("allSCRaster.bin", ios::out | ios::binary);	
	for(int i=0; i<numSC; i++){
		for(int j=0; j<(numTrials-preTrialNumber)*(csSize+msPreCS+msPostCS); j++){
			myfileSCbin.write((char*) &allSCRaster[i][j], sizeof(ct_uint8_t));
		}
	}
	myfileSCbin.close();
	delete2DArray<ct_uint8_t>(allSCRaster);
*/
	
/*	cout << "Filling GO Raster" << endl;
	ofstream myfileSCbin("allGORaster_"+to_string(simNum)+".bin", ios::out | ios::binary);	
	for(int i=0; i<numGO; i++){
		for(int j=0; j<100*(csSize+msPreCS+msPostCS); j++){
			myfileSCbin.write((char*) &allGORaster[i][j], sizeof(ct_uint8_t));
		}
	}
	myfileSCbin.close();
	cout << "GO Raster Filled" << endl;
	delete2DArray<ct_uint8_t>(allGORaster);
	cout << "GO Raster Deleted" << endl;
*/


}



int* Control::getGRIndicies(float CStonicMFfrac) 
{

	int numMF = 4096;
	int numGR = 1048576;


	//float CStonicMFfrac = 0.05;
	float CSphasicMFfrac = 0.0;
	float contextMFfrac = 0.00;
	
	bool* contextMFs = joeMFFreq->getContextMFInd();
	bool* phasicMFs = joeMFFreq->getPhasicMFInd();
	bool* tonicMFsA = joeMFFreq->getTonicMFInd();
	bool* tonicMFsB = joeMFFreq->getTonicMFIndOverlap();
	
	
	int numContext = numMF*contextMFfrac; 
	int numPhasic = numMF*CSphasicMFfrac; 
	int numTonic = numMF*CStonicMFfrac; 
	int numActiveMFs = numTonic;

	cout << "Number of CS MossyFibers:	" << numActiveMFs << endl;
	
	int *activeMFIndA;
	activeMFIndA = new int[numActiveMFs];
	int *activeMFIndB;
	activeMFIndB = new int[numActiveMFs];
	
	int counterMFA=0;
	int counterMFB=0;
	for(int i=0; i<numMF; i++)
	{	
		if(tonicMFsA[i])
		{
			activeMFIndA[ counterMFA ] = i;
			counterMFA++;
		}
		if(tonicMFsB[i])
		{
			activeMFIndB[ counterMFB ] = i;
			counterMFB++;
		}
	}
	cout << "NumMFs in A:	" << counterMFA << endl;
	cout << "NumMFs in B:	" << counterMFB << endl;
	
/*	ofstream fileActMFA;
	fileActMFA.open("mfTonicCSA.txt");
	for(int i=0; i<counterMFA; i++){
		fileActMFA << activeMFIndA[i] << endl;
	}
	ofstream fileActMFB;
	fileActMFB.open("mfTonicCSB.txt");
	for(int i=0; i<counterMFB; i++){
		fileActMFB << activeMFIndB[i] << endl;
	}
*/
	vector<int> MFtoGRs;	
	int numPostSynGRs;
	int *pActiveGRsBool;
	pActiveGRsBool = new int[numGR];
	for(int i=0; i<numGR; i++){ pActiveGRsBool[i]=0;}

	for(int i=0; i<numActiveMFs; i++)
	{
		MFtoGRs = joestate->getInnetConStateInternal()->getpMFfromMFtoGRCon( activeMFIndA[i] );
		numPostSynGRs = MFtoGRs.size();
		
		for(int j=0; j<numPostSynGRs; j++)
		{
			pActiveGRsBool[ MFtoGRs[j] ] = pActiveGRsBool[ MFtoGRs[j] ] + 1;
		}
	
	}
	
	int counterGR = 0;
	for(int i=0; i<numGR; i++)
	{
		if(pActiveGRsBool[i] >= 1)
		{		
			counterGR++;
		}
	}

	int *pActiveGRs;
	pActiveGRs = new int[counterGR];
	for(int i=0; i<counterGR; i++){ pActiveGRs[i]=0;}

	int counterAGR=0;
	for(int i=0; i<numGR; i++)
	{
		if(pActiveGRsBool[i] >= 1)
		{		
			pActiveGRs[counterAGR] = i;
			counterAGR++;
		}
		
	}	

	return pActiveGRs;

}


int Control::getNumGRIndicies(float CStonicMFfrac) 
{
	int numMF = 4096;
	int numGR = 1048576;


	//float CStonicMFfrac = 0.05;
	float CSphasicMFfrac = 0.0;
	float contextMFfrac = 0.0;
	
	bool* contextMFs = joeMFFreq->getContextMFInd();
	bool* phasicMFs = joeMFFreq->getPhasicMFInd();
	bool* tonicMFs = joeMFFreq->getTonicMFInd();
	
	int numContext = numMF*contextMFfrac; 
	int numPhasic = numMF*CSphasicMFfrac; 
	int numTonic = numMF*CStonicMFfrac; 
	int numActiveMFs = numContext+numPhasic+numTonic;
	
	int *activeMFInd;
	activeMFInd = new int[numActiveMFs];
	
	int counterMF=0;
	for(int i=0; i<numMF; i++)
	{	
		if(contextMFs[i] || tonicMFs[i] || phasicMFs[i])
		{
			activeMFInd[ counterMF ] = i;
			counterMF++;
		}
	}

	vector<int> MFtoGRs;	
	int numPostSynGRs;
	int *pActiveGRsBool;
	pActiveGRsBool = new int[numGR];
	for(int i=0; i<numGR; i++){ pActiveGRsBool[i]=0;}


	for(int i=0; i<numActiveMFs; i++)
	{
		MFtoGRs = joestate->getInnetConStateInternal()->getpMFfromMFtoGRCon( activeMFInd[i] );
		numPostSynGRs = MFtoGRs.size();
		
		for(int j=0; j<numPostSynGRs; j++)
		{
			pActiveGRsBool[ MFtoGRs[j] ] = pActiveGRsBool[ MFtoGRs[j] ] + 1;
		}
	}
	
	int counterGR = 0;
	for(int i=0; i<numGR; i++)
	{
		if(pActiveGRsBool[i] >= 1)
		{		
			counterGR++;
		}
	}

	return counterGR;

}



