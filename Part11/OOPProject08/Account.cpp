#include "Account.h"
#include "BankingCommonDecl.h"

Account::Account(int accID, int balance, const char* cusName)
    : accID(accID), balance(balance)
{
    this->cusName = new char[strlen(cusName) + 1];
    strcpy_s(this->cusName, strlen(cusName) + 1, cusName);
}
Account::Account(const Account& copy)
    : accID(copy.accID), balance(copy.balance) {
    cusName = new char[strlen(copy.cusName) + 1];
    strcpy_s(cusName, strlen(copy.cusName) + 1, copy.cusName);
}
Account& Account::operator=(const Account& ref) {
    accID = ref.accID;
    balance = ref.balance;

    delete[] cusName;
    cusName = new char[strlen(ref.cusName) + 1];
    strcpy_s(cusName, strlen(ref.cusName) + 1, ref.cusName);

    return *this;
}
int Account::getID() {
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
    cout << "°èÁÂID: " << accID << endl;
    cout << "ÀÌ ¸§: " << cusName << endl;
    cout << "ÀÜ ¾×: " << balance << endl << endl;
}
Account::~Account() {
    delete[]cusName;
}


