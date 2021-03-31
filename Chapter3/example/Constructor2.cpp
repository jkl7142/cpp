#include <iostream>
using namespace std;

class CTest {
    int m_nData;

public:
    CTest(int nParam) : m_nData(nParam) {
        cout << "CTest::CTest()" << endl;
    }

    ~CTest() {
        cout << "~CTest::CTest() " << m_nData << endl;
    }
};

int main(int argc, char* argv[]) {
    cout << "Begin" << endl;
    CTest a(1);
    cout << "Before b" << endl;
    CTest b(2);
    cout << "End" << endl;

    return 0;
}