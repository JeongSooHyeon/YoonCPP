#include <iostream>
#include "TemplateArray.cpp"
#include "PointClass.h"
using namespace std;

int main(void) {
	BoundCheckTemplateArray<int> intArray(5);
	for (int i = 0; i < intArray.GetArrLen(); i++) {
		intArray[i] = i * 10;
		cout << intArray[i] << ' ';
	}
	cout << endl << endl;
	
	BoundCheckTemplateArray<Point> pointArray(5);
	for (int i = 0; i < pointArray.GetArrLen(); i++) {
		pointArray[i] = Point(i+1, i*3);
		cout << pointArray[i] << ' ';
	}
	cout << endl << endl;

	typedef Point* POINT_PTR;
	BoundCheckTemplateArray<POINT_PTR> pointPtrArray(5);
	for (int i = 0; i < pointPtrArray.GetArrLen(); i++) {
		pointPtrArray[i] = new Point(i * 2, i * 3 - 10);
		cout << *(pointPtrArray[i]);
	}
	cout << endl << endl;

	for (int i = 0; i < pointPtrArray.GetArrLen(); i++) {
		delete pointPtrArray[i];
	}
}