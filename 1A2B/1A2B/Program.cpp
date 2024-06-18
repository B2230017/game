#include "Program.h"
#include <iostream>
using namespace std;

Program::Program(int answer) { //初始化答案
    for (int i = 0; i < 4; ++i) {
        this->answer[3 - i] = answer / static_cast<int>(pow(10, i)) % 10;//會用到static_cast<>()是因為pow回傳的值是double，所以給他轉回int
    }
}

void Program::setnumber(int guest) { //將玩家輸入的值編入guest陣列
    for (int i = 0; i < 4; ++i) {
        this->guest[3 - i] = guest / static_cast<int>(pow(10, i)) % 10;
    }
}

int Program::judgeA() {
    int A = 0;

    for (int i = 0; i < 4; ++i) {
        if (guest[i] == answer[i])A++;
    }

    return A;
}

int Program::judgeB() {
    int B = 0;

    for (int i = 0; i < 4; ++i) {
        if (guest[i] == answer[i]) {}
        else {
            for (int j = 0; j < 4; ++j) {
                if (guest[i] == answer[j]) {
                    B++;
                    break;
                }
            }
        }
    }

    return B;
}

void Program::print() {
    cout << judgeA() << "A" << judgeB() << "B" << endl;
}