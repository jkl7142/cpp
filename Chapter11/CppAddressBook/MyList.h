#pragma once

#include "MyNode.h"

#define DATA_FILE_NAME "Address.txt"

class CMyNode;
class CMyIterator;

class CMyList {
public:
    CMyList(CMyNode *pHead);
    virtual ~CMyList(void);

protected:
    void ReleaseList(void);
    CMyNode *m_pHead;

public:
    CMyNode* FindNode(const char* pszKey);
    int AddNewNode(CMyNode *pNewNode);
    // void PrintAll(void);
    int RemoveNode(const char* pszKey);

    // 열거자 생성
    CMyIterator MakeIterator(void);

    // 데이터가 추가될 때마다 호출되는 가상 함수
    virtual int OnAddNewNode(CMyNode* pNewNode);
};