#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>
using namespace std;

class Queue {
public:
    /* Constructor & destructor */
    Queue();
    ~Queue();

    /* Core functions */
    void enqueue(int nTime, int timeAdded);
    int dequeue();

    /* Aux functions */
    int peek();

    /* Variables and pointers */
    Node* front;
    Node* back;
    size_t queueSize;
};

#endif
