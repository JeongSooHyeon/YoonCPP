#pragma once

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account
{
private:
    int accID;  // °èÁÂ¹øÈ£
    int balance; // ÀÜ¾×
    String cusName; // °í°´ÀÌ¸§
public:
    Account(int accID, int balance, String cusName);
    //Account(const Account& copy);
   // Account& operator=(const Account& ref);

    int getID() const;
    virtual void Deposit(int money);
    int WithDraw(int money);
    void ShowInfo() const;
    //~Account();
};
#endif