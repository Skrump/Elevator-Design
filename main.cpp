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
	Elevator myElevator("Elevator 1", 0.0, 2500.0, 0, 1, false);
	ControlHub myHub(0, 5);
	
	int f, g = 0; //f is an input stream, g is a counter for the queue (For demo purposes only!)
/*	WE DON'T NEED THIS
	Floor floor0(0, 0, 0, 0);	//individual floors ({total requests, priority, pending status, floor number}
	Floor floor1(0, 0, 0, 1);	//as per the "Floor.cpp" custom constructor) (For demo purposes only!)
	Floor floor2(0, 0, 0, 2);
	Floor floor3(0, 0, 0, 3);
	Floor floor4(0, 0, 0, 4);
	Floor floor5(0, 0, 0, 5);
*/

	cout << "<Enter floor requests>" << endl << "<Enter '-1' to stop>" << endl; //For demo purposes only!

	while(1) { //For demo purposes only!

		cin >> f;

		if (-1) { //user enters '-1'

			break;
		}

		else {

			if (g == 0) {

				PriorityQueue queue; //create the queue with it's first node "root" here
			}

			cout << f << endl; //For debugging user input (Need a check for "not an integer"?)
			g++;
		}
	}

	/* Depending on our overall code progress, we either:
	 *
	 * 1. Run the NORMAL queue (enqueue and dequeue without implementing priority), OR ...
	 * 2. Run the PRIORITY queue (enqueue, run the priority algorithm, reorder based on priority results, and THEN dequeue).
	 *
	 *  We MUST be able to implement the first option for the sake of the demo, which will focus on our queue working.
	 */

    return 0;
}
