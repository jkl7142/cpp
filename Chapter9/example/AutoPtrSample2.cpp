#include <memory>
#include <iostream>
using namespace std;

class CMyData {
public:
    CMyData() { cout << "CMyData()" << endl; }
    ~CMyData() { cout << "~CMyData()" << endl; }
    void TestFunc() { cout << "CMyData::TestFunc()" << endl; }
};

int main(int argc, char* argv[]) {

    auto_ptr<CMyData> ptrTest(new CMyData);
    auto_ptr<CMyData> ptrNew;

    cout << "0x" << ptrTest.get() << endl;

    // 포인터를 대입하면 원본 포인터는 NULL이 된다.
    ptrNew = ptrTest;
    cout << "0x" << ptrTest.get() << endl;

    ptrTest->TestFunc();

    return 0;
}