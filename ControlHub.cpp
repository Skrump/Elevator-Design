/*
 * ControlHub.cpp
 *
 *  Created on: Oct 19, 2017
 *      Author: daneg_000
 */

#include "ControlHub.h"

ControlHub::ControlHub() {

	numFloors = 2;
	elevators = 0;
	topFloors = new int [numFloors];
	topFloors[0] = 0; 
	topFloors[1] = 0;
	locked = new bool[numFloors];
	locked[1] = false;
	myFloorArr = new Floor [numFloors];
}

ControlHub::ControlHub(int a) {
	numFloors = 2;
	elevators = a;
	topFloors = new int[1];
	topFloors[0] = 0;
	topFloors[1] = 0;
	locked = new bool [numFloors];
	locked[1] = false;
	myFloorArr = new Floor [numFloors];
}

ControlHub::ControlHub(int a, int f)
{
	numFloors = f; 
	elevators = a;
	topFloors = new int[f];
	topFloors[0] = 0;
	locked = new bool [f];
	locked[1] = false;
	myFloorArr = new Floor [numFloors];
}

ControlHub::~ControlHub()
{
	delete [] myFloorArr;
	delete [] locked;
}

void ControlHub::runMe()
{
	
}

int ControlHub::getMostReqFloor()
{

	int d;

	//run priority algorithm

	return d;
}

void ControlHub::addMostReqFloor(int num)
{

	//move floors down the array, then replace top spot

	topFloors[0] = num;
}

bool ControlHub::getStatus(int b) {

	return locked[b];
}

void ControlHub::printDisplay()
{
	//display elevator status
	/*	PLEASE EXPLAIN WHAT YOU'RE TRYING TO DO HERE
	if(myFloorArr.numFloors() == false) 
	{
		cout << "Elevator status: Online" << endl << endl;
	}
	else 
	{
		cout << "Elevator status: Offline" << endl << endl;
	} 
	*/
	//display priority floors
	cout << "Floors " << topFloors[0] << ", " << topFloors[1] << ", & " << topFloors[2] << " have priority." << endl; 
}
