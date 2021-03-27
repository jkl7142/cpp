#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char* argv[]) {

    //int *aList = new int[20, 50, 30, 10, 40];
    int aList[5] = {20, 50, 30, 10, 40};

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4 - i; j++) {
            if (aList[j] > aList[j + 1]) {
                Swap(aList[j], aList[j + 1]);
            }
        }
    }

    cout << "int aList[5] = {";
    for(auto n : aList) {
        cout << n;
        if (n != aList[4])
            cout << ", ";
        else
            cout << "};" << endl;
    }

    // delete[] aList;

    return 0;
}