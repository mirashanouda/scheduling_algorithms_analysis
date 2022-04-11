#include "RR.h"

RR::RR(vector <preProc> proc)
{
    myProc.resize(proc.size());
    for (int i = 0; i < proc.size(); ++i) {
        //myProc[i].pid = proc[i].pid;
        myProc[i].arrivalTime = proc[i].arrivalTime;
        myProc[i].cpuBurst = proc[i].cpuBurst;
        //myProc[i].priority = proc[i].priority;
        myProc[i].remainingTime = myProc[i].cpuBurst;
        myProc[i].queueTime = double(myProc[i].arrivalTime);
    }
    clk = 0; 
}

int RR::firstArrival()
{
	double minArrival = INT_MAX;
	int firstProc = 0;

	for (int i = 0; i < myProc.size(); ++i) {
		if (myProc[i].queueTime <= clk &&
            //i != preP &&
            myProc[i].queueTime <= minArrival &&
            myProc[i].remainingTime > 0) {
			minArrival = myProc[i].queueTime;
			firstProc = i;
		}
	}
	return firstProc;
}

//void RR::constructQueue()
//{
//    for (int i = 0; i < myProc.size(); ++i) {
//        if (myProc[i].arrivalTime <= clk) {
//            queueProc.push(myProc[i]);
//        }
//    }
//}


void RR::scheduler()
{
    int num = 0;
    while(num < myProc.size())
    {
        int i = firstArrival();
        //queueProc.push(myProc[i]);

        cout << "P" << i + 1 << " is picked\n";
        if (myProc[i].cpuBurst == myProc[i].remainingTime)
            myProc[i].startTime = clk;
        // check fi cpu burst < timeslic then... .. means the process finished

        if(myProc[i].remainingTime <= timeslice)
        {
            clk += myProc[i].remainingTime;
           // TODO: change the below line because we are not sure that this the completeiton time. completeion time is equal to the current lock where the remainting time = 0;
            myProc[i].completionTime = clk;
            myProc[i].turnAroundTime = myProc[i].completionTime - myProc[i].arrivalTime;
            myProc[i].waitingTime = myProc[i].turnAroundTime - myProc[i].cpuBurst;
            myProc[i].responseTime = myProc[i].startTime - myProc[i].arrivalTime;
            myProc[i].remainingTime = 0; 
            num++;
            //cout << "P" << i+1 << " -- start: " << myProc[i].startTime << " -- finish: " << myProc[i].completionTime << " -- waiting: " << myProc[i].waitingTime << " -- TurnA: " << myProc[i].turnAroundTime << endl;
        }
        // else - means the process still didn't finish 
        else{
            clk += timeslice;
            myProc[i].remainingTime = myProc[i].remainingTime - timeslice;
            //constructQueue();
            myProc[i].queueTime = clk + 0.5;
            //queueProc.push(myProc[i]);
        }
        
        //int turnAroundTime; //completionTime - arrivalTime
        //int responseTime;   // startTime - arrivalTime 
        //int waitingTime;    // turnAroundTime - cpuBurst 
        //set cpu burst= 0 to indicate that the process has finished execution so as if it's no longer in the vector.
    }
    printResults();
}
double RR::getAvgWait()
{
    int totalWait = 0;
    for(int i=0; i < myProc.size(); i++)
    {
        totalWait += myProc[i].waitingTime;
        cout << "current wait = " << myProc[i].waitingTime << endl;
        
    }
    double avgWait = totalWait/ double(myProc.size());
    cout << "total wait = " << totalWait << endl;
    return avgWait;
}

double RR::getAvgResponse()
{
    int totalResponse = 0;
    for(int i=0; i< myProc.size(); i++)
    {
        totalResponse += myProc[i].responseTime;
    }
    double avgResponse = totalResponse/ double(myProc.size());
    return avgResponse;
}

double RR::getAvgTurnAround()
{
    int totalTurnAround = 0;
    for(int i=0; i< myProc.size(); i++)
    {
        totalTurnAround += myProc[i].turnAroundTime;
    }
    double avgTurnAround = totalTurnAround/ double(myProc.size());
    return avgTurnAround;
}

void RR::printProc()
{
    printf("PID | Burst | Arrival\n");
    for (int i = 0; i < myProc.size(); ++i) {
        printf("%d   |  %d  |   %d\n", i + 1, myProc[i].cpuBurst, myProc[i].arrivalTime);
    }
    cout << endl;
}

void RR::printResults()
{
    //printf("PID | Completion | Waiting | TurnAround\n");
    ////cout << setw(10)  << "PID" << setw(10) << "Completion" << setw(10) << "Waiting" << endl;
    //for (int i = 0; i < myProc.size(); ++i) {
    //    printf(" %d  |     %d	 |   %d    |     %d     \n", i + 1, myProc[i].completionTime, myProc[i].waitingTime, myProc[i].turnAroundTime);
    //}
    cout << endl;
    cout << "Avarage Waiting	   = " << getAvgWait() << endl;
    cout << "Avarage TunringAround = " << getAvgTurnAround() << endl;
    cout << "Avarage Response	   = " << getAvgResponse() << endl << endl;
}

RR::~RR()
{
}
