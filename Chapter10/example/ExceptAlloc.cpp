#include <new>  // bad_alloc Ŭ���� ���
#include <iostream>
using namespace std;

class CTest {
public:
    CTest(int nSize) {
        m_pszData = new char[nSize];
    }

    ~CTest() {
        delete[] m_pszData;
        cout << "���������� ��ü�� �Ҹ���" << endl;
    }

private:
    char *m_pszData;
};

int main(int argc, char* argv[]) {

    try
    {
        int nSize;
        cout << "Input size: ";

        // ����ڰ� �Է��� ���� ���� ���� �״�� ���
        cin >> nSize;
        CTest a(nSize);
    }
    catch(bad_alloc &exp)
    {
        // �ý����� ���� ������ ����Ѵ�.
        cout << exp.what() << endl;
        cout << "ERROR: CTest()" << endl;
    }
    
    return 0;
}