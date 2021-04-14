#pragma once
#include "MyNode.h"
#include "MyString.h"

class CMyString;

class CUserData : public CMyNode {
public:
    CUserData(void);
    CUserData(const char* pszName, const char* pszPhone);
    //CUserData(const char* strName, const char* strPhone);
    ~CUserData(void);

    const char* GetName(void) const { return strName.GetString(); }
    const char* GetPhone(void) const { return strPhone.GetString(); }
    static int GetUserDataCounter(void) { return nUserDataCounter; }

protected:
    //char szName[32];
    //char szPhone[32];
    CMyString strName;
    CMyString strPhone;

    static int nUserDataCounter;

public:
    virtual const char* GetKey(void);
    virtual void PrintNode(void);
};