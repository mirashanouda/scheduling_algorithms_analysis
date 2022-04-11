#pragma once
#include "defs.h"

class PreSJF
{
private: 
	vector<process> myProc;
	int clk;

public:
	PreSJF(vector<preProc> proc);
	int minRemaining();	//linear search O(n) 
	void scheduler();
	double getAvgWait();
	double getAvgTurnAround();
	double getAvgResponse();
	void printProc();
	void printResults();
	~PreSJF();
};
