#include <iostream>
using namespace std;

class MyData {
public:
    MyData() { cout << "MyData()" << endl; }
    MyData(int nParam) { cout << "MyData(int)" << endl; }
    MyData(double dParam) { cout << "MyData(double)" << endl; }
};

class MyDataEx : public MyData{
public:
    MyDataEx() { cout << "MyDataEx()" << endl; }
    MyDataEx(int nParam) : MyData(nParam) { cout << "MyDataEx(int)" << endl; }
    MyDataEx(double dParam) { cout << "MyDataEx(double)" << endl; }
};


int main() {
    MyDataEx a; cout << "***********" << endl;
    MyDataEx b(3); cout << "***********" << endl;
    MyDataEx c(3.6);
    return 0;
}