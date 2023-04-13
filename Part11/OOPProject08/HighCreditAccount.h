#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

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
#endif