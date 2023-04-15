#include "String.h"
// 배고프노

String::String() : len(0) {
	str = NULL;
}
String::String(const char* str) : len(strlen(str) + 1) {
	this->str = new char[len];
	strcpy_s(this->str, len, str);
}
String::String(const String& copy) : len(copy.len) {
	str = new char[len];
	strcpy_s(str, len, copy.str);
}
String& String::operator=(const String& copy) {
	if (str != NULL)
		delete[] str;
	len = copy.len;
	str = new char[len];
	strcpy_s(str, len, copy.str);

	return *this;
}
String String::operator+(const String& ref) {
	char* temp = new char[this->len + ref.len - 1];
	strcpy_s(temp, this->len + ref.len - 1, this->str);
	strcat_s(temp, this->len + ref.len - 1, ref.str);

	String result(temp);
	delete[] temp;
	return result;
}
String& String::operator+=(const String& ref) {
	len += (ref.len - 1);
	char* temp = new char[len];
	strcpy_s(temp, len, str);
	strcat_s(temp, len, ref.str);

	if (str != NULL)
		delete[] str;
	str = temp; // 대입 연산자 오버로딩 했음
	return *this;
}
bool String::operator==(const String& ref) {
	return strcmp(this->str, ref.str) ? false : true; // -1
}
String::~String() {
	if (str != NULL)
		delete[] str;
}

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