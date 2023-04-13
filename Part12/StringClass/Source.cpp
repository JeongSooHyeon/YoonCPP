#include <iostream>
#include <cstring>
using namespace std;
// 배고프노

class String {
private:
	char* str;
public:
	String(const char* str) {
		this->str = new char[strlen(str) + 1];
		strcpy_s(this->str, strlen(str) + 1, str);
	}
	String(const String& copy) {
		str = new char[strlen(copy.str) + 1];
		strcpy_s(str, strlen(copy.str) + 1, copy.str);
	}
	String& operator=(const String& copy) {
		delete[] str;
		str = new char[strlen(copy.str) + 1];
		strcpy_s(str, strlen(copy.str) + 1, copy.str);

		return *this;
	}
	String operator+(const String& ref) {
		char* temp;
		temp = new char[strlen(this->str) + strlen(ref.str) + 1];
		strcpy_s(temp, strlen(this->str) + 1, this->str);
		strcat(temp, ref.str);
		String result(temp);
		delete[] temp;
		return result;
	}
	String& operator+=(const String& ref) {
		strcat(this->str, ref.str);
		return *this;
	}
	bool operator==(const String& ref) {
		return strcmp(this->str, ref.str) == 0;
	}
	
	~String() {
		delete[] str;
	}
};
int main(void) {


	return 0;
}