#include "stdafx.h"
#include "UserData.h"

int CUserData::nUserDataCounter = 0;

CUserData::CUserData(void) {
    memset(szName, 0, sizeof(szName));
    memset(szPhone, 0, sizeof(szPhone));

    nUserDataCounter++;
}

CUserData::CUserData(const char* pszName, const char* pszPhone) {
    memset(szName, 0, sizeof(szName));
    memset(szPhone, 0, sizeof(szPhone));

    strncpy(szName, pszName, sizeof(szName));
    strncpy(szPhone, pszPhone, sizeof(szPhone));

    nUserDataCounter++;
}

CUserData::~CUserData() {
    nUserDataCounter--;
}

const char* CUserData::GetKey(void) {
    return szName;
}

void CUserData::PrintNode(void) {
    #ifdef _DEBUG
        cout << "[" << this << "] " <<
        szName << "\t" << szPhone << " [" <<
        GetNext() << "]" << endl;
    #else
        cout << szName << "\t" << szPhone << endl;
    #endif
}