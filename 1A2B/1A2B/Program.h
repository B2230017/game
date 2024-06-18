#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include <cmath>
using namespace std;
class Program {
private:
	int guest[4];//玩家的數字
	int answer[4];//正確答案
public:
	Program(int);
	void setnumber(int);
	int judgeA();
	int judgeB();
	void print();
};

#endif
