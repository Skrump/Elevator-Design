/*
node struct to be used to build priority queue structure
*/
#pragma once
#include "Floor.h"


struct node
{
    Floor data;
    node *next;
};
