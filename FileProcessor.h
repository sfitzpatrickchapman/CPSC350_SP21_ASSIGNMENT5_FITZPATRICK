#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <fstream>
#include <string>
#include <list>
#include <iostream>
using namespace std;

class FileProcessor {
public:
	FileProcessor();
	~FileProcessor();
	list<int> processFile(string inputFile);
};

#endif