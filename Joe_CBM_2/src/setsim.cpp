#include "setsim.h"
#include <string>

	
	


SetSim::SetSim(int fileNum, int goRecipParam){
	
	
	fstream actPF;
	fstream conPF;
	
	
	if(fileNum == 0){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	//	conPF.open("../CBM_Params/conParams_binChoice2_1.txt");
	}
	if(fileNum == 1){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	//	conPF.open("../CBM_Params/conParams_binChoice2_2.txt");
	}
	if(fileNum == 2){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	//	conPF.open("../CBM_Params/conParams_binChoice2_3.txt");
	}
	if(fileNum == 3){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	//	conPF.open("../CBM_Params/conParams_binChoice2_4.txt");
	}
	if(fileNum == 4){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	//	conPF.open("../CBM_Params/conParams_binChoice2_5.txt");
	}
	if(fileNum == 5){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	//	conPF.open("../CBM_Params/conParams_binChoice2_6.txt");
	}
	if(fileNum == 6){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	//	conPF.open("../CBM_Params/conParams_binChoice2_7.txt");
	}
	if(fileNum == 7){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	//	conPF.open("../CBM_Params/conParams_binChoice2_8.txt");
	}
	if(fileNum == 8){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	//	conPF.open("../CBM_Params/conParams_binChoice2_9.txt");
	}
	if(fileNum == 9){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	}
	if(fileNum == 10){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	}
	if(fileNum == 11){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	}
	if(fileNum == 12){
		actPF.open("../CBM_Params/actParams_binChoice2_1.txt");			
	}
	if(fileNum == 13){
		actPF.open("../CBM_Params/actParams_binChoice2_14.txt");			
	}
	if(fileNum == 14){
		actPF.open("../CBM_Params/actParams_binChoice2_15.txt");			
	}
	if(fileNum == 15){
		actPF.open("../CBM_Params/actParams_binChoice2_16.txt");			
	}
	if(fileNum == 16){
		actPF.open("../CBM_Params/actParams_binChoice2_17.txt");			
	}
	if(fileNum == 17){
		actPF.open("../CBM_Params/actParams_binChoice2_18.txt");			
	}
	if(fileNum == 18){
		actPF.open("../CBM_Params/actParams_binChoice2_19.txt");			
	}
	if(fileNum == 19){
		actPF.open("../CBM_Params/actParams_binChoice2_20.txt");			
	}
	if(fileNum == 20){
		actPF.open("../CBM_Params/actParams_binChoice2_21.txt");			
	}
	if(fileNum == 21){
		actPF.open("../CBM_Params/actParams_binChoice2_22.txt");			
	}
	if(fileNum == 22){
		actPF.open("../CBM_Params/actParams_binChoice2_23.txt");			
	}
	if(fileNum == 23){
		actPF.open("../CBM_Params/actParams_binChoice2_24.txt");			
	}
	if(fileNum == 24){
		actPF.open("../CBM_Params/actParams_binChoice2_25.txt");			
	}
	
	
		cout << "YO" << endl;
	
	
	
	conPF.open("../CBM_Params/conParams_binChoice2.txt");

	state = new CBMState(actPF, conPF, 1, goRecipParam);
	cout << "opened" << endl;	
	actPF.close();
	conPF.close();
};

SetSim::~SetSim(){};





CBMState* SetSim::getstate(){
	return state;
}


CBMSimCore *SetSim::getsim(){
	
	sim = new CBMSimCore(state, gpuIndex, gpuP2);


	return sim;
}	


ECMFPopulation* SetSim::getMFFreq(float csMinRate, float csMaxRate){
	unsigned int numMF = state->getConnectivityParams()->getNumMF(); 		
	bool collaterals_off = false;
	float fracImport = 0.0;
	bool secondCS = true;
	float fracOverlap = 0.2;

	MFFreq = new ECMFPopulation(							
		numMF, randseed, 
		CStonicMFfrac, CSphasicMFfrac, contextMFfrac, nucCollfrac,
		bgFreqMin, csbgFreqMin, contextFreqMin, csMinRate, phasicFreqMin,
		bgFreqMax, csbgFreqMax, contextFreqMax, csMaxRate, phasicFreqMax,
		collaterals_off, fracImport, secondCS, fracOverlap); 

	return MFFreq;
}


PoissonRegenCells* SetSim::getMFs(){
	unsigned int numMF = state->getConnectivityParams()->getNumMF(); 		
	unsigned int numNC = state->getConnectivityParams()->getNumNC();
	float msPerTimeStep = state->getActivityParams()->getMSPerTimeStep() * 1.0;

	MFs = new PoissonRegenCells(						 
		numMF, randseed, threshDecayTau, msPerTimeStep, numMZs, numNC);

	
	return MFs;
}





