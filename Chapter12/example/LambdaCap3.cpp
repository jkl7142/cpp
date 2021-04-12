#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    int x = 10, y = 20;

    //auto TestFunc = [x, y]() -> int {
    auto TestFunc = [=]() -> int {
        return x + y;
    };

    cout << TestFunc() << endl;

    auto TestFunc2 = [&]() -> int {
        return ++x + ++y;
    };

    cout << TestFunc2() << endl;

    // [&, z] { };
    // [=, &z] { };

    return 0;
}