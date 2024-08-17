#include <iostream>
using namespace std;

class MyData {
public:
    virtual void printData() {
        cout << "MyData::printData()" << '\n';
    }

    void testFunc() {
        cout << "MyData::testFunc()" << '\n';
        // MyData::printData()가 아니라, MyDataEx::printData()가 호출됨!!
        printData();
    }

protected:
    int naData = 10;
};

class MyDataEx : public MyData {
public:
    // Called by Framework : 직접 호출하는 경우 이외에 구조에 의해 호출될 수 있음
    virtual void printData() {
        cout << "MyDataEx::printData()" << '\n';
    }

    void testFunc() {
        cout << "MyDataEx::testFunc()" << '\n';
        printData();
    }
};

int main() {
    MyDataEx a;
    MyData& b = a;

    a.printData();
    b.printData();

    a.testFunc();
    b.testFunc();

    return 0;
}