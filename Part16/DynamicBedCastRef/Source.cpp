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
	SoSimple simObj;
	SoSimple& ref = simObj;

	try {
		SoComplex& comRef = dynamic_cast<SoComplex&>(ref); // SoSimple->SoComplex 형변환 안전하지 않음, 참조자 대상으로 NULL 반환 불가 : bad_cast 예외 발생 !
		comRef.ShowSimpleInfo();
	}
	catch (bad_cast expt) {
		cout << expt.what() << endl;
	}
	
	return 0;
}