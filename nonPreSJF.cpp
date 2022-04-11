#include "nonPreSJF.h"

nonPreSJF::nonPreSJF(vector<preProc> proc)
{
	//cheking if there is a burst == 0
	//don't consider it 
	myProc.resize(proc.size());
	for (int i = 0;  i < proc.size(); ++i) {
		//myProc[i].pid = proc[i].pid;
		myProc[i].arrivalTime = proc[i].arrivalTime;
		myProc[i].cpuBurst = proc[i].cpuBurst;
		//myProc[i].priority = proc[i].priority;
		myProc[i].remainingTime = myProc[i].cpuBurst;
	}
	//myProc = proc;
	clk = 0; 
}

int nonPreSJF::minBurst()
{
	int min = INT_MAX;
	int minPro = 0;

	for (int i = 0; i < myProc.size(); ++i) {
		//if (myProc[i].arrivalTime <= clk &&
		//	myProc[i].cpuBurst == min &&
		//	myProc[i].cpuBurst != 0) {
		//
		//	min = myProc[i].remainingTime;
		//	minPro = i;
		//}

		if (myProc[i].arrivalTime <= clk && 
			myProc[i].cpuBurst <= min &&
			myProc[i].cpuBurst != 0) {

			//cout << "PID = " << myProc[i].pid << " -- burst = " << myProc[i].cpuBurst << " -- arrival = " << myProc[i].arrivalTime << endl; 
			min = myProc[i].cpuBurst;
			minPro = i;
		}
	}
	//cout << "clk = " << clk << " -- PID " << minPro+1 << " is picked\n";
	return minPro;
}


void nonPreSJF::scheduler() {
	int execProc; 
	for (int num = 0; num < myProc.size(); ++num) { //while there are ready/runable processes
		execProc = minBurst(); 

		myProc[execProc].startTime = clk;		//start time 
		clk = clk + myProc[execProc].cpuBurst;  //editing the clk
		myProc[execProc].completionTime = clk;  //the finishing time 
		myProc[execProc].turnAroundTime = myProc[execProc].completionTime - myProc[execProc].arrivalTime;
		myProc[execProc].responseTime = myProc[execProc].startTime - myProc[execProc].arrivalTime;
		myProc[execProc].waitingTime = myProc[execProc].turnAroundTime - myProc[execProc].cpuBurst;
		myProc[execProc].cpuBurst = 0;

		//cout << "P" << execProc << " -- start: " << myProc[execProc].startTime << " -- finish: " << myProc[execProc].completionTime  << " -- waiting: " << myProc[execProc].waitingTime << " -- TurnA: " << myProc[execProc].turnAroundTime << endl;
	}
	printResults();
}

double nonPreSJF::getAvgWait() {
	int totalWait = 0;
	double avgWait; 
	for (int i = 0; i < myProc.size(); ++i) {
		totalWait = totalWait + myProc[i].waitingTime;
	}

	avgWait = totalWait / double(myProc.size());
	return avgWait;
}
double nonPreSJF::getAvgTurnAround()
{
	int totalTurnAround = 0;
	double avgTurnAround;
	for (int i = 0; i < myProc.size(); ++i) {
		totalTurnAround = totalTurnAround + myProc[i].turnAroundTime;
	}

	avgTurnAround = totalTurnAround / double(myProc.size());
	return avgTurnAround;
}
double nonPreSJF::getAvgResponse()
{
	int totalResponse = 0;
	double avgResponse;
	for (int i = 0; i < myProc.size(); ++i) {
		totalResponse = totalResponse + myProc[i].responseTime;
	}
	avgResponse = totalResponse / double(myProc.size());
	return avgResponse;
}
void nonPreSJF::printProc()
{
	printf("PID | Burst | Arrival\n");
	for (int i = 0; i < myProc.size(); ++i) {
		printf("%d   |  %d  |   %d\n", i + 1, myProc[i].cpuBurst, myProc[i].arrivalTime);
	}
	cout << endl;
}
void nonPreSJF::printResults()
{
	//printf("PID | Completion | Waiting | TurnAround\n");
	//cout << setw(10)  << "PID" << setw(10) << "Completion" << setw(10) << "Waiting" << endl;
	//for (int i = 0; i < myProc.size(); ++i) {
	//	//printf(" %d  |     %d	 |   %d    |     %d     \n", i, myProc[i].completionTime, myProc[i].waitingTime, myProc[i].turnAroundTime);
	//}

	cout << "Avarage Waiting	   = " << getAvgWait() << endl;
	cout << "Avarage TunringAround = " << getAvgTurnAround() << endl << endl;
	cout << "Avarage Response	   = " << getAvgResponse() << endl << endl;
}

nonPreSJF::~nonPreSJF()
{
}
