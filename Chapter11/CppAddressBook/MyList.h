#pragma once

#include "MyNode.h"

#define DATA_FILE_NAME "Address.dat"

class CMyNode;

class CMyList {
public:
    CMyList(CMyNode *pHead);
    ~CMyList(void);

protected:
    void ReleaseList(void);
    CMyNode *m_pHead;

public:
    CMyNode* FindNode(const char* pszKey);
    int AddNewNode(CMyNode *pNewNode);
    void PrintAll(void);
    int RemoveNode(const char* pszKey);
};