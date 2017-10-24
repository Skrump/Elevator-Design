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
#include <vector>
#include "Elevator.h"
#include "Floor.h"
#include "PriorityQueue.h"
#include "node.h"
#include "ControlHub.h"

using namespace std;

const int NUMFLOORS = 5;

int main()
{
	Elevator myElevator("Elevator 1", 0.0, 2500.0, 0, 1, false);
	ControlHub myHub(0, NUMFLOORS);
	vector<int> inputs;
	inputs.resize(NUMFLOORS);
	int g = 0; //f is an input stream, g is a counter for the queue (For demo purposes only!)
	bool loopMe = true;
    char next;
    int i = 0 j = 0;

	cout << "Please enter the number of the floor(s) you would like to go to: ";


	do{ //For demo purposes only!

	    cin >> next;
	
	    while(next != '\n')
	    {
	        if ((i % 2) == 0)
	        {
	            inputs[j] = next;
	            j++;
	        }
	        i++;
	        cin.get(next);
	    }
	    cout << endl;

		//need an exit clause
		loopMe = false;

	}while (loopMe);

	/* Depending on our overall code progress, we either:
	 *
	 * 1. Run the NORMAL queue (enqueue and dequeue without implementing priority), OR ...
	 * 2. Run the PRIORITY queue (enqueue, run the priority algorithm, reorder based on priority results, and THEN dequeue).
	 *
	 *  We MUST be able to implement the first option for the sake of the demo, which will focus on our queue working.
	 */

    return 0;
}
