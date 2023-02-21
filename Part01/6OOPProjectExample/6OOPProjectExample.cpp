#include <iostream>
#include <cstring>
/*
�����Լ� ��������
������
����ü*/
using namespace std;
const int NAME_LEN = 20;

// �Լ� ����
void ShowMenu(void);    // �޴����
void MakeAccount(void); // ���°���
void DepositMoney(void); // �Ա�
void WithdrawMoney(void);// ���
void ShowAllAccInfo(void); // �ܾ���ȸ

// ������ Menu ����
enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

// ����ü
typedef struct 
{
    int accID;  // ���¹�ȣ
    int balance; // �ܾ�
    char cusName[NAME_LEN]; // ���̸�
} Account;

Account accArr[100];    // Account ������ ���� ����ü �迭
int accNum = 0;     // ����� Account ��

int main()
{
    int choice;

    while (1) {
        ShowMenu();
        cout << "����: ";
        cin >> choice;
        cout << endl;

        switch (choice) 
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}

void ShowMenu(void) {
    cout << "----Menu----\n1. ���°���\n2. �Ա�\n3. ���\n4.�������� ��ü ���\n5.���α׷� ����\n����:";
}

void MakeAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[���°���]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "�̸�: "; cin >> name;
    cout << "�Աݾ�: "; cin >> balance;
    cout << endl;

    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name);
    accNum++;
}

void DepositMoney(void) {
    int money;
    int id;
    cout << "[��  ��]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "�Աݾ�: "; cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            accArr[i].balance += money;
            cout << "�ԱݿϷ�" << endl << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void WithdrawMoney(void) {
    int money;
    int id;
    cout << "[��  ��]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "��ݾ�: "; cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i].accID == id) {
            if (accArr[i].balance < money) {
                cout << "�ܾ׺���" << endl << endl;
                return;
            }

            accArr[i].balance -= money;
            cout << "��ݿϷ�" << endl << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void ShowAllAccInfo(void) {
    for (int i = 0; i < accNum; i++) {
        cout << "����ID: " << accArr[i].accID << endl;
        cout << "�� ��: " << accArr[i].cusName << endl;
        cout << "�� ��: " << accArr[i].balance << endl << endl;
    }
}
