#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
	char name[100];
public:
	Employee(const char* name) {
		strcpy_s(this->name, name);
	}
	void ShowYourName() const {
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee {
private:
	int salary;	// �� �޿�
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money){}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee { // �ӽ���
private:
	int workTime;	
	int payPerHour;
public:
	TemporaryWorker(const char * name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{}
	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() const {
		return workTime * payPerHour;
	}
	void showSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker {
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{}
	void AddSalesResult(int value) {
		salesResult += value;
	}
	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << GetPay() << endl << endl;
	}
};

namespace RISK_LEVEL {
	enum { RISK_A = 30, RISK_B=20, RISK_C=10 };
}

class ForeignSaleWorker : public SalesWorker {
private:
	const int riskLevel;
public:
	ForeignSaleWorker(const char* name, int money, double ratio, int riskLevel)
		: SalesWorker(name, money, ratio), riskLevel(riskLevel)
	{}
	int GetRiskPay() const {
		return (int)(SalesWorker::GetPay() * (riskLevel / 100.0)); // 100���� �ϸ� �� ��

	}
	int GetPay() const {
		return SalesWorker::GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << SalesWorker::GetPay() << endl;
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{}
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() {
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();

		cout << "Salary sum: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void) {
	EmployeeHandler handler;

	ForeignSaleWorker* fseller1 = new ForeignSaleWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);	
	handler.AddEmployee(fseller1);

	ForeignSaleWorker* fseller2 = new ForeignSaleWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSaleWorker* fseller3 = new ForeignSaleWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
	return 0;
}