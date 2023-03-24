#include <iostream>
using namespace std;

class Rectangle {
private:
	int length1, length2;
public:
	Rectangle(int a, int b) : length1(a), length2(b) {

	}
	int RectArea() {
		return length1 * length2;
	}
	void ShowAreaInfo() {
		cout << "¸éÀû: " << RectArea() << endl;
	}
};

class Square : public Rectangle {
public:
	Square(int a) : Rectangle(a, a) {

	}
	

};
int main() {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();



	return 0;
}