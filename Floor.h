#pragma once

#include <iostream>
using namespace std;

class floor
{
public:
	floor();
	floor(int numReq, int prior);
	int getReq();
	void addReq(int num);
	int getPriority();
	void changePriority(int num);
private:
	int requests;
	int priority;
};
