#pragma once

#include <iostream>
#include <string>
#include "Floor.h"
using namespace std;

class Elevator
{
private:
	string name;
	double currWeight;
	double maxWeight;
	bool status;
	double time; //up/down/open/close
	bool _doorOpen; //open/close
	Floor numFloors; //wip
public:
	Elevator();
	Elevator(string a, double max, double curr, int most, bool stat, double time, bool door);
	string getName();
	void changeName(string a);
	double getCurrWeight();
	void addCurrWeight(double num);
	double getMaxWeight();
	void addMaxWeight(double num);
	double getTime();
	void changeTime(double t);
	bool goUp();
	bool goDown();
	bool openDoors();
	bool closeDoors();
	void updateStatus();
};
