#include <iostream>
#include <new> // bad_alloc 예외 클래스 선언
using namespace std;

int main(void) {
	int num = 0;

	try {
		while (1)
		{
			num++;
			cout << num << "번째 할당 시도" << endl;
			new int[10000][10000];
		}
	}
	catch (bad_alloc& bad) {
		cout << bad.what() << endl;	// 예외의 원인정보를 문자열의 형태로 반환
		cout << "더 이상 할당 불가!" << endl;
	}
	return 0;
}