#include "FCFS.h"

FCFS::FCFS(vector <preProc> proc)
{
    myProc.resize(proc.size());
    for (int i = 0; i < proc.size(); ++i) {
        myProc[i].arrivalTime = proc[i].arrivalTime;
        myProc[i].cpuBurst = proc[i].cpuBurst;
        myProc[i].priority = proc[i].priority;
        myProc[i].remainingTime = myProc[i].cpuBurst;
    }
	clk = 0; 
}

int FCFS::firstArrival()
{
	int minArrival = INT_MAX;
	int firstProc = 0;

	for (int i = 0; i < myProc.size(); ++i) {
		if (myProc[i].arrivalTime <= clk && 
            myProc[i].arrivalTime < minArrival && 
            myProc[i].remainingTime > 0) {
			minArrival = myProc[i].arrivalTime;
			firstProc = i;
		}
	}
	return firstProc;
}


void FCFS::scheduler()
{
// search for proces that has the smalles tarrival time, this means it is theprocess that you should run
//wonce you choose it to run save the clk time in "startTime" to know when process started
// for this process that you should run, check its burst time to know for how long it will run and modifiy the 
// ... clk time (clk +burst), turnaround time, and waiting time accordingly
    for(int num = 0 ;num < myProc.size(); num++)
    {
        int i = firstArrival();   

        myProc[i].startTime = clk;
        clk += myProc[i].cpuBurst;
        
        //int turnAroundTime; //completionTime - arrivalTime
        //int responseTime;   // startTime - arrivalTime 
        //int waitingTime;    // turnAroundTime - cpuBurst 
        myProc[i].completionTime = myProc[i].startTime + myProc[i].cpuBurst;
        myProc[i].responseTime = myProc[i].startTime - myProc[i].arrivalTime;
        myProc[i].turnAroundTime = myProc[i].completionTime - myProc[i].arrivalTime;
        myProc[i].waitingTime = myProc[i].turnAroundTime - myProc[i].cpuBurst;
        myProc[i].remainingTime = 0; // set cpu burst= 0 to indicate that the process has finished execution so as if it's no longer in the vector.
    }
    printResults();
}

double FCFS::getAvgWait()
{
    int totalWait = 0;
    for(int i=0; i< myProc.size(); i++)
    {
        totalWait += myProc[i].waitingTime;
    }
    double avgWait = totalWait/ double(myProc.size());
    return avgWait;
}

double FCFS::getAvgResponse()
{
    int totalResponse = 0;
    for(int i=0; i< myProc.size(); i++)
    {
        totalResponse += myProc[i].responseTime;
    }
    double avgResponse = totalResponse/ double(myProc.size());
    return avgResponse;
}

double FCFS::getAvgTurnAround()
{
    int totalTurnAround = 0;
    for(int i=0; i< myProc.size(); i++)
    {
        totalTurnAround += myProc[i].turnAroundTime;
    }
    double avgTurnAround = totalTurnAround/ double(myProc.size());
    return avgTurnAround;
}

void FCFS::printProc()
{
    printf("PID | Burst | Arrival\n");
    for (int i = 0; i < myProc.size(); ++i) {
        printf("%d   |  %d  |   %d\n", i + 1, myProc[i].cpuBurst, myProc[i].arrivalTime);
    }
    cout << endl;
}

void FCFS::printResults()
{
    //printf("PID | Completion | Waiting | TurnAround\n");
    ////cout << setw(10)  << "PID" << setw(10) << "Completion" << setw(10) << "Waiting" << endl;
    //for (int i = 0; i < myProc.size(); ++i) {
    //	printf(" %d  |     %d	 |   %d    |     %d     \n", i+1, myProc[i].completionTime, myProc[i].waitingTime, myProc[i].turnAroundTime);
    //}
    cout << "Avarage Waiting	   = " << getAvgWait() << endl;
    cout << "Avarage TunringAround = " << getAvgTurnAround() << endl;
    cout << "Avarage Response	   = " << getAvgResponse() << endl << endl;
}

FCFS::~FCFS()
{
}
