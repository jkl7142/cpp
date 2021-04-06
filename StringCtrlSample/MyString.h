#pragma once

class CMyString {
public:
    CMyString();
    ~CMyString();

    // 복사 생성자
    CMyString(const CMyString &rhs);

    // 변환 생성자
    explicit CMyString(const char *pszParam);

    operator char*() const {
        return m_pszData;
    }

    CMyString& operator=(const CMyString &rhs);

    int SetString(const char* pszParam);
    const char* GetString() const;
    void Release();

private:
    char* m_pszData;

    int m_nLength;
};