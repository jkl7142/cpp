#include <iostream>
using namespace std;

class CTest {

public:
    CTest(int nParam) : m_nData(nParam) { };
    ~CTest() { }

    int GetData() const {

        // SetData(20); const에 의해 변환 불가능
        // m_nData = 20; 마찬가지로 불가능

        return m_nData;
    }

    int SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData = 0;
};

int main(int argc, char* argv[]) {
    CTest a(10);
    cout << a.GetData() << endl;

    return 0;
}