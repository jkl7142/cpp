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

    // 이동 생성자
    CMyString(CMyString &&rhs);

    // 산술, 대입 연산자
    CMyString& operator=(const CMyString &rhs);
    CMyString operator+(const CMyString &rhs);
    CMyString& operator+=(const CMyString &rhs);

    // 배열 연산자
    char& operator[](int nIndex);
    char operator[](int nIndex) const;

    // 관계 연산자
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