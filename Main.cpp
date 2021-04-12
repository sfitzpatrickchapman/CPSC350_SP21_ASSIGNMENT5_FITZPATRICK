#include "Node.h"
#include "Queue.h"
#include "FileProcessor.h"
#include "RegistrarOffice.h"
#include <list>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	cout << "Running..." << endl;

	FileProcessor fproc;
	list<int> input = fproc.processFile("test.in.txt");

	RegistrarOffice* chapman = new RegistrarOffice(input);

	// Queue* testQueue = new Queue();
	// testQueue->enqueue(5);
	// testQueue->enqueue(4);
	// testQueue->enqueue(3);
	//
	// cout <<  testQueue->dequeue() << endl;
	// cout <<  testQueue->dequeue() << endl;
	// cout <<  testQueue->dequeue() << endl;
	//
	// testQueue->printQueue();


	delete chapman; // D:
	cout << "Done." << endl;
}
