#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    int a = 100, b;
    cout << "Input number: ";
    cin >> b;

    if (b > 0)
        cout << a / b << endl;

    else
        cout << "ERROR: 0���� ���� �� �����ϴ�." << endl;

    return 0;
}