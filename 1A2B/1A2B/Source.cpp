#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Program.h"
#include <string>
#include <sstream>
#include <unordered_set>//�ֳt�d��
using namespace std;

bool hasDuplicateDigits(const string& str) {
    unordered_set<char> seen;
    for (char digit : str) {
        if (seen.find(digit) != seen.end()) {
            return true;//��쭫�ƪ��Ʀr
        }
        seen.insert(digit);
    }
    return false;//�S�����ƪ��Ʀr
}

int main() {
    srand(time(nullptr)); // �Ыضüƺؤl
    int owner;
    bool validNumber = false;
    while (!validNumber) {
        int digits[10] = { 0 }; // �Ω��ˬd�Ʀr�O�_����
        owner = 0;
        bool firstDigitZero = true; // �Ω��ˬd�Ĥ@��O�_�� 0

        for (int i = 0; i < 4; ++i) {
            int digit;
            do {
                digit = rand() % 10;
            } while (digits[digit]);

            if (i == 0 && digit == 0) {//�P�_�Ĥ@��O���O0
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
    Program p(owner); // �N���׵��� Program �̭�


    cout << "�w��Ө�1A2B" << endl << endl;
    cout << "�C������:�q�|��0��9���Ʀr�B������" << endl << endl;

    cout << "�п������(�x����1�A²���2)" << endl;
    int n; 
    cin >> n;
    while (n != 1 && n != 2) {
        cout << "�п�J1��2:" << endl;
        cin >> n;
    }
    cout << endl;
    cout << "�C���}�l" << endl;


    if (n == 1) {
        bool tf = true;

        for (int i = 0; i < 7; i++) {
            cout << "�п�J�z������:" << endl;

            string strguest;

            do {//�P�O�Ʀr�O�_���|��ƩM���L����
                cin >> strguest;

                if (strguest.length() != 4) {
                    cout << "�п�J���T��4���!" << endl;
                }
                else if (hasDuplicateDigits(strguest)) {
                    cout << "��J���Ʀr�]�t���ƪ��Ʀr�A�Э��s��J!" << endl;
                }
            } while (strguest.length() != 4 || hasDuplicateDigits(strguest));

            int guest = stoi(strguest);//�ഫ�����

            p.setnumber(guest);

            if (guest == owner) {
                cout << "�D�Ԧ��\" << endl;
                tf = false;
                break;
            }
            p.judgeA();
            p.judgeB();
            p.print();
        }

        if (tf) {
            cout << "�D�ԥ���" << endl;
            cout << "����: " << owner << endl;
        }
    }


    else if (n == 2) {
        bool tf = true;

        for (int i = 0; i < 10; i++) {
            cout << "�п�J�z������:" << endl;

            string strguest;

            do {
                cin >> strguest;

                if (strguest.length() != 4) {
                    cout << "�п�J���T��4���!" << endl;
                }
                else if (hasDuplicateDigits(strguest)) {
                    cout << "��J���Ʀr�]�t���ƪ��Ʀr�A�Э��s��J!" << endl;
                }
            } while (strguest.length() != 4 || hasDuplicateDigits(strguest));

            int guest = stoi(strguest);
            p.setnumber(guest);

            if (guest == owner) {
                cout << "���߬D�Ԧ��\" << endl;
                tf = false;
                break;
            }
            p.judgeA();
            p.judgeB();
            p.print();
        }

        if (tf) {
            cout << "�D�ԥ���" << endl;
            cout << "����: " << owner << endl;
        }
    }


}