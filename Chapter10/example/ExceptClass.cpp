#include <iostream>
#include <string.h>
using namespace std;

class CMyException {
public:
    CMyException(int nCode, const char *pszMsg) {
        m_nErrorCode = nCode;
        strncpy(m_szMsg, pszMsg, sizeof(m_szMsg));
    }

    int GetErrorCode() const { return m_nErrorCode; }
    const char* GetMessage() const { return m_szMsg; }

private:
    int m_nErrorCode;
    char m_szMsg[128];
};

int main(int argc, char* argv[]) {

    try
    {
        int nInput = 0;
        cout << "양의 정수를 입력하세요.: ";
        cin >> nInput;

        if (nInput < 0) {
            CMyException exp(10, "양의 정수를 입력해야 합니다.");
            throw exp;
        }
    }
    catch(CMyException &exp)
    {
        cout << "ERROR CODE [" << exp.GetErrorCode() << "] " << exp.GetMessage() << endl;
    }

    return 0;
}