#include <iostream>
using namespace std;

class MyData {
public:
    MyData() {}
    virtual ~MyData() {}

    virtual void testFunc1() { cout << "MyData::testFunc1()" << endl; }

    virtual void testFunc2() { cout << "MyData::testFunc2()" << endl; }
};

class MyDataEx : public MyData {
public:
    MyDataEx() {}
    ~MyDataEx() {}

    virtual void testFunc1() { cout << "MyDataEx::testFunc1()" << endl; }

    virtual void testFunc2() { cout << "MyDataEx::testFunc2()" << endl; }
};

int main() {
    MyData* pData = new MyDataEx;
    pData->testFunc2();
    delete pData;

    return 0;
} 