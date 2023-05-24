#include <iostream>
using namespace std;

class SoSimple {
public:
	virtual void ShowSimpleInfo() {	// Polymorphic Ŭ����
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple {
public:
	void ShowSimpleInfo() {		// ���� �Լ�
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
		cout << "�� ��ȯ ����" << endl;
	else
		comPtr1->ShowSimpleInfo();
	return 0;
}