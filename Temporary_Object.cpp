#include <bits/stdc++.h>

using namespace std;

class TestData
{
    public:
        TestData(const int Data) : nData(Data) {
            cout << "TestData(int)" << endl;
        }

        TestData(const TestData& rhs) : nData(rhs.nData) {
            cout << "TestData(TestData&)" << endl;
        }

        ~TestData() {
            cout << "~TestData( " << nData << " )" << endl;
        }

        int getData() const {
            return nData;
        }

        int setData(const int data) {
            nData = data;
        }

    private:
        int nData = 0;
};

TestData testFunc(const TestData& rhs) {
    cout << "testFunc()" << endl;
    cout << "rhs : " << rhs.getData() << endl;
    //rhs.setData(20);
    return rhs;
};

int main() {
    TestData(30);
    TestData result = testFunc(TestData(10));
    result.setData(100);
    cout << "End Of Main" << endl;

    return 0;
}