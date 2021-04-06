#include "Node.h"
#include "Queue.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	cout << "Running..." << endl;
	Queue* testQueue = new Queue();
	testQueue->enqueue(5);
	testQueue->enqueue(4);
	testQueue->enqueue(3);

	cout <<  testQueue->dequeue() << endl;
	cout <<  testQueue->dequeue() << endl;
	cout <<  testQueue->dequeue() << endl;

	testQueue->printQueue();

	cout << "Done." << endl;
}
