#pragma once
#include "defs.h"

class RR
{
private:
	vector<process> myProc;
	int clk; 
    const int timeslice = 5;    // for RR only

public:
	RR(vector<preProc> proc);
	int firstArrival();
	void scheduler();
	double getAvgWait();
	double getAvgResponse();
	double getAvgTurnAround();
	void printProc();
	void printResults();
	~RR(); 
};
//looks for first arribval time