#include <iostream>
using namespace std;

class CTest {

public:
    CTest(int nParam) : m_nData(nParam) { };
    ~CTest() { }

    int GetData() const {

        // SetData(20); const�� ���� ��ȯ �Ұ���
        // m_nData = 20; ���������� �Ұ���

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