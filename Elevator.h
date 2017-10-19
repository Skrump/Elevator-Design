#pragma once

class Elevator
{
  public: 
    Elevator(double maxWeight, double currWeight, int mostReqFloor, bool status);
    void addFloor();
    void addMax();
    void addWeight(int w);
    double getWeight();
    void printDisplay();
    bool goDown();
    bool goUp();
    bool openDoors();
    bool closeDoors();
    void updateStatus();
    void addMost();
    int getMost();
    bool updateCurr();
    int getCurr();
    int emergencyState();
    void grantPriority();
};
