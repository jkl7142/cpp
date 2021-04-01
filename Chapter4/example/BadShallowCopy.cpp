#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    int *pA, *pB;

    pA = new int;
    *pA = 10;

    pB = new int;
    // pB = pA; 같은 인스턴스를 가리킴
    *pB = *pA;

    cout << *pA << endl;
    cout << *pB << endl;

    delete pA;
    delete pB;

    return 0;
}