#include "stdafx.h"
#include "MyString.h"

CMyString::CMyString() : m_pszData(NULL), m_nLength(0) { }
CMyString::~CMyString() {
    Release();
}

// ���� ������
CMyString::CMyString(const CMyString &rhs) : m_pszData(NULL), m_nLength(0) {
    this->SetString(rhs.GetString());
}

// ��� & ���� ������
CMyString& CMyString::operator=(const CMyString &rhs) {
    if (this != &rhs) this->SetString(rhs.GetString());

    return *this;
}

CMyString CMyString::operator+(const CMyString &rhs) {
    CMyString strResult(m_pszData);
    strResult.Append(rhs.GetString());

    return strResult;
}

CMyString& CMyString::operator+=(const CMyString &rhs) {
    Append(rhs.GetString());

    return *this;
}

// �迭 ������
char& CMyString::operator[](int nIndex) {
    return m_pszData[nIndex];
}

char CMyString::operator[](int nIndex) const {
    return m_pszData[nIndex];
}

// ���� ������
int CMyString::operator==(const CMyString &rhs) {
    if (m_pszData != NULL && rhs.m_pszData != NULL) {
        if (strcmp(m_pszData, rhs.m_pszData) == 0) {
            return 1;
        }
    }

    return 0;
}

int CMyString::operator!=(const CMyString &rhs) {
    if (m_pszData != NULL && rhs.m_pszData != NULL) {
        if (strcmp(m_pszData, rhs.m_pszData) == 0) {
            return 0;
        }
    }

    return 1;
}

// ��ȯ ������
CMyString::CMyString(const char *pszParam) : m_pszData(NULL), m_nLength(0) {
    SetString(pszParam);
}

// �̵� ������
CMyString::CMyString(CMyString &&rhs) : m_pszData(NULL), m_nLength(0) {
    cout << "CMyString �̵� ������ ȣ��" << endl;

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

    // �̷��� ȣ��
    OnSetString(m_pszData, m_nLength);

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

int CMyString::GetLength() const {
    return m_nLength;
}

int CMyString::Append(const char * pszParam) {
    if (pszParam == NULL || strlen(pszParam) == 0) {
        return 0;
    }

    int nLenParam = strlen(pszParam);

    if (m_pszData == NULL) {
        SetString(pszParam);

        return m_nLength;
    }

    int nLenCur = m_nLength;

    char *pszResult = new char[nLenCur + nLenParam + 1];

    strncpy(pszResult, m_pszData, sizeof(char) * (nLenCur + 1));
    strncpy(pszResult + (sizeof(char) * nLenCur), pszParam, sizeof(char) * (nLenParam + 1));

    Release();
    m_pszData = pszResult;
    m_nLength = nLenCur + nLenParam;

    return m_nLength;
}

void CMyString::OnSetString(char * pszData, int nLength) {
    
}