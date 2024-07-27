#include <iostream>
using namespace std;

class MyData {
public:
    MyData(int param) : nData(param) {}

    operator int() {
        return nData;
    }

    int operator++() {
        cout << "operator++()" << endl;
        return ++nData;
    }

    int operator++(int) {
        cout << "operator++(int)" << endl;

        int data = nData;
        nData++;

        return data;
    }

    // MyData& operator++(int) {
    //     int data = nData;
    //     nData++;

    //     return *this;
    // }

private:
    int nData = 0;
};

int main() {
    MyData test(10);
    cout << ++test << endl;
    cout << test++ << endl;
    //cout << test++++++ << endl;
    cout << test << endl;

    return 0;
}