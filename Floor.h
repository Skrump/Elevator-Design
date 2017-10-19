#pragma once

class Floor(int numReq, int priority)
{
  public:
    void getReq();
    void addReq(int num);
    void changePriority();
    int getPriority();
};
