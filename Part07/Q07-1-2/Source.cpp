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
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~MyFriendInfo() {
		cout << "���� Ŭ���� �Ҹ���" << endl;
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
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl << endl;
	}
	~MyFriendDetailInfo() {
		cout << "���� Ŭ���� �Ҹ���" << endl;
		delete[]addr;
		delete[]phone;
	}
};

int main(void) {
	MyFriendDetailInfo mf1(10, "������", "�ʷϺ� 4����", "232-441");
	MyFriendDetailInfo mf2(14, "�ҷ", "�۷��� ����������", "233-412");
	mf1.ShowMyFriendDetailInfo();
	mf2.ShowMyFriendDetailInfo();

	return 0;
}