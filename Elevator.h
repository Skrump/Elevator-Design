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
	int currFloor; 
	Floor numFloors; //wip
	
public:
	Elevator();
	Elevator(const char a[11], double max, double curr, int most, bool stat, bool door);
	Elevator(string a, double max, double curr, int most, bool stat, double time, bool door);
	string getName();
	void changeName(string a);
	double getCurrWeight();
	void addCurrWeight(double num);
	double getMaxWeight();
	void addMaxWeight(double num);
	int getCurrFloor();
	double getTime();
	void changeTime(double t);
	void goUp(int f);
	void goDown(int g);
	bool openDoors();
	bool closeDoors();
	void updateStatus();
};