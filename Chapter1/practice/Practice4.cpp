#include <iostream>
#include <string>
using namespace std;

void Swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char* argv[]) {

    int a = 10;
    int b = 20;

    Swap(a, b);

    cout << a << " " << b << endl;

    return 0;
}