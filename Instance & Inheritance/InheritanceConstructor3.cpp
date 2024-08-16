#include <iostream>
using namespace std;

class MyDataA {
public:
    MyDataA() { cout << "MyDataA()" << endl; }
    ~MyDataA() { cout << "~MyDataA()" << endl; }
};

class MyDataB : public MyDataA {
public:
    MyDataB() {
        cout << "MyDataB()" << endl;
        pszData = new char[32];
        strcpy_s(pszData, sizeof(char[32]), "TestString");
    }

    ~MyDataB() { 
        cout << "~MyDataB()" << endl;
        delete[] pszData; 
    }

    char* getString() {
        return pszData;
    }

protected:
    char* pszData = nullptr;
};

class MyDataC : public MyDataB {
public:
    MyDataC() {
        cout << "MyDataC()" << endl;
        // 파생 형식의 생성자에서 부모 클래스 멤버 변수에 접근
        // 파생 형식의 생성자는 가장 마지막에 실행되므로 부모 클래스 생성자에서 할당받은 메모리 공간 있는데 nullptr로 초기화
        // 메모리 릭이 일어남
        pszData = nullptr;
    }

    ~MyDataC() { 
        cout << "~MyDataC()" << endl;
    }
};

int main() {
    MyDataC data;
    cout << data.getString() << endl;

    return 0;
}