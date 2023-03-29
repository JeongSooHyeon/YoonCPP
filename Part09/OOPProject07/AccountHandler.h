#pragma once
#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

class AccountHandler {
private:
    Account* accArr[10];    // Account ������ ���� ����ü �迭
    int accNum;     // ����� Account ��
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

