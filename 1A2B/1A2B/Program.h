#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include <cmath>
using namespace std;
class Program {
private:
	int guest[4];//���a���Ʀr
	int answer[4];//���T����
public:
	Program(int);
	void setnumber(int);
	int judgeA();
	int judgeB();
	void print();
};

#endif
