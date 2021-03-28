#include <iostream>
using namespace std;

void TestFunc(int a) {
    cout << "TestFunc(int)" << endl;
}

void TestFunc(int a, int b = 10) {
    cout << "TestFunc(int, int)" << endl;
}

//  TestFunc(value) 처럼 인스턴스 1개로 호출이 될 경우 모호하다.

int main(void) {
    return 0;
}