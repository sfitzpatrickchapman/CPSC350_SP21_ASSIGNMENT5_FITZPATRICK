#ifndef REGISTRAROFFICE_H
#define REGISTRAROFFICE_H

#include "Second.h"
#include "Window.h"
#include "Node.h"
#include "Queue.h"
#include <list>
#include <iostream>
using namespace std;

class RegistrarOffice {
public:
	RegistrarOffice(list<int> input);
	~RegistrarOffice();
	void iterate();

	Queue* studentLine;
	Window window;
};

#endif