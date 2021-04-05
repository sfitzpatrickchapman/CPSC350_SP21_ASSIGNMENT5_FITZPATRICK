#include "Node.h"

Node::Node() {}

Node::Node(int nTime) {
	timeNeeded = nTime;
	next = 0;
	prev = 0;
}

Node::~Node() {} //TODO: what goes in here?