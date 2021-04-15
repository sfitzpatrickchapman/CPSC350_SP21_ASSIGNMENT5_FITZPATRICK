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
    void iterate(); //run simulation
    void calcStats(); //calculate complex stats
    void printAuxStats();
    void printStats();

private:
    list<int> preppedInput; //input - window amt
    list<int> studentNTimes; //for finding median
    Queue* studentLine;
    Window* windows;
    int windowsAmt;
    int timeMinutes;

    //nums for stat calcs
    int timeElapsed;
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
