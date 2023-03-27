#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

// 열거형 Menu 선택
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

enum { LEVEL_A = 7, LEVEL_B = 4, LEVELC = 2 };

enum { NORMAL = 1, CREDIT = 2 };

// 구조체
class Account
{
private:
    int accID;  // 계좌번호
    char* cusName; // 고객이름
    int balance; // 잔액
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
        cout << "계좌ID: " << accID << endl;
        cout << "이 름: " << cusName << endl;
        cout << "잔 액: " << balance << endl << endl;
    }
    ~Account() {
        delete[]cusName;
    }
};

class NormalAccount : public Account {
private:
    int interestRate; // 이자율
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
        NormalAccount::Deposit(money); // 원금과 이자
        Account::Deposit(money * (creditRating / 100.0)); // 특별 이자
    }
};

class AccountHandler {
private:
    Account* accArr[10];    // Account 저장을 위한 구조체 배열
    int accNum;     // 저장된 Account 수
protected:
    void MakeNormalAccount(void) {
        int id;
        char name[NAME_LEN];
        int balance;
        int interestRate; // 이자율

        cout << "[보통예금계좌 개설]" << endl;
        cout << "계좌ID: "; cin >> id;
        cout << "이름: "; cin >> name;
        cout << "입금액: "; cin >> balance;
        cout << "이자율: "; cin >> interestRate;
        cout << endl;

        accArr[accNum++] = new NormalAccount(id, balance, name, interestRate);
    }

    void MakeCreditAccount(void) {
        int id;
        char name[NAME_LEN];
        int balance;
        int interestRate; // 이자율
        int creditLevel; // 신용등급

        cout << "[신용신뢰계좌 개설]" << endl;
        cout << "계좌ID: "; cin >> id;
        cout << "이름: "; cin >> name;
        cout << "입금액: "; cin >> balance;
        cout << "이자율: "; cin >> interestRate;
        cout << "신용등급(1toA, 2toB, 3toC): "; cin >> creditLevel;
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
        cout << "----Menu----\n1. 계좌개설\n2. 입금\n3. 출금\n4.계좌정보 전체 출력\n5.프로그램 종료\n";
    }

    void MakeAccount(void) {
        int selectNum = -1;
        cout << "[계좌종류선택]" << endl;
        cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
        cout << "선택: ";
        cin >> selectNum;

        if (selectNum == NORMAL)
            MakeNormalAccount();
        else
            MakeCreditAccount();
    }

    void DepositMoney(void) {
        int money;
        int id;
        cout << "[입  금]" << endl;
        cout << "계좌ID: "; cin >> id;
        cout << "입금액: "; cin >> money;

        for (int i = 0; i < accNum; i++) {
            if (accArr[i]->getID() == id) {
                accArr[i]->Deposit(money);
                cout << "입금완료" << endl << endl;
                return;
            }
        }

        cout << "유효하지 않은 ID입니다." << endl << endl;
    }

    void WithdrawMoney(void) {
        int money;
        int id;
        cout << "[출  금]" << endl;
        cout << "계좌ID: "; cin >> id;
        cout << "출금액: "; cin >> money;

        for (int i = 0; i < accNum; i++) {
            if (accArr[i]->getID() == id) {
                if (accArr[i]->WithDraw(money) == 0)
                {
                    cout << "잔액부족" << endl << endl;
                    return;
                }
                cout << "출금완료" << endl << endl;
                return;
            }
        }
        cout << "유효하지 않은 ID입니다." << endl << endl;
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
        cout << "선택: ";
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


