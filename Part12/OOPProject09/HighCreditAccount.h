#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount {
private:
    int creditRating;
public:
    HighCreditAccount(int accID, int balance, String cusName, int interestRate, int creditRating)
        : NormalAccount(accID, balance, cusName, interestRate), creditRating(creditRating)
    {}
    virtual void Deposit(int money) {
        NormalAccount::Deposit(money); // 원금과 이자
        Account::Deposit(money * (creditRating / 100.0)); // 특별 이자
    }
};
#endif