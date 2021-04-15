#include "Queue.h"

Queue::Queue() {
    queueSize = 0;
    front = 0;
    back = 0;
}

Queue::~Queue() {
    Node* curr = front;

    //Loop through queue and delete each node
    while (curr != 0) {
        Node* frontPrev = curr->prev;
        delete curr;
        curr = frontPrev;
    }
}

void Queue::enqueue(int nTime, int timeAdded) {
    Node* newNode = new Node(nTime, timeAdded);

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

        int frontData = front->timeNeeded; //save fdata to return
        Node* frontPrev = front->prev; //save fprev to set as new f
        delete front; //fully delete front node
        front = frontPrev; //set new front to saved fprev value
        queueSize--; //decrement queue size

      return frontData;
    }
    catch (int x) {
        cout << "ERROR #" << x << ": Cannot dequeue from empty queue." << endl << endl;
        exit(x);
    }
}

int Queue::peek() {
    return front->timeNeeded;
}
