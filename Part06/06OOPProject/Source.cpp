/*
const Ãß°¡ÇÏ±â
*/#include <iostream>
using namespace std;

class Account
{
private:
	int accID;		// °èÁÂ¹øÈ£
	int balance;	// ÀÜ¾×
	char* cusName;	// °í°´ÀÌ¸§

public:
	Account(int ID, int money, char* name)
		: accID(ID), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy_s(cusName, strlen(name) + 1, name);
	}

	Account(const Account& ref)
		: accID(ref.accID), balance(ref.balance)
	{
		cusName = new char[strlen(ref.cusName) + 1];
		strcpy_s(cusName, strlen(ref.cusName) + 1, cusName);
	}

	int GetAccID() const { return accID; }

	void Deposit(int money) {
		balance += money;
	}

	int Withdraw(int money) {
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}

	void ShowAccInfo() const
	{
		cout << "°èÁÂID: " << accID << endl;
		cout << "ÀÌ¸§: " << cusName << endl;
		cout << "ÀÜ¾×: " << balance << endl;
	}

	~Account() {
		delete[]cusName;
	}
};
