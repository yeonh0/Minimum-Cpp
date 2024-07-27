#include <iostream>
using namespace std;

class MyData {
public:
    MyData() {
        pData = new int(0);
    }

    MyData(const MyData& rhs) {
        cout << "MyData(&rhs)" << endl;
        setData(rhs.getData());
    }

    MyData(MyData&& rhs) noexcept {
        cout << "MyData(&&rhs)" << endl;
        delete pData;
        pData = rhs.pData;
        rhs.pData = nullptr;
    }

    ~MyData() {
        cout << "~MyData()" << endl;
        delete pData;
    }

    void operator=(MyData& rhs) {
        cout << "operator=(MyData&)" << endl;
        setData(rhs.getData());
    }

    MyData& operator=(MyData&& rhs) {
        cout << "operator=(MyData&&)" << endl;
        delete pData;
        pData = rhs.pData;
        rhs.pData = nullptr;
        return *this;
    }

    int getData() const {
        return *pData;
    }

    void setData(int param) {
        if(pData != nullptr) delete pData;
        pData = new int;
        *pData = param;
    }

private:
    int *pData = nullptr;
};

MyData getMyData(int param) {
    cout << "getMyData()" << endl;
    MyData data;
    data.setData(param);
    return data;
}

int main() {
    // 1. 인스턴스 선언 및 정의: 컴파일러 최적화로 이동 생성 이루어지지 않음
    cout << "Try 1:" << endl;
    MyData data1 = getMyData(5);

    // 2. 인스턴스 생성 및 단순 대입: 이동 생성 일어남
    cout << "Try 2:" << endl;
    MyData data2;
    data2 = getMyData(10);

    // 3. 이동 시맨틱
    cout << "Try 3:" << endl;
    MyData data3(std::move(getMyData(30)));
}