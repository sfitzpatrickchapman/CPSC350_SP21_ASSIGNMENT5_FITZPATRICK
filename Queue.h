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
	void queue(int nTime);
	int dequeue();

	/* Variables and pointers */
	Node* front;
	Node* back;
	size_t queueSize;
};

#endif