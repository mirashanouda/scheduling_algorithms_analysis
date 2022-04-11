#include "PreSJF.h"

PreSJF::PreSJF(vector<preProc> proc)
{
	myProc.resize(proc.size());
	for (int i = 0; i < proc.size(); ++i) {
		//myProc[i].pid = proc[i].pid;
		myProc[i].arrivalTime = proc[i].arrivalTime;
		myProc[i].cpuBurst = proc[i].cpuBurst;
		//myProc[i].priority = proc[i].priority;
		myProc[i].remainingTime = myProc[i].cpuBurst;
	}
	//myProc = proc;
	clk = 0;
}

int PreSJF::minRemaining()
{
	int min = INT_MAX;
	int minPro = 0;

	for (int i = 0; i < myProc.size(); ++i) {
		//if (myProc[i].arrivalTime <= clk &&
		//	myProc[i].remainingTime == min &&
		//	myProc[i].remainingTime != 0) {
		//
		//	min = myProc[i].remainingTime;
		//	minPro = i;
		//}

		if (myProc[i].arrivalTime <= clk &&
			myProc[i].remainingTime <= min &&
			myProc[i].remainingTime != 0) {

			//cout << "PID = " << myProc[i].pid << " -- burst = " << myProc[i].cpuBurst << " -- arrival = " << myProc[i].arrivalTime << endl; 
			min = myProc[i].remainingTime;
			minPro = i;
		}
	}
	//cout << "clk = " << clk << " -- PID " << minPro+1 << " is picked\n";
	return minPro;
}


void PreSJF::scheduler() {
	int execProc;
	int burst0 = 0;

	while (burst0 < myProc.size()) { //while there are unfinished proc -- burst != 0
		execProc = minRemaining();
		//cout << "P" << myProc[execProc].pid << " is picked\n";

		
		
		
		//Process not yet started 
		if (myProc[execProc].cpuBurst == myProc[execProc].remainingTime) {
			myProc[execProc].startTime = clk;	//Assigning a start time 
		}

		//once picked --> decrement the remaining time
		myProc[execProc].remainingTime--;

		//Process finished:
		if (myProc[execProc].remainingTime == 0) {
			myProc[execProc].completionTime = clk + 1;  //the finishing time
			myProc[execProc].turnAroundTime = myProc[execProc].completionTime - myProc[execProc].arrivalTime;
			myProc[execProc].waitingTime = myProc[execProc].turnAroundTime - myProc[execProc].cpuBurst;
			burst0++;
			//cout << "P" << execProc << " -- arrived: " << myProc[execProc].arrivalTime  << " -- start: " << myProc[execProc].startTime << " -- finish: " << myProc[execProc].completionTime << endl;
		}
		clk++;
	}
	//printResults();
}

double PreSJF::getAvgWait() {
	int totalWait = 0;
	double avgWait;
	for (int i = 0; i < myProc.size(); ++i) {
		totalWait = totalWait + myProc[i].waitingTime;
	}

	avgWait = totalWait / double(myProc.size());
	return avgWait;
}
void PreSJF::printProc()
{
	printf("PID | Burst | Arrival\n");
	for (int i = 0; i < myProc.size(); ++i) {
		printf("%d   |  %d  |   %d\n", i+1 , myProc[i].cpuBurst, myProc[i].arrivalTime);
	}
	cout << endl;
}

double PreSJF::getAvgTurnAround()
{
	int totalTurnAround = 0;
	double avgTurnAround;
	for (int i = 0; i < myProc.size(); ++i) {
		totalTurnAround = totalTurnAround + myProc[i].turnAroundTime;
	}

	avgTurnAround = totalTurnAround / double(myProc.size());
	return avgTurnAround;
}

double PreSJF::getAvgResponse()
{
	int totalResponse = 0;
	double avgResponse;
	for (int i = 0; i < myProc.size(); ++i) {
		totalResponse = totalResponse + myProc[i].responseTime;
	}

	avgResponse = totalResponse / double(myProc.size());
	return avgResponse;
}

void PreSJF::printResults()
{
	//printf("PID | Completion | Waiting | TurnAround\n");
	////cout << setw(10)  << "PID" << setw(10) << "Completion" << setw(10) << "Waiting" << endl;
	//for (int i = 0; i < myProc.size(); ++i) {
	//	printf(" %d  |     %d	 |   %d    |     %d     \n", i + 1, myProc[i].completionTime, myProc[i].waitingTime, myProc[i].turnAroundTime);
	//}
	cout << endl;
	cout << "Avarage Waiting	   = " << getAvgWait() << endl;
	cout << "Avarage TunringAround = " << getAvgTurnAround() << endl;
	cout << "Avarage Response	   = " << getAvgResponse() << endl << endl;
}
PreSJF::~PreSJF()
{
}
