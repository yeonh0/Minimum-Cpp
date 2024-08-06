#include <cstring>
#include <iostream>
using namespace std;

class Node {
    friend class MyList;
public:
    explicit Node(const char* pszName) {
        strcpy(m_szName, pszName);
    }
    
private:
    char m_szName[30];
    Node* pNext = nullptr;
};

class MyList {
public:
    MyList():m_HeadNode("Dummy Head") {}
    ~MyList() {
        Node* pNode = m_HeadNode.pNext;
        Node* pDelete = nullptr;

        while(pNode) {
            pDelete = pNode;
            pNode = pNode->pNext;
            cout << pDelete->m_szName << endl;
            delete pDelete;
        }
        m_HeadNode.pNext = nullptr;
    }
    void AddNewNode(const char* pszName) {
        Node* pNode = new Node(pszName);
        pNode->pNext = m_HeadNode.pNext;
        m_HeadNode.pNext = pNode;
    }

private:
    Node m_HeadNode;
};

int main() {
    MyList list;
    list.AddNewNode("amy");
    list.AddNewNode("bob");
    list.AddNewNode("chris");
}