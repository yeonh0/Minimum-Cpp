#include <iostream>
#include "CMyString.h"

using namespace std;

int main()
{
    CMyString Hello("Hello ");
    CMyString World("World");

    cout << Hello + World << endl;
    cout << "(const char[])Hello " + World << endl;

    return 0;
}