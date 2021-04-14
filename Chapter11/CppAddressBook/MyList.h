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

    // ������ ����
    CMyIterator MakeIterator(void);

    // �����Ͱ� �߰��� ������ ȣ��Ǵ� ���� �Լ�
    virtual int OnAddNewNode(CMyNode* pNewNode);
};