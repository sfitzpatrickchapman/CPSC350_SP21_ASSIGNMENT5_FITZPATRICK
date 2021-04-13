#ifndef REGISTRAROFFICE_H
#define REGISTRAROFFICE_H

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
	void iterate(list<int> input);
	void calcStats();

private:
	Queue* studentLine;
	Window* windows;
	int windowsAmt;

	//nums for stat calcs
	int timeMinutes;
	int totalWaitTime;
	int totalStudents;
	int totalWindowIdleTime;

	//stat answers
	float meanWaitTime;
	float medianWaitTime;
	int longestWaitTime;
	int numStudentsOverTen;
	float meanWindowIdleTime;
	int longestWindowIdleTime;
	int numWindowsIdleOverFive;
};

#endif
