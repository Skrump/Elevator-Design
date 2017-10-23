/****************************************************************
 * Authors: Alejandro Lopez, Pierce Tu, Dane Godard, Kenneth Paw
 * Elevator Design Project
 * Course Project for Software Engineering 1 (CMPE 131)
 * Professor: Dr. Hungwen Li
 * Last Modified: 10/13/2017
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

int main()
{
    Floor myFloor;
    PriorityQueue myQueue;
    myQueue.enqueue(myFloor);
    cout << "Size: " << myQueue.size() << endl;
    return 0;
}
