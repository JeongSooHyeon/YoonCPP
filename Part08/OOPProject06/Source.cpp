#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

// ������ Menu ����
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

enum { LEVEL_A = 7, LEVEL_B = 4, LEVELC = 2 };

enum { NORMAL = 1, CREDIT = 2 };

// ����ü
class Account
{
private:
    int accID;  // ���¹�ȣ
    char* cusName; // ���̸�
    int balance; // �ܾ�
public:
    Account(int accID, int balance, const char* cusName)
        : accID(accID), balance(balance)
    {
        this->cusName = new char[strlen(cusName) + 1];
        strcpy_s(this->cusName, strlen(cusName) + 1, cusName);
    }
    Account(const Account& copy) : accID(copy.accID), balance(copy.balance) {
        cusName = new char[strlen(copy.cusName) + 1];
        strcpy_s(cusName, strlen(copy.cusName) + 1, copy.cusName);
    }
    int getID() {
        return accID;
    }
    virtual void Deposit(int money) {
        balance += money;
    }
    int WithDraw(int money) {
        if (balance < money)
            return 0;

        balance -= money;
        return money;
    }

    void ShowInfo() const {
        cout << "����ID: " << accID << endl;
        cout << "�� ��: " << cusName << endl;
        cout << "�� ��: " << balance << endl << endl;
    }
    ~Account() {
        delete[]cusName;
    }
};

class NormalAccount : public Account {
private:
    int interestRate; // ������
public:
    NormalAccount(int accID, int balance, const char* cusName, int interestRate)
        : Account(accID, balance, cusName), interestRate(interestRate)
    {}
    virtual void Deposit(int money) {
        Account::Deposit(money);
        Account::Deposit(money * (interestRate / 100.0));
    }
};

class HighCreditAccount : public NormalAccount {
private:
    int creditRating;
public:
    HighCreditAccount(int accID, int balance, const char* cusName, int interestRate, int creditRating)
        : NormalAccount(accID, balance, cusName, interestRate), creditRating(creditRating)
    {}
    virtual void Deposit(int money) {
        NormalAccount::Deposit(money); // ���ݰ� ����
        Account::Deposit(money * (creditRating / 100.0)); // Ư�� ����
    }
};

class AccountHandler {
private:
    Account* accArr[10];    // Account ������ ���� ����ü �迭
    int accNum;     // ����� Account ��
protected:
    void MakeNormalAccount(void) {
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

    void MakeCreditAccount(void) {
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
public:
    AccountHandler() :accNum(0) {
    }

    int getAccNum() {
        return accNum;
    }
    void ShowMenu(void) {
        cout << "----Menu----\n1. ���°���\n2. �Ա�\n3. ���\n4.�������� ��ü ���\n5.���α׷� ����\n";
    }

    void MakeAccount(void) {
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

    void DepositMoney(void) {
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

    void WithdrawMoney(void) {
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

    void ShowAllAccInfo(void) const {
        for (int i = 0; i < accNum; i++) {
            accArr[i]->ShowInfo();
            cout << endl;
        }
    }

    ~AccountHandler(){
        for (int i = 0; i < accNum; i++ )
            delete accArr[i];
    }
};

int main()
{
    AccountHandler handler;
    int choice;

    while (1) {
        handler.ShowMenu();
        cout << "����: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case MAKE:
            handler.MakeAccount();
            break;
        case DEPOSIT:
            handler.DepositMoney();
            break;
        case WITHDRAW:
            handler.WithdrawMoney();
            break;
        case INQUIRE:
            handler.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}


