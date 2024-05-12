#include "Program.h"
#include <iostream>
using namespace std;

Program::Program(int number) { //初始化答案
    owner[0] = number / 10 / 10 / 10;
    owner[1] = number / 10 / 10 % 10;
    owner[2] = number / 10 % 10;
    owner[3] = number % 10;
}
void Program::setnumber(int number) { //將玩家輸入的值編入guest陣列
    guest[0] = number / 10 / 10 / 10;
    guest[1] = number / 10 / 10 % 10;
    guest[2] = number / 10 % 10;
    guest[3] = number % 10;
}
void Program::printjudge() {
    int A = 0;
    int B = 0;

    for (int i = 0; i < 4; ++i) {
        if (guest[i] == owner[i]) {
            A++;
        }
        else {
            for (int j = 0; j < 4; ++j) {
                if (guest[i] == owner[j]) {
                    B++;
                    break;
                }
            }
        }
    }
    cout << A << "A" << B << "B" << endl;
}