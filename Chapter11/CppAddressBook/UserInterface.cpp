#include "stdafx.h"
#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"
#include "MyIterator.h"
#include "MyListEx.h"

CUserInterface::CUserInterface(CMyList &rList) : m_List(rList) {

}

CUserInterface::~CUserInterface(void) {
    
}

void CUserInterface::Add(void) {
    char szName[32] = {0};
    char szPhone[32] = {0};

    cout << "Input name : ";
    fflush(stdin);
    gets(szName);

    cout << "Input phone number : ";
    fflush(stdin);
    gets(szPhone);

    int nResult = m_List.AddNewNode(new CUserData(szName, szPhone));

    if (nResult == 0) {
        puts("ERROR: 이미 존재하는 데이터입니다.");

        _getch();
    }
    else if (nResult == -1) {
        puts("ERROR: 욕설을 이름으로 쓸 수 없습니다.");

        _getch();
    }
}

int CUserInterface::PrintUI(void) {
    int nInput = 0;

    system("cls");
    cout << "[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit" << endl;

    cin >> nInput;

    return nInput;
}

void CUserInterface::Search(void) {
    char szName[32] = {0};
    CUserData *pNode = NULL;

    cout << "Input name : ";
    fflush(stdin);
    gets(szName);

    pNode = static_cast<CUserData*>(m_List.FindNode(szName));

    if (pNode != NULL) {
        pNode->PrintNode();
    }
    else {
        puts("ERROR: 데이터를 찾을 수 없습니다.");
    }

    _getch();
}

void CUserInterface::Remove(void) {
    char szName[32];

    cout << "Input name : ";
    fflush(stdin);
    gets(szName);

    m_List.RemoveNode(szName);
}

int CUserInterface::Run(void) {
    int nMenu = 0;

    // 메인 이벤트 반복문
    while ((nMenu = PrintUI()) != 0) {
        switch(nMenu) {
        case 1: // Add
            Add();
            break;
        
        case 2: // Search
            Search();
            break;

        case 3: // Print All
            PrintAll();
            break;

        case 4: // Remove
            Remove();
            break;
        }
    }

    return nMenu;
}


void CUserInterface::PrintAll(void) {
    // 리스트에 대한 열거자를 생성
    CMyIterator it = m_List.MakeIterator();
    CUserData *pNode = NULL;

    // 열거자를 이용해 리스트 전체에 접근한다
    while ((pNode = static_cast<CUserData*> (it.GetCurrent())) != NULL) {
        pNode->PrintNode();
        it.MoveNext();
    }

    _getch();
}