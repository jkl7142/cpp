#include <iostream>
using namespace std;

class CTest {

public:
    CTest(int nParam) : m_nData(nParam) { };
    ~CTest() { }

    int GetData() const {
        m_nData = 20;
        return m_nData;
    }

    int SetData(int nParam) { m_nData = nParam; }

private:
    mutable int m_nData = 0;
};

int main(int argc, char* argv[]) {
    CTest a(10);
    cout << a.GetData() << endl;

    return 0;
}