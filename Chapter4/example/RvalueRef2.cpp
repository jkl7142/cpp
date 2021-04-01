#include <iostream>
using namespace std;

void TestFunc(int &rParam) {
    cout << "TestFunc(int &)" << endl;
}

void TestFunc(int &&rParam) {
    cout << "TestFunc(int &&)" << endl;
}

int main(int argc, char* argv[]) {
    TestFunc(3 + 4);

    return 0;
}