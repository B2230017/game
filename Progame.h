#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
using namespace std;
class Program {
private:
	int guest[4];
	int owner[4];
public:
	Program(int);
	void setnumber(int);
	void printjudge();
};

#endif
