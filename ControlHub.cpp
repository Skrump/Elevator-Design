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
	locked = new bool[numFloors];
	locked[1] = false;
	myFloorArr = new Floor [numFloors];
	topFloors.resize(floor(numFloors/3));
	inputs.resize(0);
	fileVec.resize(numFloors + 1);
}

ControlHub::ControlHub(int a) {

	numFloors = 2;
	elevators = a;
	locked = new bool [numFloors];
	locked[1] = false;
	myFloorArr = new Floor [numFloors];
	topFloors.resize(floor(numFloors/3));
	inputs.resize(0);
	fileVec.resize(numFloors + 1);
}

ControlHub::ControlHub(int a, int f)
{

	numFloors = f; 
	elevators = a;
	locked = new bool [f];
	locked[1] = false;
	myFloorArr = new Floor [numFloors];
	topFloors.resize(floor(numFloors/3));
	inputs.resize(0);
	fileVec.resize(numFloors + 1);
	for(int i=0; i<f; i++) //sets Floor number info
	{
		myFloorArr[i].changeFloor(i+1);
	}
	for(int j=0; j<f; j++)//checks to see if it is named correctly.
	{
		cout << "Floor " << myFloorArr[j].getFloor() << endl;
	}
}

ControlHub::ControlHub(int a, int f, Elevator ele)
{

	numFloors = f;
	elevators = a;
	locked = new bool [f];
	locked[1] = false;
	myFloorArr = new Floor [numFloors];
	topFloors.resize(floor(numFloors/3));
	inputs.resize(0);
	fileVec.resize(numFloors + 1);
	for(int i=0; i<f; i++) //sets Floor number info
	{
		myFloorArr[i].changeFloor(i+1);
	}
	for(int j=0; j<f; j++)//checks to see if it is named correctly.
	{
		cout << "Floor " << myFloorArr[j].getFloor() << endl;
	}
	myElevator = ele;
}

ControlHub::~ControlHub()
{
	delete [] myFloorArr;
	delete [] locked;
}

void ControlHub::runMe()
{
	bool loopMe = true;
    char next;
    int inp;
    int i = 0;
	int j = 0;
    int n = 1;

	cout << "Please enter the number of the floor(s) you would like to go to: ";
		
	do{
		if (cin >> inp)
			inputs.push_back(inp);
	}while(cin && cin.peek() != '\n');

    cout << endl;

	getFromFile();

    sortVec(); //sorts vector
	for (int x = 0; x<inputs.size(); x++)//queues inputs from vector
	{
		myQueue.enqueue(inputs[x]);
		fileVec[inputs[x]]++;	//update file vector (adds a point to a requested floor)
	}
	writeToFile(1);
	getFromFile();
	
	moveThrough();//elevator begins moving through input queue.
	myQueue.display();
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
//	cout << "Floors " << topFloors[0] << ", " << topFloors[1] << ", & " << topFloors[2] << " have priority." << endl; 
}
void ControlHub::moveThrough()
{
	node *temp = new node;
	node *tempNext = new node;
	temp = myQueue.getHead();
	tempNext = temp;

	int weight = 0;
	int i = 0;

	while (temp != NULL)
	{
		cout << "Elevator arrived at Floor " << temp->data << endl;
		myElevator.openDoors();

		if(i == 0) //assumes this is an empty elevator.
		{
			cout << "Passenger(s) boarded." << endl;
			cout << "Please enter passenger(s)'s weight." << endl;
			cin >> weight;
			weight = myElevator.getCurrWeight() + weight;
			myElevator.addCurrWeight(weight);
			myElevator.updateStatus();
		}

		myElevator.closeDoors();
		temp = temp->next;

		if(temp == NULL)
		{
			break;
		}
		else if(tempNext->data < temp->data) //checks if elevator is going up
		{
			myElevator.goUp(temp->data);
			myFloorArr[temp->data].addReq();
		}
		else if(tempNext->data > temp->data)//checks if elevator is going down.
		{
			myElevator.goDown(temp->data);
			myFloorArr[temp->data].addReq();
		}
		tempNext = tempNext->next;
		myQueue.dequeue();
		i++;
	}
	myQueue.dequeue();
}

void ControlHub::sortVec()
{
	int temp, sortVal=0;
	do{
		for (int i = 0; i < inputs.size() - 1; i++)
		{
			if (inputs[i] > inputs[i+1])
			{
				temp = inputs[i];
				inputs[i] = inputs[i+1];
				inputs[i+1] = temp;
			}
		}
		sortVal++;
	}while (sortVal < 6);
}

void ControlHub::getFromFile()	//gets information from data file and inserts them into a vector
{
	ifstream fin;
	fin.open("data.dat");
	if (fin.fail())
	{
		cout << "\nError 404: File not found. . . Creating a new File\n\n";
		writeToFile(0);
		fin.open("data.dat");
		if (fin.fail())
		{
			cout << "Error: File failed to open\n";
			exit(1);
		}
	}
	
	int next, i =0;
	
	fin >> next;
	
	if (next != numFloors)
	{
		cout << "\nError 405: The number of floors has changed . . . Creating a new File\n\n";
		fin.close();
		writeToFile(0);
		fin.open("data.dat");
		if (fin.fail())
		{
			cout << "Error: File failed to open\n";
			exit(1);
		}
		fin >> next;
	}
	while (!fin.eof())
	{
		fileVec[i] = next;
		i++;
		fin >> next;
	}
	fin.close();
}

void ControlHub::writeToFile(int num)	//writes vector to the file
{
	ofstream fout;
	fout.open("data.dat");
	if (fout.fail())
	{
		cout << "Error: File failed to open\n";
		exit(1);
	}
	
	if (num == 0)
	{
		fout << numFloors << endl;
		for (int i = 0; i < numFloors; i++)
		{
			fout << 0 << endl;
		}
	}
	else if (num == 1)
	{
		for (int i = 0; i < fileVec.size(); i++)
		{
			fout << fileVec[i] << endl;
		}
	}
	
	fout.close();
}