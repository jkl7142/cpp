#include <iostream>
using namespace std;

class CRefTest {

public:
    CRefTest(int &rParam) : m_nData(rParam) {
    }

    int GetData(void) { return m_nData; }

private:
    int &m_nData;
};

int main(int argc, char* argv[]) { 
    int a = 10;   
    CRefTest b(a);
    cout << b.GetData() << endl;

    return 0;
}