#include "defs.h"
#include "nonPreSJF.h"
#include "PreSJF.h"
#include "FCFS.h"
#include "RR.h"
#include "MLQ.h"

int main() {
	//vector<preProc> list = { 
	////arrival,burst,pr
	//	{2,6,0},
	//	{5,2,0},
	//	{1,8,0},
	//	{0,3,0},
	//	{4,4,0}
	//};
	
	//vector<preProc> list = {
	//	//arrival,burst,pr
	//		{0,5},
	//		{1,6},
	//		{2,3},
	//		{3,1},
	//		{4,5},
	//		{6,4}
	//};
	
	//vector<preProc> list = {
	//	//arrival,burst,pr
	//		{0,5},
	//		{1,4},
	//		{2,2},
	//		{3,1}
	//};
	//vector<preProc> list = {
	//	//arrival,burst,pr
	//		{0,4},
	//		{1,5},
	//		{2,2},
	//		{3,1},
	//		{4,6},
	//		{6,3}
	//};

	//vector<preProc> list = {
	//	//time,burst,pr
	//	{0,4,1},
	//	{0,3,1},
	//	{0,8,2},
	//	{10,5,1}
	//};
	//nonPreSJF nonPresjf(list);
	//nonPresjf.scheduler();

	vector<preProc> list;
	for (int i = 0; i < 2000; i++) {
		list.push_back({ rand() % 120, rand() % 30+1, rand() %3 });
	}
	
	//cout << "MLQ: \n";
	//MLQ mlq(list);
	//mlq.scheduler();

	cout << "nonPreemtive: \n";
	nonPreSJF nonPresjf(list);
	nonPresjf.scheduler();
	
	cout << "Preemtive: \n";
	PreSJF Presjf(list);
	Presjf.scheduler();
	
	cout << "FCFS: \n";
	FCFS fcfs(list);
	fcfs.scheduler();
	
	cout << "RR: \n";
	RR rr(list);
	rr.scheduler();


	system("pause");
	return 0;
}