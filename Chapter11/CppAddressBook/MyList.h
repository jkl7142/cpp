#pragma once

#include "UserData.h"

#define DATA_FILE_NAME "Address.dat"

class CMyList {
public:
    CMyList(void);
    ~CMyList(void);

protected:
    void ReleaseList(void);
    CUserData m_Head;

public:
    CUserData* FindNode(const char* pszName);
    int AddNewNode(const char* pszName, const char* pszPhone);

    void PrintAll(void);

    int RemoveNode(const char* pszName);
};