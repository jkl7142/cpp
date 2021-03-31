#include <iostream>
using namespace std;

class CMyData {

public:
    CMyData(int nParam) : m_nData(nParam) { }

    CMyData(int x, int y) : m_nData(x + y) { }

    int GetData(void) { return m_nData; }

private:
    int m_nData;
};

int main(int argc, char* argv[]) {

    CMyData a(10);
    CMyData b(3, 4);

    cout << a.GetData() << endl;
    cout << b.GetData() << endl;

    return 0;
}