#include <iostream>
#include "CMyString.h"

using namespace std;

int main()
{
    CMyString Hello("Hello ");
    Hello += "World";

    cout << Hello << endl;
    cout << Hello[6] << endl;

    cout << Hello[-1] << endl;
    cout << Hello[20] << endl;

    return 0;
}