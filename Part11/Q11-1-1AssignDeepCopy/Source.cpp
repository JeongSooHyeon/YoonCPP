#include <iostream>
#include <cstring>
using namespace std;

class Gun {
private:
	int bullet;	// ������ �Ѿ��� ��
public:
	Gun(int bnum) : bullet(bnum)
	{}
	void Shot() {
		cout << "BBAN" << endl;
		bullet--;
	}
};

class Police {
private:
	int handcuffs; // ����
	Gun* pistol;
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	// ���� ������
	Police(const Police& ref)
		: handcuffs(ref.handcuffs) {
		cout << "���� ������" << endl;
		if (ref.pistol != NULL) {
			pistol = new Gun(*(ref.pistol)); // Gun�� ���� ������ ȣ��
		}
		else
			pistol = NULL;
	}
	Police& operator=(const Police& ref) {
		cout << "���� ������" << endl;
		if(pistol != NULL)
			delete pistol;
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;

		handcuffs = ref.handcuffs;
		return *this;
	}
	void PutHandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shot();
	}
	~Police() {
		if (pistol != NULL)
			delete pistol;
	}
};

int main(void) {
	Police p1(3, 3);
	Police p2 = p1; // ���� ������

	Police p3(0, 2);
	Police p4(4, 5);
	p3 = p4;	// ���� ������



	return 0;
}