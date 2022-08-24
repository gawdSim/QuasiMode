#include "../includes/main.h"
#include <time.h>
#include <math.h>
using namespace std;

int main(){

int minAcqTrials = 500;
int numTrainingTrials = ceil(minAcqTrials*1.5);
int numForgetTrials = numTrainingTrials*10;
int numExtinctionTrials = 0;
int homeoTuningTrials = 0;
int granuleActivityDetectionTrials = 0;

int numTrials = homeoTuningTrials+granuleActivityDetectionTrials+numTrainingTrials+numForgetTrials+numExtinctionTrials;  

float csTonicF = 0.05;
float CSlength[10] = {250, 500, 750, 1000, 1250, 1500, 1750, 2000, 2250, 2500};
float goMin = 0.26;



float GRGO;
float MFGO;

float GOGR = 0.017;
float spillFrac = 0.15;

float csRateMin = 100.0;
float csRateMax = 110.0;




float grW = 0.0007;
float mfW = 0.0035;


float ws = 0.9;//1.01;
float numcon = 10;


float gogoW;
clock_t ttt;
ttt = clock();
for(int i=0; i<1; i++){	
	cout << "ParamNum:  " << i << endl;
	for(int j=0; j<1; j++){
		for(int k=1; k<2; k++){

			GRGO = grW * (ws);
			MFGO = mfW * (ws);
			gogoW = 0.0125;			

			for(int simNum=5; simNum<10; simNum++){
				// i refers to FileNum 
				// j refers to inputStrength
				// k refers to goRecipParam and marking the CS length --> goRecipParam is a remnant that carries no value
				// simNum refers to simNum
				Control joeSimulation;
				//joeSimulation.runTuningSimulation(homeoTuningTrials, numTrials, num, CSlength, csTonicF, goMin);
				joeSimulation.runSimulationWithGRdata(i, k, granuleActivityDetectionTrials, numTrials, numTrainingTrials, simNum, CSlength[k], csTonicF, goMin, GOGR, GRGO, MFGO, csRateMin, csRateMax, gogoW, j, spillFrac);
			}
		}
	}
}
	ttt = clock() - ttt;
	cout << "Simulation time seconds:	" << ((float)ttt)/CLOCKS_PER_SEC << endl;

}

