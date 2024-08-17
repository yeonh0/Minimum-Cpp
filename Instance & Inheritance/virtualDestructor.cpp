#include <iostream>
using namespace std;

class MyData {
public:
    MyData() {
        m_pszData = new char[32];
    }
    virtual ~MyData() {
        cout << "~MyData()" << '\n';
        delete[] m_pszData;
    }
private:
    char* m_pszData;
};

class MyDataEx : public MyData {
public:
    MyDataEx() {
        m_pnData = new int;
    }
    ~MyDataEx() {
        cout << "~MyDataEx()" << '\n';
        delete m_pnData;
    }
private:
    int* m_pnData;
};


int main() {
    MyData* pData = new MyDataEx;
    delete pData;

    return 0;
}