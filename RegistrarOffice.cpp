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

	while (studentLine != 0) { //should loop until queue empty
		if (timeIncrements.front() == timeMinutes) { //if came during at the time
			//stat variable adjustments
			totalStudents += studentAmounts.front(); //add to total students
			if (studentAmounts.front() > longestWaitTime)
				longestWaitTime = studentAmounts.front(); //update longestWaitTime
			if (studentAmounts.front() > 10)
				numStudentsOverTen++; //update/increment numStudentsOverTen

			/* For each student (i loop), iterate through all of the windows to see
			if they are vacant (j loop). If so, dequeue the value into that window */
			for (int i = 0; i < studentAmounts.front(); i++) {
				for (int j = 0; j < windowsAmt; j++) {
					if (windows[j].timeLeft == 0) { //if there is an empty window
						if (studentLine->queueSize != 0) { //and if queue isn't empty
							windows[j].timeLeft = studentLine->dequeue(); //TODO: sus
							windows[j].atIdle = false;

							//stat updates
							totalWaitTime += windows[j].timeLeft; //add to all waiting time
							if (windows[j].timeLeft > longestWindowIdleTime)
								longestWindowIdleTime = windows[j].timeLeft;
						}
						else { //queue empty
							windows[j].atIdle = true;
						}



						//stat udates
						if (windows[j].idleTime > 5)
							numWindowsIdleOverFive++;
					}

					//if window j at idle, increment idle time
					if (windows[j].atIdle)
						windows[j].idleTime++;

					//update longest idle time stat if needed
					if (windows[j].idleTime > longestWindowIdleTime)
						longestWindowIdleTime = windows[j].idleTime;

					break; //from just j loop; prevent multiple students to one window
				}
			}

			timeIncrements.pop_front();
			studentAmounts.pop_front();
		}

		//update all windows
		for (int i = 0; i < windowsAmt; i++) {
			windows[i].timeLeft--; //decrement windows' time left
		}

		timeMinutes++;
	}
}

void RegistrarOffice::calcStats() {
	//other counter stats already calculated in iterate func
	meanWaitTime = totalWaitTime / totalStudents;
	//medianWaitTime = ?

	//calculate meanWindowIdleTime
	for (int i = 0; i < windowsAmt; i++) //calculate totalWindowIdleTime first
		totalWindowIdleTime += windows[i].idleTime;
	meanWindowIdleTime = totalWindowIdleTime / timeMinutes;
}
