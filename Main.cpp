#include "Node.h"
#include "Queue.h"
#include "FileProcessor.h"
#include "RegistrarOffice.h"
#include <list>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    FileProcessor fproc;
    list<int> input = fproc.processFile((string)argv[1]);

    RegistrarOffice* chapman = new RegistrarOffice(input);
    chapman->iterate();
    chapman->calcStats();
    //chapman->printAuxStats(); //un-comment to see core stats
    chapman->printStats();

    delete chapman; // D:
		return 0;
}
