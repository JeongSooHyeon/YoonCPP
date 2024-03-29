#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN = 20;

// 열거형 Menu 선택
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// 구조체
class Account
{
private:
    int accID;  // 계좌번호
    int balance; // 잔액
    char* cusName; // 고객이름
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
        cout << "입금완료" << endl << endl;
    }
    void WithDraw(int money) {
        if (balance >= money) {
            balance -= money;
            cout << "출금완료" << endl << endl;
        }
        else
            cout << "잔액부족" << endl << endl;
    }
    void ShowInfo() {
        cout << "계좌ID: " << accID << endl;
        cout << "이 름: " << cusName << endl;
        cout << "잔 액: " << balance << endl << endl;
    }
    ~Account() {
        delete[]cusName;
    }
};

class AccountHandler {
private:
    Account* accArr[10];    // Account 저장을 위한 구조체 배열
    int accNum;     // 저장된 Account 수
public:
    AccountHandler() :accNum(0) {
       
    }
    ~AccountHandler() {
        for (int i = 0; i < getAccNum(); i++) {
            delete accArr[i];
        }
    }
    int getAccNum() {
        return accNum;
    }
    void ShowMenu(void) {
        cout << "----Menu----\n1. 계좌개설\n2. 입금\n3. 출금\n4.계좌정보 전체 출력\n5.프로그램 종료\n:";
    }

    void MakeAccount(void) {
        int id;
        char name[NAME_LEN];
        int balance;

        cout << "[계좌개설]" << endl;
        cout << "계좌ID: "; cin >> id;
        cout << "이름: "; cin >> name;
        cout << "입금액: "; cin >> balance;
        cout << endl;

        accArr[accNum] = new Account(id, balance, name);
        accNum++;
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
                break;
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
                accArr[i]->WithDraw(money);
                break;
            }
        }
        cout << "유효하지 않은 ID입니다." << endl << endl;
    }

    void ShowAllAccInfo(void) const {
        for (int i = 0; i < accNum; i++) {
            accArr[i]->ShowInfo();
        }
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


