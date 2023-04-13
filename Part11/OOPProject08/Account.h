#pragma once

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
    int accID;  // °èÁÂ¹øÈ£
    char* cusName; // °í°´ÀÌ¸§
    int balance; // ÀÜ¾×
public:
    Account(int accID, int balance, const char* cusName);
    Account(const Account& copy);
    Account& operator=(const Account& ref);

    int getID();
    virtual void Deposit(int money);
    int WithDraw(int money);
    void ShowInfo() const;
    ~Account();
};
#endif