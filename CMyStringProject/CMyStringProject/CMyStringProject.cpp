#include <iostream>
#include "CMyString.h"
#include "CMyStringEx.h"

using namespace std;

int main()
{
    CMyString* pstrData = new CMyStringEx;
    pstrData->setData("멍멍이아들");
    cout << pstrData->getData() << endl;

    delete pstrData;

    return 0;
}