#include "defs.h"
#include "nonPreSJF.h"
#include "PreSJF.h"
#include "FCFS.h"
#include "RR.h"

int main() {
	//vector<preProc> list = { 
	////arrival,burst,pr
	//	{2,6},
	//	{5,2},
	//	{1,8},
	//	{0,3},
	//	{4,4}
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
	
	vector<preProc> list = {
		//arrival,burst,pr
			{0,5},
			{1,4},
			{2,2},
			{3,1}
	};
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
	//	//pid,time,burst,pr
	//		{5,8},
	//		{0,5},
	//		{4,9},
	//		{1,2}	
	//};
	//nonPreSJF nonPresjf(list);
	//nonPresjf.scheduler();

	//vector<preProc> list;

	//for (int i = 0; i < 100; i++) {
	//	list.push_back({ rand() % 120, rand() % 30+1 });
	//}
	//
	//cout << "nonPreemtive: \n";
	//nonPreSJF nonPresjf(list);
	//nonPresjf.scheduler();

	//cout << "Preemtive: \n";
	//PreSJF Presjf(list);
	//Presjf.scheduler();

	//cout << "FCFS: \n";
	//FCFS fcfs(list);
	//fcfs.scheduler();

	cout << "RR: \n";
	RR rr(list);
	rr.scheduler();
	system("pause");
	return 0;
}