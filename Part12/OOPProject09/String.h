#pragma once
#ifndef __STRING_H__
#define __STRING_H__
// 배고프노
#include "BankingCommonDecl.h"

class String {
private:
	int len;
	char* str;
public:
	String();
	String(const char* str);
	String(const String& copy);
	String& operator=(const String& copy);
	String operator+(const String& ref);
	String& operator+=(const String& ref);
	bool operator==(const String& ref);
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
	~String();
};
#endif