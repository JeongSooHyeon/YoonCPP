#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN = 20;

// �Լ� ����
void ShowMenu(void);    // �޴����
void MakeAccount(void); // ���°���
void DepositMoney(void); // �Ա�
void WithdrawMoney(void);// ���
void ShowAllAccInfo(void); // �ܾ���ȸ

// ������ Menu ����
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// ����ü
class Account
{
private:
    int accID;  // ���¹�ȣ
    int balance; // �ܾ�
    char* cusName; // ���̸�
public:
    Account(int accID, int balance, const char* cusName)
        : accID(accID), balance(balance)
    {
        cusName = new char[strlen(cusName) + 1];
        strcpy_s(this->cusName, strlen(cusName) + 1, cusName);
    }
    Account(const Account& copy) : accID(copy.accID), balance(copy.balance) {
        cusName = new char[strlen(copy.cusName) + 1];
        strcpy_s(cusName, strlen(copy.cusName) + 1, copy.cusName);
    }
    int getID() {
        return accID;
    }
    void Deposit(int money) {
        balance += money;
        cout << "�ԱݿϷ�" << endl << endl;
    }
    void WithDraw(int money) {
        if (balance >= money) {
            balance -= money;
            cout << "��ݿϷ�" << endl << endl;
        }
        else
            cout << "�ܾ׺���" << endl << endl;
    }
    void ShowInfo() {
        cout << "����ID: " << accID << endl;
        cout << "�� ��: " << cusName << endl;
        cout << "�� ��: " << balance << endl << endl;
    }
    ~Account() {
        delete[]cusName;
    }
};

Account* accArr[10];    // Account ������ ���� ����ü �迭
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
            for (int i = 0; i < accNum; i++) {
                delete accArr[i];
            }
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}

void ShowMenu(void) {
    cout << "----Menu----\n1. ���°���\n2. �Ա�\n3. ���\n4.�������� ��ü ���\n5.���α׷� ����\n:";
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

    accArr[accNum] = new Account(id, balance, name);
    accNum++;
}

void DepositMoney(void) {
    int money;
    int id;
    cout << "[��  ��]" << endl;
    cout << "����ID: "; cin >> id;
    cout << "�Աݾ�: "; cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->getID() == id) {
            accArr[i]->Deposit(money);
            break;
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
        if (accArr[i]->getID() == id) {
            accArr[i]->WithDraw(money);
            break;
        }
    }
    cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void ShowAllAccInfo(void) {
    for (int i = 0; i < accNum; i++) {
        accArr[i]->ShowInfo();
    }
}
