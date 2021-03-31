#include <iostream>
using namespace std;

// Developer code
class CMyData {
    int m_nData;

public:
    int GetData(void) { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }
};

// User code
int main(int argc, char* argv[]) {
    CMyData data;

    data.SetData(10);
    cout << data.GetData() << endl;

    return 0;
}