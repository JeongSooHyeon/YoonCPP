#include <iostream>
#include <new> // bad_alloc ���� Ŭ���� ����
using namespace std;

int main(void) {
	int num = 0;

	try {
		while (1)
		{
			num++;
			cout << num << "��° �Ҵ� �õ�" << endl;
			new int[10000][10000];
		}
	}
	catch (bad_alloc& bad) {
		cout << bad.what() << endl;	// ������ ���������� ���ڿ��� ���·� ��ȯ
		cout << "�� �̻� �Ҵ� �Ұ�!" << endl;
	}
	return 0;
}