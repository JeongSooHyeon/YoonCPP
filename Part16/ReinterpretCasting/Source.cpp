#include <iostream>
using namespace std;

int main(void) {
	int num = 0x010203;
	char* ptr = reinterpret_cast<char*>(&num); // ������ ���, ������ ���� ���

	for (int i = 0; i < sizeof(num); i++)
		cout << static_cast<int>(*(ptr + 1)) << endl;


	////////////////////////////////////////////////////////

	int num1 = 72;
	int* ptr = &num1;

	int adr = reinterpret_cast<int>(ptr);	// �ּ� ���� ������ ��ȯ
	cout << "Addr : " << adr << endl;	// �ּ� �� ���

	int* rptr = reinterpret_cast<int*>(adr);	// ������ �ٽ� �ּ� ������ ��ȯ
	cout << "value : " << *rptr << endl;	// �ּ� ���� ����� ���� ���

	return 0;
}