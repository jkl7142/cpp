#include <iostream>
using namespace std;

void TestFunc(int &rParam) {
    rParam = 100;
}

int main(int argc, char* argv[]) {

    int nData = 0;

    TestFunc(nData);
    cout << nData << endl;

    return 0;
}