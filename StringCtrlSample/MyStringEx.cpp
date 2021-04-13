#include "stdafx.h"
#include "MyStringEx.h"

CMyStringEx::CMyStringEx() { }
CMyStringEx::~CMyStringEx() { }

int CMyStringEx::Find(const char * pszParam) {
    if (pszParam == NULL || GetString() == NULL) {
        return -1;
    }

    const char *pszResult = strstr(GetString(), pszParam);

    //cout << (int)GetString() << endl; // 15367928
    //cout << (int)pszResult << endl;   // 15367930

    if (pszResult != NULL) {
        return pszResult - GetString(); // �ּҰ� : 15367930 - 15367928
    }

    return -1;
};