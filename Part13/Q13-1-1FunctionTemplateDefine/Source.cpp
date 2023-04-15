#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y){}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

template<typename T>
void SwapData(T& d1, T& d2) {
	T temp;
	temp = d1;
	d1 = d2;
	d2 = temp;
}
int main(void) {
	int num1 = 1; int num2 = 3;
	cout << num1 << ' ' << num2 << endl;
	SwapData<int>(num1, num2);
	cout << num1 << ' ' << num2 << endl;

	Point p1(4, 5); Point p2(10, 14);
	p1.ShowPosition();
	p2.ShowPosition();
	SwapData<Point>(p1, p2);
	p1.ShowPosition();
	p2.ShowPosition();
	return 0;
}