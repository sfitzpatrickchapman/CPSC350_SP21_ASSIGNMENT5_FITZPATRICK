#include "RegistrarOffice.h"

RegistrarOffice::RegistrarOffice(list<int> input) {
	//read and initialize first line (window amt)
	studentLine = new Queue();
	windowsAmt = input.front(); input.pop_front();

	//stat vars
	timeMinutes = 0;
	totalWaitTime = 0;
	longestWaitTime = 0;
	numStudentsOverTen = 0;
	totalWindowIdleTime = 0;
	longestWindowIdleTime = 0;
	numWindowsIdleOverFive = 0;

	//windows = malloc(sizeof(Window) * openWindows);
	//windows = new int[windowsAmt];
	windows = new Window[windowsAmt];

}

RegistrarOffice::~RegistrarOffice() {
	delete windows;
} //delete queue?

void RegistrarOffice::iterate(list<int> input) {
	list<int> timeIncrements;
	list<int> studentAmounts;


	/* Get data from input list, put it where it belongs */
	while (input.size() != 0) {
		//read time and student amount from input
		int currTime = input.front(); input.pop_front();
		timeIncrements.push_back(currTime);

		int studentAmt = input.front(); input.pop_front();
		studentAmounts.push_back(studentAmt);

		//add reqTimes for each of students at that time
		for (int i = 0; i < studentAmt; i++) {
			int neededTime = input.front(); input.pop_front();
			studentLine->enqueue(neededTime);
		}
	}

	while (studentLine != 0) {
		if (timeIncrements.front() == timeMinutes) {
			//stat variable adjustments
			totalStudents += studentAmounts.front(); //add to total students
			if (studentAmounts.front() > longestWaitTime)
				longestWaitTime = studentAmounts.front();
			if (studentAmounts.front() > 10)
				numStudentsOverTen++;

			for (int i = 0; i < studentAmounts.front(); i++) {
				for (int j = 0; j < windowsAmt; j++) {
					if (windows[j].timeLeft == 0) { //empty window
						windows[j].timeLeft = studentLine->dequeue();

						//stats
						totalWaitTime += windows[j].timeLeft; //add to all waiting time
						if (windows[j].timeLeft > longestWindowIdleTime)
							longestWindowIdleTime = windows[j].timeLeft;
						if (windows[j].idleTime > 5)
							numWindowsIdleOverFive++;

						break; //from just the j loop
					}
				}
			}

			timeIncrements.pop_front();
			studentAmounts.pop_front();
		}

		//decrement windows' time left
		for (int i = 0; i < windowsAmt; i++)
			windows[i].timeLeft--;

		timeMinutes++;
	}
}

void RegistrarOffice::calcStats() {
	//other counter stats already calculated in iterate func
	meanWaitTime = totalWaitTime / totalStudents;
	//medianWaitTime = ?
	meanWindowIdleTime = totalWindowIdleTime / timeMinutes; //TODO: find where to increment idle time
}
