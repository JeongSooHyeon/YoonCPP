#pragma once
#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

class AccountHandler {
private:
    Account* accArr[10];    // Account 저장을 위한 구조체 배열
    int accNum;     // 저장된 Account 수
protected:
    void MakeNormalAccount(void);
    void MakeCreditAccount(void);
public:
    AccountHandler();
    int getAccNum();
    void ShowMenu(void);
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    ~AccountHandler();
};
#endif

