#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;

public:
	/*void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}*/
	Point(int x, int y): xpos(x), ypos(y){}
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point centerPosition; // 원의 중심좌표
	int radius; // 반지름

public:
	/*void Init(int x, int y, int r) {
		centerPosition.Init(x, y);
		radius = r;
	}*/
	Circle(int x, int y, int r): centerPosition(x,y), radius(r){}
	int getRadius() const{
		return radius;
	}
	void ShowCircleInfo() const{
		cout << "radius: " << getRadius() << endl;
		centerPosition.ShowPointInfo();
	}
};

class Ring {
private:
	Circle inC;
	Circle outC;

public:
	Ring(int inX, int inY, int inR, int outX, int outY, int outR): inC(inX, inY, inR), outC(outX, outY, outR)
	{
		
	}
	void ShowRingInfo()
	{
		cout << "Inner Circle Info..." << endl;
		inC.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outC.ShowCircleInfo();
	}
};

int main(void) {
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}