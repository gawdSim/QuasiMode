#include "../includes/main.h"
#include <time.h>
using namespace std;

int main(){

int numTrainingTrials = 1000;
int homeoTuningTrials = 0;
int granuleActivityDetectionTrials = 0;

int numTrials = homeoTuningTrials+granuleActivityDetectionTrials+numTrainingTrials;  
float csTonicF = 0.05;
float CSlength[10] = {250, 500, 750, 1000, 1250, 1500, 1750, 2000, 2250, 2500};//{250, 500, 750, 1000, 1250, 1500, 1750, 2000, 2250, 2500, 2750};
float goMin = 0.26;



float GRGO;
float MFGO;

float GOGR = 0.015;
float spillFrac = 0.15;

float csRateMin = 100.0;
float csRateMax = 110.0;




float grW = 0.0007;
float mfW = 0.0035;
//float ws[5] = {0.9125, 0.975, 1.0375, 1.1, 1.1625};//0.9125;
//float gogoW[5] = {0.0125, 0.107, 0.0094, 0.0083, 0.0075};


//float ws[25] = {1.15, 1.175, 1.2, 1.225, 1.25, 1.275, 1.3, 1.325, 1.35, 1.3775, 1.3775, 1.3825, 1.3925, 1.42, 1.42, 1.425, 1.4375, 1.44, 1.45, 1.4525, 1.455, 1.46, 1.4625, 1.4625, 1.4625}; //0.25
//float gogr[9] = {0.001, 0.0025, 0.0052, 0.0095, 0.014, 0.015, 0.016, 0.016, 0.016};
//float ws[25] = {0.99, 1.015, 1.04, 1.065, 1.09, 1.115, 1.14, 1.1675, 1.2025, 1.23, 1.26, 1.2675, 1.2825, 1.2975, 1.3, 1.3075, 1.3075, 1.31, 1.3225, 1.33, 1.3325, 1.3325, 1.3325, 1.34, 1.34}; //0.2
//float gogr[5] = {0.00125, 0.0025, 0.0055, 0.0095, 0.01325};
//float ws[25] = {0.785, 0.83, 0.875, 0.92, 0.965, 1.01, 1.055, 1.075, 1.1025, 1.1425, 1.1475, 1.1475, 1.1575, 1.1675, 1.175, 1.18, 1.18, 1.1825, 1.1825, 1.2, 1.2, 1.1025, 1.1025, 1.1025, 1.1025};//0.15
//float gogr[5] = {0.0013, 0.0033, 0.007, 0.011, 0.014};
//float ws[25] = {0.9175, 0.9275, 0.9375, 0.9475, 0.9575, 0.9675, 0.9775, 0.9775, 0.9875, 1.0, 1.01, 1.015, 1.0175, 1.0325, 1.0325, 1.04, 1.0425, 1.045, 1.045, 1.045, 1.045, 1.045, 1.05, 1.055, 1.055};//0.1
//float gogr[6] = {0.0375, 0.035, 0.0275, 0.022, 0.017, 0.016};


//float numcon[25] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50}; 


float ws = 0.4;//1.01;
float numcon = 12;


float gogoW;
clock_t ttt;
ttt = clock();
for(int i=0; i<1; i++){	
	cout << "ParamNum:  " << i << endl;
	for(int j=0; j<1; j++){
		for(int k=4; k<6; k++){
	


			GRGO = grW * (ws);
			MFGO = mfW * (ws);
			gogoW = 0.15/numcon;			

			for(int num=5; num<10; num++){
				
				Control joeSimulation;
				//joeSimulation.runTuningSimulation(homeoTuningTrials, numTrials, num, CSlength, csTonicF, goMin);
				joeSimulation.runSimulationWithGRdata(i, k, homeoTuningTrials, granuleActivityDetectionTrials, numTrials, num, CSlength[k], csTonicF, goMin, GOGR, GRGO, MFGO, csRateMin, csRateMax, gogoW, j, i, spillFrac);
			}
		}
	}
}
	ttt = clock() - ttt;
	cout << "Simulation time seconds:	" << ((float)ttt)/CLOCKS_PER_SEC << endl;

}

