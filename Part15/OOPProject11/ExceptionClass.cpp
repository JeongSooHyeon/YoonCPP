#include "ExceptionClass.h"

WithDrawException::WithDrawException(int money) : money(money) {}
void WithDrawException::ShowExceptionReason() {
	cout << "�ܾ� ����" << endl << "���Է� �Ͻÿ�" << endl;
}

InputException::InputException(int money) : money(money) {}
void InputException::ShowExceptionReason() {
	cout << "0���� ū ���� �Է��Ͻÿ�" << endl << "���Է� �Ͻÿ�" << endl;
}