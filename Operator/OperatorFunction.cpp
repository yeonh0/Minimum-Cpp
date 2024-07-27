#include <iostream>
using namespace std;

class MyData {
public:
    MyData() {};

    MyData(int param) : nData(param) {};

    int getData() const {return nData;}

    void setData(int param) { nData = param; }

    MyData& operator=(const MyData& rhs) { 
        cout << "operator=" << endl;
        nData = rhs.getData();

        return *this;
     }
     
     MyData operator+(const MyData& rhs) {
        cout << "operator+" << endl;
        MyData retVal(0);
        retVal.setData(nData + rhs.getData());

        return retVal;
     }

private:
    int nData = 0;
};

MyData operator+(int left, const MyData& rhs) {
    cout << "global operator+" << endl;
    MyData data(left + rhs.getData());
    return data;
}

int main() {
    MyData a(30), b(40);

    // 1. operator=
    MyData result;
    result = a;
    cout << "1. result of (result = a) : " << result.getData() << endl;
    result = b;
    cout << "2. result of (result = b) : " << result.getData() << endl;

    // 2. operator+(&rhs) : Method of Class MyData
    result = result + a;
    cout << "3. result of (result + a) : " << result.getData() << endl;
    result = a + b;
    cout << "4. result of (a + b) : " << result.getData() << endl;

    // 3. operator+(int, &rhs) : Global Operator
    result = 4 + a;
    cout << "5. result of (4 + a) : " << result.getData() << endl;

    return 0;
}