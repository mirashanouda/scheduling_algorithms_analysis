#include "MLQ.h"

MLQ::MLQ(vector <preProc> proc)
{
    myProc.resize(proc.size());
    for (int i = 0; i < proc.size(); ++i) {
        myProc[i].arrivalTime = proc[i].arrivalTime;
        myProc[i].cpuBurst = proc[i].cpuBurst;
        myProc[i].priority = proc[i].priority;
        myProc[i].remainingTime = myProc[i].cpuBurst;
        myProc[i].queueTime = double(myProc[i].arrivalTime);
    }
    clk = 0;
}

int MLQ::maxP(vector <process> proc) //function to find max priority of all processes 
{
    int maxPriority = 0;
    for (int i = 0; i < myProc.size(); ++i) {
        if (myProc[i].priority > maxPriority && myProc[i].remainingTime > 0)
            maxPriority = myProc[i].priority;
    }
    return maxPriority;
}

int MLQ::firstArrival()
{
    double minArrival = INT_MAX;
    int firstProc = 0;

    for (int i = 0; i < myProc.size(); ++i) {
        if (myProc[i].queueTime <= clk && myProc[i].queueTime <= minArrival && myProc[i].remainingTime > 0
            && myProc[i].priority == highestPriority) {
            minArrival = myProc[i].queueTime;
            firstProc = i;
        }
    }
    return firstProc;
}

void MLQ::scheduler()
{
    int num = 0;
    while (num < myProc.size())
    {
        highestPriority = maxP(myProc);
        int i = firstArrival();

        //cout << "P" << i + 1 << " is picked\n";
        if (myProc[i].cpuBurst == myProc[i].remainingTime)
            myProc[i].startTime = clk;
        // check fi cpu burst < timeslic then... .. means the process finished

        if (myProc[i].remainingTime <= timeslice)
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
        else {
            clk += timeslice;
            myProc[i].remainingTime = myProc[i].remainingTime - timeslice;
            myProc[i].queueTime = clk + 0.5;
        }
    }
    printResults();
}
double MLQ::getAvgWait()
{
    int totalWait = 0;
    for (int i = 0; i < myProc.size(); i++)
    {
        totalWait += myProc[i].waitingTime;
        //cout << "current wait = " << myProc[i].waitingTime << endl;

    }
    double avgWait = totalWait / double(myProc.size());
    //cout << "total wait = " << totalWait << endl;
    return avgWait;
}

double MLQ::getAvgResponse()
{
    int totalResponse = 0;
    for (int i = 0; i < myProc.size(); i++)
    {
        totalResponse += myProc[i].responseTime;
    }
    double avgResponse = totalResponse / double(myProc.size());
    return avgResponse;
}

double MLQ::getAvgTurnAround()
{
    int totalTurnAround = 0;
    for (int i = 0; i < myProc.size(); i++)
    {
        totalTurnAround += myProc[i].turnAroundTime;
    }
    double avgTurnAround = totalTurnAround / double(myProc.size());
    return avgTurnAround;
}

void MLQ::printProc()
{
    printf("PID | Burst | Arrival\n");
    for (int i = 0; i < myProc.size(); ++i) {
        printf("%d   |  %d  |   %d\n", i + 1, myProc[i].cpuBurst, myProc[i].arrivalTime);
    }
    cout << endl;
}

void MLQ::printResults()
{
    printf("PID | Completion | Waiting | TurnAround\n");
    for (int i = 0; i < myProc.size(); ++i) {
        printf(" %d  |     %d	 |   %d    |     %d     \n", i + 1, myProc[i].completionTime, myProc[i].waitingTime, myProc[i].turnAroundTime);
    }
    cout << "Avarage Waiting	   = " << getAvgWait() << endl;
    cout << "Avarage TunringAround = " << getAvgTurnAround() << endl;
    cout << "Avarage Response	   = " << getAvgResponse() << endl << endl;
}

MLQ::~MLQ()
{
}