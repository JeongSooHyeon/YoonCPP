#include <iostream>
using namespace std;

class AAA {
public:
	void ShowYou() { cout << "AAA exception!" << endl; }
};

class BBB : public AAA {
public:
	void ShowYou() { cout << "BBB exception!" << endl; }
};

class CCC : public BBB {
public:
	void ShowYou() { cout << "BBB exception!" << endl; }
};

void ExceptionGenerator(int expn) {
	if (expn == 1)
		throw AAA();
	else if (expn == 2)
		throw BBB();
	else
		throw CCC();
}

int main(void) {
	try {
		ExceptionGenerator(3);
		ExceptionGenerator(2);
		ExceptionGenerator(1);
	}
	catch (CCC& expn) {	// 순서 중요 AAA를 앞에 두면 다 여기서 catch됨
		cout << "catch(CCC& expn)" << endl;
		expn.ShowYou();
	}
	catch (BBB& expn) {
		cout << "catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch (AAA& expn) {
		cout << "catch(AAA& expn)" << endl;
		expn.ShowYou();
	}
}