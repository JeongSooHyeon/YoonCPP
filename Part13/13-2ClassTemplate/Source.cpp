#include <iostream>
using namespace std;

template <typename T>
class BoundCheckTemplateArray {
private:
	T* arr;
	int arrlen;
	BoundCheckTemplateArray(const BoundCheckTemplateArray& arr){}
	BoundCheckTemplateArray& operator=(const BoundCheckTemplateArray& arr){}

public:
	BoundCheckTemplateArray(int len) : arrlen(len) {
		arr = new T[len];
	}
	T& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	T operator[] (int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckTemplateArray() { delete[]arr; }
};

int main(void) {
	
}