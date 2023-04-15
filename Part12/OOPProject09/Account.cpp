#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int accID, int balance, String cusName)
    : accID(accID), balance(balance)
{
    this->cusName = cusName;
}
//Account::Account(const Account& copy)
//    : accID(copy.accID), balance(copy.balance) {
//    cusName = copy.cusName;
//}
//Account& Account::operator=(const Account& ref) {
//    accID = ref.accID;
//    balance = ref.balance;
//    cusName = ref.cusName;
//
//    return *this;
//}
int Account::getID() const{
    return accID;
}
void Account::Deposit(int money) {
    balance += money;
}
int Account::WithDraw(int money) {
    if (balance < money)
        return 0;

    balance -= money;
    return money;
}
void Account::ShowInfo() const {
    cout << "����ID: " << accID << endl;
    cout << "�� ��: " << cusName << endl;
    cout << "�� ��: " << balance << endl << endl;
}

