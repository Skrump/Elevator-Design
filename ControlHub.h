/*
 * ControlHub.h
 *
 *  Created on: Oct 19, 2017
 */

#ifndef CONTROLHUB_H_
#define CONTROLHUB_H_

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <ctime>
#include "PriorityQueue.h"
#include "Elevator.h"
#include "Floor.h"

using namespace std;

class ControlHub {

	int numFloors;
	int elevators;
	bool *locked;
	PriorityQueue myQueue;
	vector<Elevator> myElevator;
	Floor *myFloorArr;
	vector<int> topFloors;
	vector<int> inputs;
	vector<int> fileVec;
	void sortVec();
	void sortVec(vector<int>& vec);
	void getFromFile();
	void writeToFile(int num);
	void swapVal(int f, int s);
	void updateVectors(vector<int> &v1, vector<int> &v2, vector<int> &v3, vector<int> &v4);

public:

	ControlHub();
	ControlHub(int a);
	ControlHub(int a, int f);
	ControlHub(int a, int f, vector<Elevator> ele);
	~ControlHub();
	void runMe();
	void findMostReqFloor();
	void addMostReqFloor(int num);
	bool getStatus(int b);
	void printDisplay();
	void moveThrough(Elevator ele, PriorityQueue& queue);
	void moveThrough(Elevator ele, PriorityQueue& queue, vector<int> vec);
};



#endif /* CONTROLHUB_H_ */
