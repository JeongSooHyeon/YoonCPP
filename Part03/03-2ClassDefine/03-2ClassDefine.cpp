#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// ¹®Á¦2
class Printer {
private:
	char str[30];

public:
	void SetString(const char* s);
	void ShowString();
};

void Printer::SetString(const char* s) {
	strcpy_s(str, 30, s);
}

void Printer::ShowString() {
	cout << str << endl;
}

int main(void) {
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}
// ¹®Á¦1
//class Calculator {
//private:
//	int cntAdd;
//	int cntDiv;
//	int cntMin;
//
//public:
//	void Init();
//	double Add(double n1, double n2);
//	double Div(double n1, double n2);
//	double Min(double n1, double n2);
//	void ShowOpCount();
//};
//void Calculator::Init() {
//	cntAdd = 0;
//	cntDiv = 0;
//	cntMin = 0;
//}
//double Calculator::Add(double n1, double n2) {
//	cntAdd++;
//	return n1 + n2;
//}
//
//double Calculator::Div(double n1, double n2) {
//	cntDiv++;
//	return n1 / n2;
//}
//
//double Calculator::Min(double n1, double n2) {
//	cntMin++;
//	return n1 - n2;
//}
//
//void Calculator::ShowOpCount() {
//	cout << "µ¡¼À: " << cntAdd << " »¬¼À: " << cntMin << " ³ª´°¼À: " << cntDiv << endl;
//}
//int main()
//{
//	Calculator cal;
//	cal.Init();
//	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
//	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
//	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
//	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
//	cal.ShowOpCount();
//
//	return 0;
//}
