#include "RegistrarOffice.h"

RegistrarOffice::RegistrarOffice(list<int> input) {
	studentLine = new Queue();
	int openWindows = input.front(); input.pop_front();


	int time = input.front(); input.pop_front();
	int studentAmt = input.front(); input.pop_front();

	Second currSecond(time, studentAmt, input);


}