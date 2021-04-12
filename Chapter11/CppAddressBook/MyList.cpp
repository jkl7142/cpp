#include "stdafx.h"
#include "MyList.h"
#include "UserData.h"

CMyList::CMyList(CMyNode *pHead) {
    // LoadList()
    try
    {
        FILE *fp = fopen(DATA_FILE_NAME, "rb");
        CMyNode *user;

        if (fp == NULL) throw false;

        ReleaseList();

        while (fread(user, sizeof(CMyNode), 1, fp)) {
            AddNewNode(pHead);
        }

        fclose(fp);
    }
    catch(bool)
    {
        cout << "ERROR: 리스트 파일을 읽기 모드로 열지 못했습니다." << endl;
    }

    m_pHead = pHead;
}
CMyList::~CMyList(void) {
    // SaveList()
    try
    {
        FILE *fp = fopen(DATA_FILE_NAME, "wb");
        CMyNode *pTmp = m_pHead->pNext;

        if (fp == NULL) throw false;        

        while (pTmp != NULL) {
            if (fwrite(pTmp, sizeof(CMyNode), 1, fp) != 1) {
                // TODO
                cout << "ERROR: " << pTmp->GetKey() << "에 대한 정보를 저장하는 데 실패했습니다." << endl;
            }

            pTmp = pTmp->pNext;
        }

        fclose(fp);
    }
    catch(bool)
    {
        cout << "ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다." << endl;
    }
    
    ReleaseList();
}

int CMyList::AddNewNode(CMyNode *pNewNode) {
    if (FindNode(pNewNode->GetKey()) != NULL) {
        delete pNewNode;

        return 0;
    }

    pNewNode->pNext = m_pHead->pNext;
    m_pHead->pNext = pNewNode;

    return 1;
}

void CMyList::PrintAll(void) {
    CMyNode *pTmp = m_pHead->pNext;

    while (pTmp != NULL) {
        pTmp->PrintNode();
        pTmp = pTmp->pNext;
    }

    cout << "CUserData Counter : " << CUserData::GetUserDataCounter() << endl;

    _getch();
}

CMyNode* CMyList::FindNode(const char* pszKey) {
    CMyNode *pTmp = m_pHead->pNext;

    while (pTmp != NULL) {
        if (strcmp(pTmp->GetKey(), pszKey) == 0) return pTmp;

        pTmp = pTmp->pNext;
    }

    return NULL;
}

int CMyList::RemoveNode(const char* pszKey) {
    CMyNode *pPrevNode = m_pHead;
    CMyNode *pDelete = NULL;

    while (pPrevNode->pNext != NULL) {
        pDelete = pPrevNode->pNext;

        if (strcmp(pDelete->GetKey(), pszKey) == 0) {
            pPrevNode->pNext = pDelete->pNext;
            delete pDelete;

            return 1;
        }

        pPrevNode = pPrevNode->pNext;
    }

    return 0;
}

void CMyList::ReleaseList(void) {
    CMyNode *pTmp = m_pHead;
    CMyNode *pDelete = NULL;

    while (pTmp != NULL) {
        pDelete = pTmp;
        pTmp = pTmp->pNext;

        delete pDelete;
    }

    m_pHead = NULL;
}