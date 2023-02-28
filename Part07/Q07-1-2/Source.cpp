#include <iostream>
using namespace std;

class MyFriendInfo {
private:
	char* name;
	int age;
public:
	MyFriendInfo(int age, const char* name) : age(age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	void ShowMyFriendInfo() {
		cout << "ÀÌ¸§: " << name << endl;
		cout << "³ªÀÌ: " << age << endl;
	}
	~MyFriendInfo() {
		cout << "±âÃÊ Å¬·¡½º ¼Ò¸êÀÚ" << endl;
		delete[]name;
	}
};

class MyFriendDetailInfo :public MyFriendInfo {
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(int age, const char* name, const char* addr, const char* phone)
		: MyFriendInfo(age, name) 
	{
		this->addr = new char[strlen(addr) + 1];
		strcpy_s(this->addr, strlen(addr) + 1, addr);

		this->phone = new char[strlen(phone) + 1];
		strcpy_s(this->phone, strlen(phone) + 1, phone);
	}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "ÁÖ¼Ò: " << addr << endl;
		cout << "ÀüÈ­: " << phone << endl << endl;
	}
	~MyFriendDetailInfo() {
		cout << "À¯µµ Å¬·¡½º ¼Ò¸êÀÚ" << endl;
		delete[]addr;
		delete[]phone;
	}
};

int main(void) {
	MyFriendDetailInfo mf1(10, "¸¸µæÀÌ", "ÃÊ·Ïº° 4»ÏÁ·", "232-441");
	MyFriendDetailInfo mf2(14, "¼Ò·î¶±", "ÆÛ··º° °­³²ºô¸®Áö", "233-412");
	mf1.ShowMyFriendDetailInfo();
	mf2.ShowMyFriendDetailInfo();

	return 0;
}