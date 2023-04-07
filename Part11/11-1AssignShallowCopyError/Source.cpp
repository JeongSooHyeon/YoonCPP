#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		age = myage;
	}
	void ShowPersonInfo() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person() {
		delete[]name;
		cout << "Called destructor!" << endl;
	}
	Person& operator=(const Person & ref){
		delete[]name; // 메모리 누수를 막기 위한 메모리 헤제 연산

		int len = strlen(ref.name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, ref.name);

		this->age = ref.age;

		return *this;
	}
};

int main(void) {
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}