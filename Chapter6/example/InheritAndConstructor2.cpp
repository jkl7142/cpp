#include <iostream>
using namespace std;

class CMyDataA {
    public:
        CMyDataA() {
            cout << "CMyDataA()" << endl;
            m_pszData = new char[32];
        }

        ~CMyDataA() {
            cout << "~CMyDataA()" << endl;
            delete m_pszData;
        }

    protected:
        char *m_pszData;
};

class CMyDataB : public CMyDataA {
    public:
        CMyDataB() {
            cout << "CMyDataB()" << endl;
        }

        ~CMyDataB() {
            cout << "~CMyDataA()" << endl;
        }
};

class CMyDataC : public CMyDataB {
    public:
        CMyDataC() {
            cout << "CMyDataC()" << endl;
        }

        ~CMyDataC() {
            cout << "~CMyDataC()" << endl;
            delete m_pszData;   // 논리적 오류
        }
};