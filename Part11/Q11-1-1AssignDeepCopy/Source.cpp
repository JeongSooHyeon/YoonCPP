#include <iostream>
#include <cstring>
using namespace std;

class Gun {
private:
	int bullet;	// 장전된 총알의 수
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
	int handcuffs; // 수갑
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
	// 복사 생성자
	Police(const Police& ref)
		: handcuffs(ref.handcuffs) {
		cout << "복사 생성자" << endl;
		if (ref.pistol != NULL) {
			pistol = new Gun(*(ref.pistol)); // Gun의 복사 생성자 호출
		}
		else
			pistol = NULL;
	}
	Police& operator=(const Police& ref) {
		cout << "대입 연산자" << endl;
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
	Police p2 = p1; // 복사 생성자

	Police p3(0, 2);
	Police p4(4, 5);
	p3 = p4;	// 대입 연산자



	return 0;
}