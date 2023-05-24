#include <iostream>
using namespace std;

class SoSimple {
public:
	virtual void ShowSimpleInfo() {	// Polymorphic 클래스
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple {
public:
	void ShowSimpleInfo() {		// 가상 함수
		cout << "SoComplex Derived Class" << endl;
	}
};

int main(void) {
	SoSimple* simPtr = new SoComplex;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	comPtr->ShowSimpleInfo();


	//////////////////////////////////////////
	SoSimple* simPtr1 = new SoSimple;
	SoComplex* comPtr1 = dynamic_cast<SoComplex*>(simPtr1);  
	if (comPtr1 == NULL)
		cout << "형 변환 실패" << endl;
	else
		comPtr1->ShowSimpleInfo();
	return 0;
}