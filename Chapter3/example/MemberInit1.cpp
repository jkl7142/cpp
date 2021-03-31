#include <iostream>
using namespace std;

// Developer code
class CTest {

public:
    CTest() {   // 생성자
        m_nData = 10;
    }    

    int m_nData;

    void PrintData(void) {
        cout << m_nData << endl;
    }
};

// User code
int main(int argc, char* argv[]) {
    CTest t;
    t.PrintData();

    return 0;
}