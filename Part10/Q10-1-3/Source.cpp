#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend Point operator+(const Point& pos1, const Point& pos2);
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);

};

Point operator+(const Point& pos1, const Point& pos2) {
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

bool operator==(const Point& pos1, const Point& pos2) {
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	return false;
}
bool operator!=(const Point& pos1, const Point& pos2) {
	return !(pos1 == pos2);
}

int main(void) {
	Point pos1(3, 4);
	Point pos2(3, 4);
	Point pos3(4, 1);

	if (pos1 == pos2)
		cout << "같습니다" << endl;
	else
		cout << "다릅니다" << endl;

	if(pos2 != pos3)
		cout << "다릅니다" << endl;
	else
		cout << "같습니다" << endl;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}