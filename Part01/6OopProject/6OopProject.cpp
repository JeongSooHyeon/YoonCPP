/*
* 01-6 OOP 단계별 프로젝트 1단계
은행 계좌 관리 프로그램
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int selectNum = -1;

    int ID[10];
    string name[10];
    int balance[10]; // 잔액

    int cnt = 0;


    int inputID; // 입력 ID
    int inputDeposit; // 입력 입금액
    int idx = 0;
    int inputWithdraw; // 입력 출금액

    while (true) {
        cout << "----Menu----\n1. 계좌개설\n2. 입금\n3. 출금\n4.계좌정보 전체 출력\n5.프로그램 종료\n선택:";
        cin >> selectNum;

        switch (selectNum) {
        case 1:
            cout << "\n[계좌개설]\n계좌ID:";
            cin >> ID[cnt];
            cout << "이름:";
            cin >> name[cnt];
            cout << "입금액:";
            cin >> balance[cnt];
            cnt++;
            break;
        case 2:
            idx = 0;

            cout << "\n[입  금]\n계좌ID:";
            cin >> inputID;
            cout << "입금액:";
            cin >> inputDeposit;
            while (true) {
                if (ID[idx] == inputID) {
                    balance[idx] += inputDeposit;
                    break;
                }
                idx++;
            }
            cout << "입금완료\n";
            break;
        case 3:
            idx = 0;
            cout << "\n[출  금]\n계좌ID:";
            cin >> inputID;
            cout << "출금액:";
            cin >> inputWithdraw;
            while (true) {
                if (ID[idx] == inputID) {
                    balance[idx] -= inputWithdraw;
                    break;
                }
                idx++;
            }
            cout << "출금완료\n";
            break;
        case 4:
            for (int i = 0; i < cnt; i++) {
                cout << "\n계좌ID: " << ID[i] << endl;
                cout << "이름: " << name[i] << endl;
                cout << "잔액 :" << balance[i] << endl;
            }
            break;
        default:
            return 0;
        }
    }

}
