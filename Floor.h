#pragma once

#include <iostream>
using namespace std;

class Floor
{
private:
	int requests;
	int priority;
	int number;
	bool pending;
public:
	Floor();
	Floor(int numReq, int prior, bool pend, int num);
	int getReq();
	void addReq(int num);
	int getPriority();
	void changePriority(int num);
	bool request();
	bool reached();
	int getFloor();
	void changeFloor(int num);
	int getStatus();
};
