#include <iostream>
using namespace std;

class MyInterface {
public:
    MyInterface() {}
    virtual int getData() const = 0;
    virtual void setData(int nParam) = 0;
};

class MyData : public MyInterface {
public:
    virtual int getData() const { return nData; }
    virtual void setData(int nParam) { nData = nParam; }

private:
    int nData = 0;
};

int main() {
    // MyInterface a;
    MyData hi;
    hi.setData(10);
    cout << hi.getData() << endl;

    return 0;
}