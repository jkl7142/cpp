#include <iostream>
using namespace std;

// 함수 객체 클래스 선언 및 정의
class Add {
public:
    // 함수 호출 연산자 다중 정의
    int operator()(int a, int b) {
        cout << "()(int, int)" << endl;

        return a + b;
    }

    double operator()(double a, double b) {
        cout << "()(double, double)" << endl;

        return a + b;
    }
};

void TestFunc(Add &add) {
    cout << add(3, 4) << endl;
}

int main(int argc, char* argv[]) {
    Add adder;

    // 함수 객체로 호출한다.
    cout << adder(3, 4) << endl;
    cout << adder(3.3, 4.4) << endl;

    TestFunc(adder);

    return 0;
}