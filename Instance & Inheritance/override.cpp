#include <iostream>
using namespace std;

class MyData {
public:
    int getData() { return nData; }

    void setData(int nParam) { nData = nParam; }

private:
    int nData = 0;
};

class MyDataEx : public MyData {
public:
    // 일반적인 override : 과거 메서드 작동 + 기능 append
    int setData(int nParam) {
        if(nParam < 0) MyData::setData(0);
        if(nParam > 10) MyData::setData(10);
    }
};

int main() {
    MyDataEx a;
    MyData& rData = a;
    MyDataEx& rExData = a;

    // 일반 메서드 -> 참조 형식에 따라 호출됨!
    rData.setData(15);
    cout << rData.getData() << '\n';

    rExData.setData(15);
    cout << rExData.getData() << '\n';

    a.setData(-3);
    cout << a.getData() << '\n';

    return 0;
}