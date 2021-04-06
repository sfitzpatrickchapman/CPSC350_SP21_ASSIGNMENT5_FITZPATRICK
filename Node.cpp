#include "Node.h"

Node::Node() {}

Node::Node(int nTime) {
	timeNeeded = nTime;
	next = 0;
	prev = 0;
}

Node::~Node() {
	timeNeeded = 0;
	next = 0;
	prev = 0;
} //TODO: what goes in here?
