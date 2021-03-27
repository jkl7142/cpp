#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
    int nTmp = a;
    a = b;
    b = nTmp;
}

int main(int argc, char* argv[]) {
    int x = 10, y = 20;

    Swap(x, y);

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    return 0;
}