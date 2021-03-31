#include <iostream>
using namespace std;

// Developer code
class CTest {

public:
    CTest() {
        cout << "CTest() : 생성자 함수" << endl;
        m_nData = 10;
    }

    int m_nData;

    void PrintData(void) {
        cout << m_nData << endl;
    }
};

// User code
int main(int argc, char* argv[]) {
    cout << "main() 함수 시작" << endl;

    CTest t;
    t.PrintData();

    cout << "main() 함수 끝" << endl;

    return 0;
}