#pragma once
#include "defs.h"

class FCFS
{
private:
	vector <process> myProc; 
	int clk; 

public:
	FCFS(vector<preProc> proc);
	int firstArrival();
	void scheduler();
	double getAvgWait();
	double getAvgResponse();
	double getAvgTurnAround();
	void printProc();
	void printResults();
	~FCFS(); 
};
//looks for first arribval time