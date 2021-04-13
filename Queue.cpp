#include "Queue.h"

Queue::Queue() {
	queueSize = 0;
	front = 0;
	back = 0;
}

Queue::~Queue() {
    //TODO: adapt for int queue
    //StackNode<T>* curr = top;

    ///* Loop through stack and delete each node */
    //while (curr != 0) {
    //    StackNode<T>* temp = curr->next; //remember next top
    //    delete curr; //delete current top
    //    curr = temp; //recall top's next to set as new top
    //}
}

void Queue::enqueue(int nTime) {
	Node* newNode = new Node(nTime);

	newNode->next = back;

	if (queueSize == 0) {
		front = newNode;
		back = newNode;
	}
	else {
		back->prev = newNode;
		back = newNode;
	}
	queueSize++;
}

int Queue::dequeue() {
	try {
		if (queueSize == 0)
			throw 1;

		int temp = front->timeNeeded;
		front = front->prev;
		queueSize--;

	  return temp;
	}
	catch (int x) {
		cout << "ERROR #" << x << ": Cannot dequeue from empty queue." << endl << endl;
	}
}

void Queue::printQueue() {
	cout << "umm maybe finish this" << endl;
}
