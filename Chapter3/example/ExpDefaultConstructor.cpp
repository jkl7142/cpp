#include <iostream>
using namespace std;

class CTest {

public:
    CTest(void);
    // CTest(void) = default;   // 디폴트 생성자 선언 및 정의
    // CTest(void) = delete;    // 디폴트 생성자 삭제
    int m_nData = 5;
};

CTest::CTest(void) { }

int main(int argc, char* argv[]) {
    CTest a;
    cout << a.m_nData << endl;

    return 0;
}