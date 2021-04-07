#include <iostream>
#include <string.h>
using namespace std;

class CNode {
    friend class CMyList;

public:
    explicit CNode(const char *pszName) {
        strncpy(m_szName, pszName, sizeof(m_szName));
    }

private:
    char m_szName[32];
    CNode *pNext = nullptr;
};

class CMyList {
public:
    CMyList() : m_HeadNode("Dummy Head") { }
    ~CMyList() {
        CNode *pNode = m_HeadNode.pNext;
        CNode *pDelete = nullptr;

        while(pNode) {
            pDelete = pNode;
            pNode = pNode->pNext;

            cout << pDelete->m_szName << endl;
            delete pDelete;
        }

        m_HeadNode.pNext = nullptr;
    }

    void AddNewNode(const char *pszName) {
        CNode *pNode = new CNode(pszName);

        pNode->pNext = m_HeadNode.pNext;
        m_HeadNode.pNext = pNode;
    }

    void Print() {
        CNode *pNode = m_HeadNode.pNext;
        while(pNode) {
            cout << pNode->m_szName << endl;
            pNode = pNode->pNext;
        }
    }

private:
    CNode m_HeadNode;
};

class CMyUI {
public:
    CMyUI(CMyList &rList) : m_list(rList) { }

    int PrintMenu() {
        system("cls");
        cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n:";
        cout.flush();
        int nInput = 0;
        cin >> nInput;

        return nInput;
    }

    void Run() {
        char szName[32];
        int nInput = 0;

        while ((nInput = PrintMenu()) > 0) {
            switch(nInput) {
                case 1: // Add
                    cout << "ÀÌ¸§: ";
                    cout.flush();
                    cin >> szName;
                    m_list.AddNewNode(szName);
                    break;

                case 2: // Print
                    m_list.Print();
                    break;
                
                default:
                    break;
            }
        }
    }

private:
    CMyList &m_list;
};

int main(int argc, char* argv[]) {
    CMyList list;
    CMyUI ui(list);
    ui.Run();

    return 0;
}