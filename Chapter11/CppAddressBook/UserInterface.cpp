#include "stdafx.h"
#include "UserInterface.h"
#include "MyList.h"

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

    m_List.AddNewNode(szName, szPhone);
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

    pNode = m_List.FindNode(szName);

    if (pNode != NULL) {
        cout << "[" << (int)&pNode << "] " <<
        pNode->GetName() << "\t" << pNode->GetPhone() << " " << "[" <<
        (pNode->GetNext()) << "]" << endl;
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
            m_List.PrintAll();
            break;

        case 4: // Remove
            Remove();
            break;
        }
    }

    return nMenu;
}