#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"
#include "Account.h"

void AccountHandler::MakeNormalAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;
    int interestRate; // ������

    cout << "[���뿹�ݰ��� ����]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "�̸�: "; cin >> name;
    cout << "�Աݾ�: "; cin >> balance;
    cout << "������: "; cin >> interestRate;
    cout << endl;

    accArr[accNum++] = new NormalAccount(id, balance, name, interestRate);
}

void AccountHandler::MakeCreditAccount(void) {
    int id;
    char name[NAME_LEN];
    int balance;
    int interestRate; // ������
    int creditLevel; // �ſ���

    cout << "[�ſ�ŷڰ��� ����]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "�̸�: "; cin >> name;
    cout << "�Աݾ�: "; cin >> balance;
    cout << "������: "; cin >> interestRate;
    cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> creditLevel;
    cout << endl;

    switch (creditLevel) {
    case 1:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interestRate, LEVEL_A);
        break;
    case 2:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interestRate, LEVEL_B);
        break;
    case 3:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interestRate, LEVEL_B);
        break;
    }
}

AccountHandler::AccountHandler() :accNum(0) {
}

int AccountHandler::getAccNum() {
    return accNum;
}
void AccountHandler::ShowMenu(void) {
    cout << "----Menu----\n1. ���°���\n2. �Ա�\n3. ���\n4.�������� ��ü ���\n5.���α׷� ����\n";
}

void AccountHandler::MakeAccount(void) {
    int selectNum = -1;
    cout << "[������������]" << endl;
    cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
    cout << "����: ";
    cin >> selectNum;

    if (selectNum == NORMAL)
        MakeNormalAccount();
    else
        MakeCreditAccount();
}

void AccountHandler::DepositMoney(void) {
    int money;
    int id;
    cout << "[��  ��]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "�Աݾ�: "; cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->getID() == id) {
            accArr[i]->Deposit(money);
            cout << "�ԱݿϷ�" << endl << endl;
            return;
        }
    }

    cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void AccountHandler::WithdrawMoney(void) {
    int money;
    int id;
    cout << "[��  ��]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "��ݾ�: "; cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->getID() == id) {
            if (accArr[i]->WithDraw(money) == 0)
            {
                cout << "�ܾ׺���" << endl << endl;
                return;
            }
            cout << "��ݿϷ�" << endl << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) const {
    for (int i = 0; i < accNum; i++) {
        accArr[i]->ShowInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler() {
    for (int i = 0; i < accNum; i++)
        delete accArr[i];
}



