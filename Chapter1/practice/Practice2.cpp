#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

    //auto 예약어는 인스턴스의 형식을 자동으로 결정하여 선언해준다.

    int a = 10;
    auto b(a);

    cout << a + b << endl;

    return 0;
}