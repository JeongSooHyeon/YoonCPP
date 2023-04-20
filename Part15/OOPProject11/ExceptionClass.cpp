#include "ExceptionClass.h"

WithDrawException::WithDrawException(int money) : money(money) {}
void WithDrawException::ShowExceptionReason() {
	cout << "잔액 부족" << endl << "재입력 하시오" << endl;
}

InputException::InputException(int money) : money(money) {}
void InputException::ShowExceptionReason() {
	cout << "0보다 큰 값을 입력하시오" << endl << "재입력 하시오" << endl;
}