#ifndef DEFS
#define DEFS

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip> 
using namespace std;

struct preProc
{
    int arrivalTime;    // when process arrives at the queue
    int cpuBurst;             //cpu cyles
    int priority;
};

struct process
{
    //given
    //int pid;
    int arrivalTime;    // when process arrives at the queue
    int cpuBurst;             //cpu cyles
    int priority;

    //to be calculated:
    int startTime;      // whSen process starts execution 
    int completionTime; // whenn process finishes execution
    int remainingTime;  
    int turnAroundTime; //completionTime - arrivalTime
    int responseTime;   // startTime - arrivalTime 
    int waitingTime;    // turnAroundTime - cpuBurst 
    double queueTime; 
};

#endif
//void nonPreSJF(vector<process> list);