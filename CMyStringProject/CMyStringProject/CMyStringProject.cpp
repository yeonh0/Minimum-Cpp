#include <iostream>
#include "CMyString.h"
#include "CMyStringEx.h"

using namespace std;

int main()
{
    CMyStringEx data;
    data = "Hello";
    cout << data << endl;

    data = "멍멍이아들";
    cout << data << endl;

    CMyString &rdata = data;
    rdata = "멍멍이아들";
    cout << rdata << endl;

    return 0;
}