#include "stdafx.h"
#include "MyList.h"

CMyList::CMyList(void) {
    // LoadList()
    try
    {
        FILE *fp = fopen(DATA_FILE_NAME, "rb");
        CUserData *user;

        if (fp == NULL) throw false;

        ReleaseList();

        while (fread(user, sizeof(CUserData), 1, fp)) {
            AddNewNode(user->szName, user->szPhone);
        }

        fclose(fp);
    }
    catch(bool)
    {
        cout << "ERROR: 리스트 파일을 읽기 모드로 열지 못했습니다." << endl;
    }


}
CMyList::~CMyList(void) {
    // SaveList()
    try
    {
        FILE *fp = fopen(DATA_FILE_NAME, "wb");
        CUserData *pTmp = m_Head.pNext;

        if (fp == NULL) throw false;        

        while (pTmp != NULL) {
            if (fwrite(pTmp, sizeof(CUserData), 1, fp) != 1) {
                cout << "ERROR: " << pTmp->szName << "에 대한 정보를 저장하는 데 실패했습니다." << endl;
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

int CMyList::AddNewNode(const char* pszName, const char* pszPhone) {
    CUserData *pNewUser = NULL;

    if (FindNode(pszName) != NULL) {
        return 0;
    }

    pNewUser = new CUserData;

    strncpy(pNewUser->szName, pszName, sizeof(pNewUser->szName));
    strncpy(pNewUser->szPhone, pszPhone, sizeof(pNewUser->szPhone));
    pNewUser->pNext = NULL;

    pNewUser->pNext = m_Head.pNext;
    m_Head.pNext = pNewUser;

    return 1;
}

void CMyList::PrintAll(void) {
    CUserData *pTmp = m_Head.pNext;

    while (pTmp != NULL) {
        cout << "[" << (int)&pTmp << "] " <<
        pTmp->szName << "\t" << pTmp->szPhone << " " << "[" <<
        (int)&pTmp->pNext << "]" << endl;

        pTmp = pTmp->pNext;
    }

    cout << "CUserData Counter : " << CUserData::GetUserDataCounter() << endl;

    _getch();
}

CUserData* CMyList::FindNode(const char* pszName) {
    CUserData *pTmp = m_Head.pNext;

    while (pTmp != NULL) {
        if (strcmp(pTmp->szName, pszName) == 0) return pTmp;

        pTmp = pTmp->pNext;
    }

    return NULL;
}

int CMyList::RemoveNode(const char* pszName) {
    CUserData *pPrevNode = &m_Head;
    CUserData *pDelete = NULL;

    while (pPrevNode->pNext != NULL) {
        pDelete = pPrevNode->pNext;

        if (strcmp(pDelete->szName, pszName) == 0) {
            pPrevNode->pNext = pDelete->pNext;
            delete pDelete;

            return 1;
        }

        pPrevNode = pPrevNode->pNext;
    }

    return 0;
}

void CMyList::ReleaseList(void) {
    CUserData *pTmp = m_Head.pNext;
    CUserData *pDelete = NULL;

    while (pTmp != NULL) {
        pDelete = pTmp;
        pTmp = pTmp->pNext;

        delete pDelete;
    }

    m_Head.pNext = NULL;
}