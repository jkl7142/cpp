#include <iostream>
using namespace std;

class CMyInterface {
public:
    CMyInterface() {
        cout << "CMyInterface()" << endl;
    }

    virtual int GetData() const = 0;
    virtual void SetData(int nParam) = 0;
};

class CMyData : public CMyInterface {
public:
    CMyData() { cout << "CMyData()" << endl; }

    virtual int GetData() const { return m_nData; }
    virtual void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData = 0;
};

int main(int argc, char* argv[]) {
    
    // 순수 가상 클래스는 인스턴스 선언 및 정의가 불가능
    // CMyInterface a;
    CMyData a;
    a.SetData(5);
    cout << a.GetData() << endl;

    return 0;
}