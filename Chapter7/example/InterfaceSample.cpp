#include <iostream>
using namespace std;

class CMyObject {
public:
    CMyObject() { }
    virtual ~CMyObject() { }

    virtual int GetDeviceID() = 0;

protected:
    int m_nDeviceID;
};

void PrintID(CMyObject *pObj) {
    cout << "Device ID: " << pObj->GetDeviceID() << endl;
}

class CMyTV : public CMyObject {
public:
    CMyTV(int nID) { m_nDeviceID = nID; }
    virtual int GetDeviceID() {
        cout << "CMyTv::GetDeviceID()" << endl;
        return m_nDeviceID;
    }
};

class CMyPhone : public CMyObject {
public:
    CMyPhone(int nID) { m_nDeviceID = nID; }
    virtual int GetDeviceID() {
        cout << "CMyPhone::GetDeviceID()" << endl;
        return m_nDeviceID;
    }
};

int main(int argc, char* argv[]) {
    CMyTV a(5);
    CMyPhone b(10);

    ::PrintID(&a);
    ::PrintID(&b);

    return 0;
}