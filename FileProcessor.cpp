#include "FileProcessor.h"

FileProcessor::FileProcessor() {}

FileProcessor::~FileProcessor() {}

list<int> FileProcessor::processFile(string inputFile) {
	list<int> inputList;
	string textHolder; //stack pushes chars from here
	fstream readFile;

	readFile.open(inputFile, ios::in);

	if (readFile.is_open()) {
		while (getline(readFile, textHolder)) {
			inputList.push_back(stoi(textHolder));
		}
		readFile.close();
		return inputList;
	}
	else { //invalid file handling
		cout << "ERROR #3: Invalid input. The file may spelled ";
		cout << "improperly or without \".txt\"." << endl << endl;
		readFile.close();
		exit(3);
	}
}
