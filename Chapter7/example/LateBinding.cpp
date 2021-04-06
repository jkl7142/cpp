#include <iostream>
using namespace std;

void TestFunc1(int nParam) { }
void TestFunc2(int nParam) { }

int main(int argc, char* argv[]) {
    int nInput = 0;
    cin >> nInput;
    void(*pfTest)(int) = NULL;

    if(nInput > 10) pfTest = TestFunc1;
    else pfTest = TestFunc2;

    pfTest(10);

    return 0;
}