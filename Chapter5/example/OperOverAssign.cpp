#include <iostream>
using namespace std;

class CMyData {

public:
    explicit CMyData(int nParam) {
        m_pnData = new int(nParam);
    }

    ~CMyData() { delete m_pnData; }

    operator int() { return *m_pnData; }

    CMyData& operator=(const CMyData &rhs) {    // ��ȯ ������ �����ڷ� ������ a = b = c �ذ�
        if(this == &rhs) {  // a = a �ذ�
            return *this;
        }

        delete m_pnData;

        //m_pnData = new int;
        //*m_pnData = *rhs.m_pnData;
        m_pnData = new int(*rhs.m_pnData);

        return *this;
    }

private:
    int *m_pnData = nullptr;
};

int main(int argc, char* argv[]) {

    CMyData a(0), b(5), c(10);

    // a = a; ���� ���� : �����͸� �����ϱ� ���� ������ ����
    // a = b = c;
    a = b;
    cout << a << endl;

    return 0;
}