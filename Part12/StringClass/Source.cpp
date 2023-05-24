#include <iostream>
#include <cstring>
using namespace std;
// 배고프노

class String {
private:
	int len;
	char* str;
public:
	String() : len(0) {
		str = NULL;
	}
	String(const char* str) : len(strlen(str)+1) {
		this->str = new char[len];
		strcpy_s(this->str, len, str);
	}
	String(const String& copy) : len(copy.len) {
		str = new char[len];
		strcpy_s(str, len, copy.str);
	}
	String& operator=(const String& copy) {
		if(str!=NULL)
			delete[] str;
		len = copy.len;
		str = new char[len];
		strcpy_s(str, len, copy.str);

		return *this;
	}
	String operator+(const String& ref) {
		char* temp = new char[this->len + ref.len - 1];
		strcpy_s(temp, this->len + ref.len - 1, this->str);
		strcat_s(temp, this->len + ref.len - 1, ref.str);

		String result(temp);
		delete[] temp;
		return result;
	}
	String& operator+=(const String& ref) {
		len += (ref.len - 1);
		char* temp = new char[len];
		strcpy_s(temp, len, str);
		strcat_s(temp, len, ref.str);

		if (str != NULL)
			delete[] str;
		str = temp; // 대입 연산자 오버로딩 했음
		return *this;
	}
	bool operator==(const String& ref) {
		return strcmp(this->str, ref.str) ? false : true; // -1, 0, 1
	}
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);

	~String() {
		if(str!=NULL)
			delete[] str;
	}
};
ostream& operator<<(ostream& os, const String& s) {
	os << s.str;
	return os;
}
istream& operator>>(istream& is, String& s) {
	char temp[100];
	is >> temp;
	s = String(temp);
	
	return is;
}

int main(void) {
	String str1 = "I like ";
	String str2 = "String class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;

	return 0;
}