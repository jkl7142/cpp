#include <iostream>
using namespace std;

class CTest {
    int m_nData;

public:
    CTest() {
        cout << "CTest::CTest()" << endl;
    }

    ~CTest() {
        cout << "~CTest::CTest()" << endl;
    }
};

int main(int argc, char* argv[]) {
    cout << "Begin" << endl;

    //CTest *pData = new CTest();
    CTest *pData = new CTest[3];
    cout << "Test" << endl;

    //delete pData;
    delete[] pData;
    cout << "End" << endl;

    return 0;
}