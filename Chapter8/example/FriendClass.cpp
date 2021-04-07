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

private:
    CNode m_HeadNode;
};

int main(int argc, char* argv[]) {
    CMyList list;
    list.AddNewNode("±æµ¿");
    list.AddNewNode("Ã¶¼ö");
    list.AddNewNode("¿µÈñ");

    return 0;
}