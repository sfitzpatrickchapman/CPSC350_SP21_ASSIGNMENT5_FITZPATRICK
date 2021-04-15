#include "RegistrarOffice.h"

RegistrarOffice::RegistrarOffice(list<int> input) {
    studentLine = new Queue();
    windowsAmt = input.front(); input.pop_front();
    preppedInput = input;
    windows = new Window[windowsAmt];

    //stat vars
    timeMinutes = 0;
    timeElapsed = 0;
    totalWaitTime = 0;
    totalStudents = 0;
    longestWaitTime = 0;
    numStudentsOverTen = 0;
    totalWindowIdleTime = 0;
    longestWindowIdleTime = 0;
    numWindowsIdleOverFive = 0;
}

RegistrarOffice::~RegistrarOffice() {
    delete studentLine;
    delete []windows;
}

void RegistrarOffice::iterate() {
    bool allWindowsVacant = true;
    int studentsForCurrTime = 99999999;

    /* Run the simulation */
    while (true) {
        // ADD TO THE STUDENT LINE (QUEUE)
        if (timeMinutes == preppedInput.front()) { //if time has new students
            preppedInput.pop_front();

            //make variable that defines the amount of new students for this time
            studentsForCurrTime = preppedInput.front();
            preppedInput.pop_front();

            //add the new students from the list to the queue
            for (int i = 0; i < studentsForCurrTime; i++) {
                studentLine->enqueue(preppedInput.front(), timeMinutes);
                preppedInput.pop_front();
                totalStudents++; //STAT: total amount of students
            }
        }

        // PUT STUDENTS FROM LINE INTO VACANT WINDOWS
        if (studentLine->queueSize > 0) {
            for (int i = 0; i < windowsAmt; i++) {
                if (windows[i].timeLeft <= 0 && studentLine->queueSize > 0) {
                    int stdtWaitTime = timeMinutes - studentLine->front->timeAdded;

                    //STATS: median swt, longest swt, and swt over 10
                    studentNTimes.push_front(stdtWaitTime); //find median latr

                    if (stdtWaitTime > longestWaitTime)
                        longestWaitTime = stdtWaitTime; //STAT
                    if (stdtWaitTime > 10)
                        numStudentsOverTen++; //STAT

                    //occupy the window and update its vars
                    windows[i].timeLeft = studentLine->dequeue();
                    windows[i].atIdle = false;
                    windows[i].idleTime = 0;
                }
            }
        }


        //decrement windows time left
        for (int i = 0; i < windowsAmt; i++) {
            windows[i].timeLeft--; //decrement windows' time left
        }

        //increment time
        timeMinutes++;

        //STAT updates
        totalWaitTime += studentLine->queueSize;

        //check if all windows are vacant and update stats
        allWindowsVacant = true;
        for (int i = 0; i < windowsAmt; i++) {
            if (windows[i].timeLeft > 0) { //if a window isn't vacant
                allWindowsVacant = false;
                windows[i].atIdle = false;
            }
            else { //window vacant
                totalWindowIdleTime++; //STAT

                windows[i].atIdle = true; //set atIdle status to true
                windows[i].idleTime++;

                //STAT: longest window idle time
                if (windows[i].idleTime > longestWindowIdleTime)
                    longestWindowIdleTime = windows[i].idleTime;

                //STAT: amount of windows that idled over 5
                if (windows[i].idleTime > 5)
                    windows[i].idledOverFive = true;
            }
        }


        //BREAK IF ALL WINDOWS VACANT, NO MORE STUDENTS IN LINE, & ENOUGH TIME HAS PASSED
        if (allWindowsVacant && studentLine->queueSize == 0 && timeMinutes > studentsForCurrTime)
            break;
    }
}

void RegistrarOffice::calcStats() { //other counter stats already calculated in iterate func
    meanWaitTime = (float)totalWaitTime / (float)totalStudents;

    //calculate median student wait time
    auto itr = studentNTimes.begin();

    if (studentNTimes.size() % 2 == 0) { //if even
        for (int i = 0; i < studentNTimes.size() / 2; i++)
            itr++;

        medianWaitTime = ((double) * itr + *--itr) / 2;
    }
    else { //if odd
        for (int i = 0; i < studentNTimes.size() / 2; i++)
            itr++;

        medianWaitTime = *itr;
    }

    //calculate amount of windows that idled over five
    for (int i = 0; i < windowsAmt; i++) {
        if (windows[i].idledOverFive)
            numWindowsIdleOverFive++;
    }

    //calculate meanWindowIdleTime
    meanWindowIdleTime = (float)totalWindowIdleTime / (float)windowsAmt;
}

void RegistrarOffice::printStats() {
    cout << "\n<--------------------<STATS>-------------------->" << endl;
    cout << "  Mean Student Wait Time             "; printf("%.2f", meanWaitTime); cout << " mins" << endl;
    cout << "  Median Student Wait Time           "; printf("%.2f", medianWaitTime); cout << " mins" << endl;
    cout << "  Longest Student Wait Time          " << longestWaitTime << " mins" << endl;
    cout << "  Student Wait Times Over Ten        " << numStudentsOverTen << " stdts" << endl;
    cout << endl;
    cout << "  Mean Window Idle Time              "; printf("%.2f", meanWindowIdleTime); cout << " mins" << endl;
    cout << "  Longest Window Idle Time           " << longestWindowIdleTime << " mins" << endl;
    cout << "  Windows That Idled Over Five       " << numWindowsIdleOverFive << " windows" << endl;
    cout << "<----------------------------------------------->" <<  endl;
    cout << endl;
}

void RegistrarOffice::printAuxStats() {
    cout << "\n<--------------<AUX STATS>-------------->" << endl;
    cout << "  Time Elapsed                  " << timeMinutes << " mins" << endl;
    cout << "  Total Student Wait Time       " << totalWaitTime << " mins" << endl;
    cout << "  Total Amount of Students      " << totalStudents << " stdts" << endl;
    cout << "  Total Window Idle Time        " << totalWindowIdleTime << " mins" << endl;
    cout << "<--------------------------------------->" <<  endl;
    cout << endl;
}
