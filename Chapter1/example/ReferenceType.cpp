#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    int nData = 10;

    int &ref = nData;

    ref = 20;
    cout << nData << endl;

    int *pnData = &nData;
    *pnData = 30;
    cout << nData << endl;

    return 0;
}