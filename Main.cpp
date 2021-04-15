#include "Node.h"
#include "Queue.h"
#include "FileProcessor.h"
#include "RegistrarOffice.h"
#include <list>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    FileProcessor fproc;
    list<int> input = fproc.processFile("test.in.txt");

    RegistrarOffice* chapman = new RegistrarOffice(input);
    chapman->iterate();
    chapman->calcStats();
    chapman->printAuxStats();
    chapman->printStats();

    delete chapman; // D:
}
