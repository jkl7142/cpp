#include <iostream>
using namespace std;

class CTest {

public:
    CTest() {
        cout << "CTest::CTest()" << endl;
    }

    ~CTest() {
        cout << "~CTest::CTest()" << endl;
    }
};

// CTest a;  ���� ������ ������ Ŭ������ �����ڴ� main() �Լ����� ���� ȣ���

int main(int argc, char* argv[]) { 
    cout << "Begin" << endl;
    CTest a;
    cout << "End" << endl;

    return 0;
}