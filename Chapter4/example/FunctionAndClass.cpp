#include <iostream>
using namespace std;

class CTestData {

public:
    CTestData(int nParam) : m_nData(nParam) {
        cout << "CTestData(int)" << endl;
    }

    // CTestData(const CTestData &rhs) = delete;    // user의 복사 생성자 호출 차단
    CTestData(const CTestData &rhs) : m_nData(rhs.m_nData) {
        cout << "CTestData(const CTestData &)" << endl;
    }

    int GetData() const { return m_nData; }

    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData = 0;
};

void TestFunc(CTestData &param) {
    cout << "TestFunc()" << endl;

    param.SetData(20);
}

int main(int argc, char* argv[]) {

    cout << "*****Begin*****" << endl;
    CTestData a(10);
    TestFunc(a);

    cout << "a: " << a.GetData() << endl;

    cout << "******End******" << endl;

    return 0;
}