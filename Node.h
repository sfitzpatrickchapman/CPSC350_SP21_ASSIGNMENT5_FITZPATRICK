#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
public:
    Node();
    Node(int nTime, int timeA);
    ~Node();

    int timeNeeded;
    int timeAdded;
    Node* next;
    Node* prev;
};

#endif
