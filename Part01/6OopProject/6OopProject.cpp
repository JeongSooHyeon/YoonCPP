/*
* 01-6 OOP �ܰ躰 ������Ʈ 1�ܰ�
���� ���� ���� ���α׷�
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int selectNum = -1;

    int ID[10];
    string name[10];
    int balance[10]; // �ܾ�

    int cnt = 0;


    int inputID; // �Է� ID
    int inputDeposit; // �Է� �Աݾ�
    int idx = 0;
    int inputWithdraw; // �Է� ��ݾ�

    while (true) {
        cout << "----Menu----\n1. ���°���\n2. �Ա�\n3. ���\n4.�������� ��ü ���\n5.���α׷� ����\n����:";
        cin >> selectNum;

        switch (selectNum) {
        case 1:
            cout << "\n[���°���]\n����ID:";
            cin >> ID[cnt];
            cout << "�̸�:";
            cin >> name[cnt];
            cout << "�Աݾ�:";
            cin >> balance[cnt];
            cnt++;
            break;
        case 2:
            idx = 0;

            cout << "\n[��  ��]\n����ID:";
            cin >> inputID;
            cout << "�Աݾ�:";
            cin >> inputDeposit;
            while (true) {
                if (ID[idx] == inputID) {
                    balance[idx] += inputDeposit;
                    break;
                }
                idx++;
            }
            cout << "�ԱݿϷ�\n";
            break;
        case 3:
            idx = 0;
            cout << "\n[��  ��]\n����ID:";
            cin >> inputID;
            cout << "��ݾ�:";
            cin >> inputWithdraw;
            while (true) {
                if (ID[idx] == inputID) {
                    balance[idx] -= inputWithdraw;
                    break;
                }
                idx++;
            }
            cout << "��ݿϷ�\n";
            break;
        case 4:
            for (int i = 0; i < cnt; i++) {
                cout << "\n����ID: " << ID[i] << endl;
                cout << "�̸�: " << name[i] << endl;
                cout << "�ܾ� :" << balance[i] << endl;
            }
            break;
        default:
            return 0;
        }
    }

}
