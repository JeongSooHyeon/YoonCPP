#include <iostream>
#include <cstring>
using namespace std;

class BoundCheckIntArray {
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& ref) {}
	BoundCheckIntArray& operator=(const BoundCheckIntArray& ref) {}
public:
	BoundCheckIntArray(int len = 0) : arrlen(len) {
		arr = new int[len];
	}
	int& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Out of range";
			exit(1);
		}
		return arr[idx];
	}
	int operator[](int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Out of range";
			exit(1);
		}
		return arr[idx];
	}
	~BoundCheckIntArray() {
		delete[] arr;
	}
};

typedef BoundCheckIntArray* INT_PTR;

class BoundCheck2DIntArray {
private:
	INT_PTR* arr;
	int arrlen;
	BoundCheck2DIntArray(const BoundCheck2DIntArray& ref) {}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& ref) {}
public:
	BoundCheck2DIntArray(int row, int col) : arrlen(row) {
		arr = new INT_PTR[row];
		for (int i = 0; i < row; i++)
			arr[i] = new BoundCheckIntArray(col);
	}
	BoundCheckIntArray& operator[] (int row) {
		if (row < 0 || row >= arrlen) {
			cout << "Out of range";
			exit(1);
		}
		return *(arr[row]);
	}
	~BoundCheck2DIntArray() {
		for (int i = 0; i < arrlen; i++)
			delete arr[i];
		delete[]arr;
	}
};