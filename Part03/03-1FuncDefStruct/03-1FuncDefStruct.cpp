#include <iostream>
using namespace std;

void Cooking(int hour, int minute, int time) {
    int remainTime;
    hour += (minute + time) / 60;
    minute = (minute + time) % 60;

    cout << hour << ' ' << minute << endl;
}

int main(void)
{
    cout << "현재 시각 입력 : ";

    int hour, minute;
    int cookTime;

    cin >> hour >> minute;
    cin >> cookTime;

    Cooking(hour, minute, cookTime);

    return 0;
}