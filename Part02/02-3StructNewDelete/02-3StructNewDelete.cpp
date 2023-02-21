#include <iostream>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2);

int main()
{
	Point* point1 = new Point;
	point1->xpos = 5;
	point1->ypos = 10;

	Point* point2 = new Point;;
	point2->xpos = 2;
	point2->ypos = 3;

	Point& point3 = PntAdder(*point1, *point2); // 왜 이러는진 모르겠노
	cout << point3.xpos << ' ' << point3.ypos << endl;

	delete point1;
	delete point2;
	delete &point3; // ???????????

	return 0;
}


Point& PntAdder(const Point& p1, const Point& p2) {
	Point* result = new Point;
	(*result).xpos = p1.xpos + p2.xpos;
	(*result).ypos = p1.ypos + p2.ypos;

	return *result;
}