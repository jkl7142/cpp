#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

    char *arr = new char[12];

    for(int i = 0; i < 7; i++) {
        arr[i] = 'a' + i;
    }

    for(int i = 0; i < 7; i++) {
        cout << arr[i] << endl;
    }

    delete[] arr;

    return 0;
}