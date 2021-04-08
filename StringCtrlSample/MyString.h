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

    // �迭 ������
    char& operator[](int nIndex);
    char operator[](int nIndex) const;

    int SetString(const char* pszParam);
    const char* GetString() const;
    void Release();

    int GetLength() const;
    int Append(const char * pszParam);

private:
    char* m_pszData;

    int m_nLength;
};