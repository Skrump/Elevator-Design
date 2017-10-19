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
	int mostReqFloor;
	bool status;
	Floor numFloors; //wip
public:
	Elevator();
	Elevator(string a, double max, double curr, int most, bool stat);
	string getName();
	void changeName(string a);
	double getCurrWeight();
	void addCurrWeight(double num);
	double getMaxWeight();
	void addMaxWeight(double num);
	int getMostReqFloor();
	void addMostReqFloor(int num);
	void printDisplay();
	bool goUp();
	bool goDown();
	bool openDoors();
	bool closeDoors();
	void updateStatus();
	int emergencyState();
	void grantPriority();
};
