#include <memory>
#include <iostream>
using namespace std;

class CMyData {
public:
    CMyData() { cout << "CMyData()" << endl; }
    ~CMyData() { cout << "~CMyData()" << endl; }
};

int main(int argc, char* argv[]) {

    cout << "*****Begin*****" << endl;
    {
        // 범위를 벗어나면 객체는 자동으로 소멸
        auto_ptr<CMyData> ptrTest(new CMyData);

        // 배열로 생성하면 3개의 객체가 생성되지만 1개의 객체만 삭제됨
        auto_ptr<CMyData> ptrTest(new CMyData[3]);
    }

    cout << "******End******" << endl;

    return 0;
}