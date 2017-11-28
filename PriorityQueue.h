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
        node *getHead();
        node *getTail();
        node *getCurrPtr();
        node *getSecPtr();
        bool isEmpty();
        int size();
        int front();
        int rear();
        void enqueue(int f);
        void dequeue();
        void emplace(int f);
        void display();
};
