#include "bits/stdc++.h"

using namespace std;

class MyString {
public:
    MyString() : nData() {
        cout << "MyString()" << endl;
    }

    MyString(int a) : nData(a) {
        cout << "MyString(int)" << endl;
    }

    MyString(const MyString& rhs) : nData(rhs.nData) {
        cout << "MyString(const MyString&)" << endl;
    }

    int getData() {
        return nData;
    }

private:
    int nData = 10;
};


int main() {
    MyString h1(30);
    cout << MyString().getData() << endl;
    cout << MyString(20).getData() << endl;
    cout << MyString(h1).getData() << endl;
}