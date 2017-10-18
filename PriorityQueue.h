#pragma once

#include "node.h"

class PriorityQueue
{
        node *root;
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