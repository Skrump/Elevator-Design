/****************************************************************
 * Authors: Alejandro Lopez, Pierce Tu, Dane Godard, Kenneth Paw
 * Elevator Design Project
 * Course Project for Software Engineering 1 (CMPE 131)
 * Professor: Dr. Hungwen Li
 * Last Modified: 11/13/2017
 * Description: This program will improve upon basic elevator 
 * programs. It utilizes a priority queue to process the elevator
 * requests per floor.
 * Additional: Push to Github on cloud9 with the commands 
 * git add .
 * git commit -m "Enter comment here"
 * git push
 * 
 * To download from Git:
 * git pull origin master
 ***************************************************************/
 
#include <iostream>
#include "Elevator.h"
#include "Floor.h"
#include "PriorityQueue.h"
#include "node.h"
#include "ControlHub.h"

using namespace std;

const int NUMFLOORS = 10;	

int main()
{
	Elevator myElevator("Elevator 1", 2500.0, 0.0, 0, 1, 1, false);
	Elevator secElevator("Elevator 2", 2500.0, 0.0, 0, 1, 1, false);
	Elevator thirdElevator("Elevator 3", 2500.0, 0.0, 0, 1, 1, false);
	vector<Elevator> elevatorVec;
	elevatorVec.push_back(myElevator);
	elevatorVec.push_back(secElevator);
	elevatorVec.push_back(thirdElevator);

	ControlHub myHub(3, NUMFLOORS, elevatorVec);
	myHub.runMe();
	return 0;
}
