#include <iostream>
using namespace std;

int main(void) {
	int num = 0x010203;
	char* ptr = reinterpret_cast<char*>(&num); // 포인터 대상, 포인터 관련 대상

	for (int i = 0; i < sizeof(num); i++)
		cout << static_cast<int>(*(ptr + 1)) << endl;


	////////////////////////////////////////////////////////

	int num1 = 72;
	int* ptr = &num1;

	int adr = reinterpret_cast<int>(ptr);	// 주소 값을 정수로 변환
	cout << "Addr : " << adr << endl;	// 주소 값 출력

	int* rptr = reinterpret_cast<int*>(adr);	// 정수를 다시 주소 값으로 변환
	cout << "value : " << *rptr << endl;	// 주소 값에 저장된 정수 출력

	return 0;
}