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

void Queue::queue(int nTime) {

}

int Queue::dequeue() {
    return 0;
}