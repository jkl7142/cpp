#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    int a = 100, b;
    cout << "Input number: ";
    cin >> b;

    try
    {
        if (b == 0)
            throw b;
        else
            cout << a / b << endl;
    }
    catch(int nExp)
    {
        cout << "ERROR: " << nExp << "���� ���� �� �����ϴ�." << endl;
    }
    

    return 0;
}