#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"
#include "Exceptionclass.h"

void AccountHandler::MakeNormalAccount(void) {
    int id;
    String name;
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

void AccountHandler::MakeCreditAccount(void) {
    int id;
    String name;
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

AccountHandler::AccountHandler() :accNum(0) {
}

int AccountHandler::getAccNum() {
    return accNum;
}
void AccountHandler::ShowMenu(void) {
    cout << "----Menu----\n1. 계좌개설\n2. 입금\n3. 출금\n4.계좌정보 전체 출력\n5.프로그램 종료\n";
}

void AccountHandler::MakeAccount(void) {
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

void AccountHandler::DepositMoney(void) throw(AccountException) {
    int money;
    int id;
    cout << "[입  금]" << endl;
    cout << "계좌ID: "; cin >> id;
    while (1) {
        cout << "입금액: "; cin >> money;
        try {
            for (int i = 0; i < accNum; i++) {
                if (accArr[i]->getID() == id) {
                    accArr[i]->Deposit(money);
                    cout << "입금완료" << endl << endl;
                    return;
                }
            }
            cout << "유효하지 않은 ID입니다." << endl << endl;
            return;
        }
        catch (AccountException& expn) {
            expn.ShowExceptionReason();
        }
    }

}

void AccountHandler::WithdrawMoney(void) throw(AccountException){
    int money;
    int id;
    cout << "[출  금]" << endl;
    cout << "계좌ID: "; cin >> id;
  
    while (1) {
        cout << "출금액: "; cin >> money;
        try {
            for (int i = 0; i < accNum; i++) {
                if (accArr[i]->getID() == id) {
                    accArr[i]->WithDraw(money);
                    cout << "출금완료" << endl << endl;
                    return;
                }
            }
            cout << "유효하지 않은 ID입니다." << endl << endl;
            return;
        }    
        catch (AccountException& expn) {
            expn.ShowExceptionReason();
        }
    }
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



