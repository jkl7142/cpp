#include <iostream>
using namespace std;

// Developer code
class CTest {

public:
    CTest() {
        cout << "CTest() : ������ �Լ�" << endl;
        m_nData = 10;
    }

    int m_nData;

    void PrintData(void) {
        cout << m_nData << endl;
    }
};

// User code
int main(int argc, char* argv[]) {
    cout << "main() �Լ� ����" << endl;

    CTest t;
    t.PrintData();

    cout << "main() �Լ� ��" << endl;

    return 0;
}