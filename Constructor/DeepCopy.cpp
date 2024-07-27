#include <bits/stdc++.h>
using namespace std;

class MyString {
    public:
        MyString() {
            cout << "MyString()" << endl;
        }
        MyString(const MyString& rhs) {
            cout << "MyString(MyString)" << endl;
            this->setData(rhs.getData());
        }
        ~MyString() {
            cout << "~MyString()" << endl;
        }

        const char* getData() const {
            return this->m_data;
        }

        void setData(const char* pParam) {
            if(m_data != nullptr)
                delete[] m_data;
            length = strlen(pParam);
            m_data = new char[length+1];
            strcpy(m_data, pParam);
        }

        size_t getLength() {
            return this->length;
        }

        void operator=(const MyString& rhs) {
            this->setData(rhs.getData());
        }
    private:
        char* m_data = nullptr;
        size_t length = 0;
};

int main() {
    MyString string1;
    string1.setData("Hello!");
    cout<<"string1: " << string1.getData() << ", length: " << string1.getLength() << endl;

    MyString string2(string1);
    cout<<"string2: " << string2.getData() << ", length: " << string2.getLength() << endl;

    MyString string3;
    string3 = string1;
    cout<<"string3: " << string3.getData() << ", length: " << string3.getLength() << endl;

    string2.setData("World!!!");
    string3.setData("Nice to meet you!");
    cout<<"string1: " << string1.getData() << ", length: " << string1.getLength() << endl;
    cout<<"string2: " << string2.getData() << ", length: " << string2.getLength() << endl;
    cout<<"string3: " << string3.getData() << ", length: " << string3.getLength() << endl;

    return 0;
}