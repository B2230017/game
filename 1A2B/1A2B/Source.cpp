#include "Program.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {

    srand(time(nullptr));//�Ыضü�(answer)
    int digits[10] = { 0 };
    int owner = 0;
    for (int i = 0; i < 4; i++) {
        int digit;
        do {
            digit = rand() % 10;
        } while (digits[digit]);
        owner = owner * 10 + digit;
        digits[digit] = 1;
    }//�Ыضü�(answer)
    Program p(owner);
    cout << "�w��Ө�1A2B" << endl << endl;
    cout << "�C������:�q�|��0��9���Ʀr�B������" << endl << endl;
    cout << "�п������(�x����1�A²���2)" << endl;
    int n;
    cin >> n;
    cout << endl;
    cout << "�ж}�l�C��" << endl;
    if (n == 1) {
        bool tf = true;
        for (int i = 0; i < 7; i++) {
            cout << "�п�J�Ʀr:" << endl;
            int guest;
            cin >> guest;
            p.setnumber(guest);
            if (guest == owner) {
                cout << "�D�Ԧ��\" << endl;
                tf = false;
                break;
            }
            p.printjudge();
        }
        if (tf) {
            cout << "�D�ԥ���" << endl;
            cout << "����: " << owner << endl;
        }
    }
    else if (n == 2) {
        bool tf = true;
        for (int i = 0; i < 10; i++) {
            cout << "�п�J�Ʀr:" << endl;
            int guest;
            cin >> guest;
            p.setnumber(guest);
            if (guest == owner) {
                cout << "���߬D�Ԧ��\" << endl;
                tf = false;
                break;
            }
            p.printjudge();
        }
        if (tf) {
            cout << "�D�ԥ���" << endl;
            cout << "����: " << owner << endl;
        }
    }


}