#include <iostream>
#include "TemplateArray.h"
using namespace std;

template <typename T>
BoundCheckTemplateArray<T>::BoundCheckTemplateArray(int len) : arrlen(len) {
	arr = new T[len];
}
template <typename T>
T& BoundCheckTemplateArray<T>:: operator[] (int idx) {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
T BoundCheckTemplateArray<T>::operator[] (int idx) const {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}
template <typename T>
int BoundCheckTemplateArray<T>::GetArrLen() const { return arrlen; }

template <typename T>
BoundCheckTemplateArray<T>::~BoundCheckTemplateArray() { delete[]arr; }
