#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
public:
	Node();
	Node(int nTime);
	~Node();

	int timeNeeded;
	Node* next;
	Node* prev;
};

#endif