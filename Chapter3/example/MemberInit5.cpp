#include <iostream>
using namespace std;

// Developer code
class CTest {

public:
    CTest() { }

     int m_nData1 = 10;
     int m_nData2 = 20;

     void PrintData(void) {
         cout << m_nData1 << endl;
         cout << m_nData2 << endl;
     }
};

// User code
int main(int argc, char* argv[]) {
    CTest t;
    t.PrintData();

    return 0;
}