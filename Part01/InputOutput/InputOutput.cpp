#include <iostream>

int main()
{
    // 문제4
    //int a = 1;
    //int salary;

    //while (true) {
    //    std::cout << "판매 금액을 만원 단위로 입력(-1 to end) : ";
    //    std::cin >> a;
    //    if (a != -1) {
    //        salary = (int)(50 + a * 0.12);
    //        std::cout << "이번 달 급여 : " << salary << "만원" << std::endl;
    //    }
    //    else
    //    {
    //        std::cout << "프로그램을 종료합니다.";
    //        break;
    //    }
    //}

    // 문제3
    /*int a;
    std::cin >> a;
    for (int i = 0; i < 9; i++) {
        std::cout << a << " x " << i + 1 << " = " << a * (i + 1) << std::endl;
    }*/

    // 문제2
    char name[100];
    char phonenumber[100];

    std::cin >> name >> phonenumber;
    std::cout << name << ' ' << phonenumber;

    // 문제1
    //int a;
    //int result = 0;

    //for (int i = 0; i < 5; i++) {
    //    std::cout << i+1 << "번째 정수 입력 : ";
    //    std::cin >> a;
    //    result += a;
    //}
    //std::cout << "합계 : " << result;
}
