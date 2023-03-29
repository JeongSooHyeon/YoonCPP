#pragma once
#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account {
private:
    int interestRate; // ¿Ã¿⁄¿≤
public:
    NormalAccount(int accID, int balance, const char* cusName, int interestRate)
        : Account(accID, balance, cusName), interestRate(interestRate)
    {}
    virtual void Deposit(int money) {
        Account::Deposit(money);
        Account::Deposit(money * (interestRate / 100.0));
    }
}; 
#endif