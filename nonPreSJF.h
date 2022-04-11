#pragma once
#include "defs.h"

class nonPreSJF
{
private:
	vector<process> myProc; 
	int clk; 

public:
	nonPreSJF(vector<preProc> proc);
	int minBurst();	//linear search O(n) 
	void scheduler();
	double getAvgWait();
	double getAvgTurnAround();
	double getAvgResponse();
	void printProc();
	void printResults();
	~nonPreSJF(); 
};
