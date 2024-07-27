#include <iostream>
using namespace std;

class TestData {
public:
    explicit TestData(int param) : nData(param) {
        cout << "TestData(int)" << endl;
    }

    TestData(const TestData& rhs) : nData(rhs.nData) {
        cout << "TestData(&rhs)" << endl;
    }

    ~TestData() {
        cout << "~TestData()" << endl;
    }

    int getData() const {
        return nData;
    }

    operator int(void) {
        return nData;
    }

private:
    int nData = 0;
};

void testFunc(const TestData &param) {
    cout << "testFunc(): " << param.getData() << endl;
}

int main() {
    testFunc( TestData(5) );

    TestData a(10);
    cout << a << endl;

    return 0;
}