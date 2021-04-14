#include "stdafx.h"
#include "MyListEx.h"

CMyListEx::CMyListEx(CMyNode *pHead) : CMyList(pHead) { }
CMyListEx::~CMyListEx(void) { }

int CMyListEx::OnAddNewNode(CMyNode* pNewNode) {
    if (pNewNode->GetKey() != NULL) {
        return 1;
    }
    return 0;
}