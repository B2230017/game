#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Program.h"
#include <string>
#include <sstream>
#include <unordered_set>//快速查找
using namespace std;

bool hasDuplicateDigits(const string& str) {
    unordered_set<char> seen;
    for (char digit : str) {
        if (seen.find(digit) != seen.end()) {
            return true;//找到重複的數字
        }
        seen.insert(digit);
    }
    return false;//沒有重複的數字
}

int main() {
    srand(time(nullptr)); // 創建亂數種子
    int owner;
    bool validNumber = false;
    while (!validNumber) {
        int digits[10] = { 0 }; // 用於檢查數字是否重複
        owner = 0;
        bool firstDigitZero = true; // 用於檢查第一位是否為 0

        for (int i = 0; i < 4; ++i) {
            int digit;
            do {
                digit = rand() % 10;
            } while (digits[digit]);

            if (i == 0 && digit == 0) {//判斷第一位是不是0
                firstDigitZero = true;
                break;
            }

            owner = owner * 10 + digit;
            digits[digit] = 1;

            if (i == 0) {
                firstDigitZero = false;
            }
        }

        if (!firstDigitZero) {
            validNumber = true;
        }
    }
    Program p(owner); // 將答案給到 Program 裡面


    cout << "歡迎來到1A2B" << endl << endl;
    cout << "遊戲說明:猜四個0到9的數字且不重複" << endl << endl;

    cout << "請選擇難度(困難按1，簡單按2)" << endl;
    int n; 
    cin >> n;
    while (n != 1 && n != 2) {
        cout << "請輸入1或2:" << endl;
        cin >> n;
    }
    cout << endl;
    cout << "遊戲開始" << endl;


    if (n == 1) {
        bool tf = true;

        for (int i = 0; i < 7; i++) {
            cout << "請輸入您的答案:" << endl;

            string strguest;

            do {//判別數字是否為四位數和有無重複
                cin >> strguest;

                if (strguest.length() != 4) {
                    cout << "請輸入正確的4位數!" << endl;
                }
                else if (hasDuplicateDigits(strguest)) {
                    cout << "輸入的數字包含重複的數字，請重新輸入!" << endl;
                }
            } while (strguest.length() != 4 || hasDuplicateDigits(strguest));

            int guest = stoi(strguest);//轉換成整數

            p.setnumber(guest);

            if (guest == owner) {
                cout << "挑戰成功" << endl;
                tf = false;
                break;
            }
            p.judgeA();
            p.judgeB();
            p.print();
        }

        if (tf) {
            cout << "挑戰失敗" << endl;
            cout << "答案: " << owner << endl;
        }
    }


    else if (n == 2) {
        bool tf = true;

        for (int i = 0; i < 10; i++) {
            cout << "請輸入您的答案:" << endl;

            string strguest;

            do {
                cin >> strguest;

                if (strguest.length() != 4) {
                    cout << "請輸入正確的4位數!" << endl;
                }
                else if (hasDuplicateDigits(strguest)) {
                    cout << "輸入的數字包含重複的數字，請重新輸入!" << endl;
                }
            } while (strguest.length() != 4 || hasDuplicateDigits(strguest));

            int guest = stoi(strguest);
            p.setnumber(guest);

            if (guest == owner) {
                cout << "恭喜挑戰成功" << endl;
                tf = false;
                break;
            }
            p.judgeA();
            p.judgeB();
            p.print();
        }

        if (tf) {
            cout << "挑戰失敗" << endl;
            cout << "答案: " << owner << endl;
        }
    }


}