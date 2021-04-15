#include "Node.h"

Node::Node() {}

Node::Node(int nTime, int timeA) {
    timeNeeded = nTime;
    timeAdded = timeA;
    next = 0;
    prev = 0;
}

Node::~Node() {}
