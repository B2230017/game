#include "Program.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {

    srand(time(nullptr));//創建亂數(answer)
    int digits[10] = { 0 };
    int owner = 0;
    for (int i = 0; i < 4; i++) {
        int digit;
        do {
            digit = rand() % 10;
        } while (digits[digit]);
        owner = owner * 10 + digit;
        digits[digit] = 1;
    }//創建亂數(answer)
    Program p(owner);
    cout << "歡迎來到1A2B" << endl << endl;
    cout << "遊戲說明:猜四個0到9的數字且不重複" << endl << endl;
    cout << "請選擇難度(困難按1，簡單按2)" << endl;
    int n;
    cin >> n;
    cout << endl;
    cout << "請開始遊戲" << endl;
    if (n == 1) {
        bool tf = true;
        for (int i = 0; i < 7; i++) {
            cout << "請輸入數字:" << endl;
            int guest;
            cin >> guest;
            p.setnumber(guest);
            if (guest == owner) {
                cout << "挑戰成功" << endl;
                tf = false;
                break;
            }
            p.printjudge();
        }
        if (tf) {
            cout << "挑戰失敗" << endl;
            cout << "答案: " << owner << endl;
        }
    }
    else if (n == 2) {
        bool tf = true;
        for (int i = 0; i < 10; i++) {
            cout << "請輸入數字:" << endl;
            int guest;
            cin >> guest;
            p.setnumber(guest);
            if (guest == owner) {
                cout << "恭喜挑戰成功" << endl;
                tf = false;
                break;
            }
            p.printjudge();
        }
        if (tf) {
            cout << "挑戰失敗" << endl;
            cout << "答案: " << owner << endl;
        }
    }


}