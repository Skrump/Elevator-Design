#pragma once

class Floor
{
  public:
    Floor(int numReq, int priority);
    void getReq();
    void addReq(int num);
    void changePriority();
    int getPriority();
};
