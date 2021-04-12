#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int nData = 10;
    cout << nData << endl;
    auto TestFunc = [nData](void) mutable -> void {
        cout << ++nData << endl;
    };

    TestFunc();
    cout << nData << endl;

    return 0;
}