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

// CTest a;  전역 변수로 선언한 클래스의 생성자는 main() 함수보다 먼저 호출됨

int main(int argc, char* argv[]) { 
    cout << "Begin" << endl;
    CTest a;
    cout << "End" << endl;

    return 0;
}