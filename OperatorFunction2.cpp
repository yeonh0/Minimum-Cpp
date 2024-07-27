#include <iostream>
using namespace std;

class MyData {
public:
    MyData() {}

    MyData(const int param) {
        if(this->pData != nullptr)
            delete[] pData;
        this->pData = new int(param);
    }

    MyData(const MyData& rhs) {
        cout << "MyData(const MyData&)" << endl;
        if(this->pData != nullptr) delete[] pData;
        this->pData = rhs.pData;
    }

    operator int() {
        return *this->pData;
    }

    MyData& operator=(const MyData& rhs) {
        if(this->pData != nullptr)
            delete pData;
        this->pData = new int(*rhs.pData);

        return *this;
    }

    MyData& operator+=(const MyData& rhs) {
        int result = *pData;
        result += *rhs.pData;
        delete this->pData;
        this->pData = new int(result);

        return *this;
    }
 
private:
    int *pData = nullptr;
};

int main() {
    MyData num1(10), num2(20), num3(30);
    num1 = num2 = num3 = 20;
    num2 += num3;
    cout << " " << num1 << " " << num2 << " " << num3 << endl;
}