#pragma once

class CMyString {
public:
    CMyString();
    ~CMyString();

    // ���� ������
    CMyString(const CMyString &rhs);

    // ��ȯ ������
    explicit CMyString(const char *pszParam);

    operator char*() const {
        return m_pszData;
    }

    // �̵� ������
    CMyString(CMyString &&rhs);

    // ���, ���� ������
    CMyString& operator=(const CMyString &rhs);
    CMyString operator+(const CMyString &rhs);
    CMyString& operator+=(const CMyString &rhs);
    friend CMyString operator+(const char *pszParam, const CMyString &strParam);

    // �迭 ������
    char& operator[](int nIndex);
    char operator[](int nIndex) const;

    // ���� ������
    int operator==(const CMyString &rhs);
    int operator!=(const CMyString &rhs);

    int SetString(const char* pszParam);
    const char* GetString() const;
    void Release();

    int GetLength() const;
    int Append(const char * pszParam);

    virtual void OnSetString(char * pszData, int nLength);

private:
    char* m_pszData;

    int m_nLength;
};