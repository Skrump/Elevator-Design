/*
Priority queue header file: This priority queue will be the primary data structure
for the elevator class.
*/

#pragma once

#include <cstddef>
#include "node.h"
#include "Floor.h"

class PriorityQueue
{
        node *head;
        node *tail;
        node *currPtr;
        node *secPtr;
    public:
        PriorityQueue();
        ~PriorityQueue();
        bool isEmpty();
        int size();
        Floor front(); 
        Floor rear(); 
        void enqueue(Floor f);
        void dequeue();
};