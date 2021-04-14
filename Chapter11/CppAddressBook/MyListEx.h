#pragma once
#include "MyNode.h"
#include "MyList.h"

class CMyListEx : public CMyList {
public:
    CMyListEx(CMyNode *pHead);
    ~CMyListEx(void);

    int OnAddNewNode(CMyNode* pNewNode);
};