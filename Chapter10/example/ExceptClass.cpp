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
        cout << "���� ������ �Է��ϼ���.: ";
        cin >> nInput;

        if (nInput < 0) {
            CMyException exp(10, "���� ������ �Է��ؾ� �մϴ�.");
            throw exp;
        }
    }
    catch(CMyException &exp)
    {
        cout << "ERROR CODE [" << exp.GetErrorCode() << "] " << exp.GetMessage() << endl;
    }

    return 0;
}