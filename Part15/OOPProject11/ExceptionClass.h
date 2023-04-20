#pragma once
#ifndef __EXCEPTION_CLASS_H__
#define __EXCEPTION_CLASS_H__

#include <iostream>
using namespace std;

class AccountException {
public:
	virtual void ShowExceptionReason() = 0;
};

class WithDrawException : public AccountException {
private:
	int money;
public:
	WithDrawException(int money);
	void ShowExceptionReason();
};

class InputException : public AccountException {
private:
	int money;
public:
	InputException(int money);
	void ShowExceptionReason();
};
#endif