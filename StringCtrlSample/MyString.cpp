#include "stdafx.h"
#include "MyString.h"

CMyString::CMyString() : m_pszData(NULL), m_nLength(0) { }
CMyString::~CMyString() {
    Release();
}

// 복사 생성자
CMyString::CMyString(const CMyString &rhs) : m_pszData(NULL), m_nLength(0) {
    this->SetString(rhs.GetString());
}

CMyString& CMyString::operator=(const CMyString &rhs) {
    if (this != &rhs) this->SetString(rhs.GetString());

    return *this;
}

// 변환 생성자
CMyString::CMyString(const char *pszParam) : m_pszData(NULL), m_nLength(0) {
    SetString(pszParam);
}

// 이동 생성자
CMyString::CMyString(CMyString &&rhs) : m_pszData(NULL), m_nLength(0) {
    cout << "CMyString 이동 생성자 호출" << endl;

    m_pszData = rhs.m_pszData;
    m_nLength = rhs.m_nLength;

    rhs.m_pszData = NULL;
    rhs.m_nLength = 0;
}

int CMyString::SetString(const char* pszParam) {
    Release();

    if (pszParam == NULL || strlen(pszParam) == 0) return 0;

    int nLength = strlen(pszParam);

    m_pszData = new char[nLength + 1];

    strncpy(m_pszData, pszParam, sizeof(char)* (nLength + 1));
    m_nLength = nLength;

    return nLength;
}

const char* CMyString::GetString() const {
    return m_pszData;
}

void CMyString::Release() {
    if(m_pszData != NULL) delete[] m_pszData;

    m_pszData = NULL;
    m_nLength = 0;
}