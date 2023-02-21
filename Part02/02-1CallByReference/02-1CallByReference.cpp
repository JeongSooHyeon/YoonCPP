#include <iostream>
using namespace std;


// 문제1
void func1(int& num) {
    num++;
}

void func2(int& num) {
    num *= -1;
}

// 문제2
void SwapPointer(int* (&ptr1), int* (&ptr2)) {
    int* temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}
int main()
{
    // 문제1
    /*int num = -4;
    cout << num << endl;

    func1(num);
    cout << num << endl;

    func2(num);
    cout << num << endl;*/

    // 문제3
    int num1 = 5;
    int* ptr1 = &num1;
    int num2 = 10;
    int* ptr2 = &num2;
    
    cout << *ptr1 << ' ' << *ptr2 << endl;
    SwapPointer(ptr1, ptr2);
    cout << *ptr1 << ' ' << *ptr2 << endl;
}
