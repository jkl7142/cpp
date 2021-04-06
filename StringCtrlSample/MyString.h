#pragma once

class CMyString {
public:
    CMyString();
    ~CMyString();

    // 복사 생성자
    CMyString(const CMyString &rhs);

    CMyString& operator=(const CMyString &rhs);

    int SetString(const char* pszParam);
    const char* GetString() const;
    void Release();

private:
    char* m_pszData;

    int m_nLength;
};