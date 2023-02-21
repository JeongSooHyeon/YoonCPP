#include <iostream>
#include <cstring>

#include <ctime> // time
#include <cstdlib> // rand, srand

using namespace std;

int main()
{
    // 문제1
    /*char str1[100];
    char* str = "fuckfuck";
    char str2[] = "Hi";
    
    strcpy_s(str1, str2);
    cout << strlen(str1) << endl;

    cout << strcmp(str1, str2) << endl;

    strcat_s(str1, "hello");
    cout << str1 << endl;


    cout << strcmp(str1, str2) << endl;*/

    // 문제2
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        cout << (rand() % 100) + 1 << endl;

    }

    return 0;
}