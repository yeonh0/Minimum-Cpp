#include <iostream>
using namespace std;

class MyData {
public:
    MyData() {
        cout << "MyData()" << '\n';
    }

    int getData() {
        return nData;
    }

    void setData(int nParam) {
        nData = nParam;
    }

protected:
    void printData() {
        cout << "MyData::PrintData()" << '\n';
    }

private:
    int nData = 0;
};

class MyDataEx : public MyData {
public:
    MyDataEx() { cout << "MyDataEx()" << '\n'; }

    void testFunc() {
        printData();
        setData(5);
        cout << MyData::getData() << '\n';
    }
};

int main() {
    MyDataEx data;

    data.setData(10);
    cout << data.getData() << '\n';
    data.testFunc();

    // 추상 형식에 대한 접근 (추상 자료형) : pData->testFunc()는 불가능
    MyData *pData = new MyDataEx;
    pData->setData(4);
    cout << pData->getData() << '\n';
    delete pData;

    MyDataEx extData;
    MyData& rData = extData;
    cout << rData.getData() << '\n';

    return 0;
}