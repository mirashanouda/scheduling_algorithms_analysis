#pragma once
#include "defs.h"

class MLQ
{
private:
	vector <process> myProc;
	int clk;
	int highestPriority;
	const int timeslice = 2; //for RR

public:
	MLQ(vector<preProc> proc);
	int maxP(vector <process> proc);
	int firstArrival();
	void scheduler();
	double getAvgWait();
	double getAvgResponse();
	double getAvgTurnAround();
	void printResults();
	void printProc();
	~MLQ();
};
