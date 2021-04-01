#include <iostream>
using namespace std;

class CMyData {

public:
    CMyData() { cout << "CMyData()" << endl; }

    int GetData(void) { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData = 0;
};

int main(int argc, char* argv[]) {

    CMyData a;
    a.SetData(10);

    CMyData b(a);
    cout << b.GetData() << endl;

    return 0;
}