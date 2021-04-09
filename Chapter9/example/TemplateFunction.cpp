#include <memory>
#include <string.h>
#include <iostream>
using namespace std;

template<typename T>
T Add(T a, T b) { return a + b; }

template< >
char* Add(char *pszLeft, char *pszRight) {
    int nLenLeft = strlen(pszLeft);
    int nLenRight = strlen(pszRight);
    char *pszResult = new char[nLenLeft + nLenRight + 1];

    strncpy(pszResult, pszLeft, nLenLeft + 1);
    strncpy(pszResult + nLenLeft, pszRight, nLenRight + 1);

    return pszResult;
}

int main(int argc, char* argv[]) {

    int nResult = Add<int>(3, 4);
    cout << nResult << endl;

    char *pszResult = Add<char*>("Hello", "World");
    cout << pszResult << endl;
    delete[] pszResult;

    return 0;
}