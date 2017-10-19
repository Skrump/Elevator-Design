/*
Priority queue header file: This priority queue will be the primary data structure
for the elevator class.
*/

#pragma once

#include <cstddef>
#include "node.h"

class PriorityQueue
{
        node *root;
        node *currPtr;
        node temp1;
        node temp2;
        void linkedList();
    public:
        PriorityQueue();
        ~PriorityQueue();
        bool empty();
        int size();
        node front();
        void enqueue();
        void dequeue();
        void deleteEnd();
};