#include <iostream>
using namespace std;

class MyObject {
public:
    MyObject() {}
    virtual ~MyObject() {}
    virtual int getDeviceId() = 0;
protected:
    int deviceId;
};

class MyTV : public MyObject {
public:
    MyTV(int id) { deviceId = id; }
    virtual int getDeviceId() { 
        cout << "MyTV::getDeviceId()" << endl;
        return deviceId;
     }
};

class MyPhone : public MyObject {
public:
    MyPhone(int id) { deviceId = id; }
    virtual int getDeviceId() { 
        cout << "MyPhone::getDeviceId()" << endl;
        return deviceId;
     }
};

void printId(MyObject& pObj) {
    cout << "Device Id : " << pObj.getDeviceId() << endl;
}

int main() {
    // MyObject a;
    MyTV a(5);
    MyPhone b(10);

    ::printId(a);
    ::printId(b);

    return 0;
}