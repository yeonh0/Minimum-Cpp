#include <iostream>
#include "CMyString.h"

using namespace std;

int main()
{
    CMyString Hello("Hello ");
    CMyString world("world");

    Hello + "world";
    "Hello" + world;

    return 0;
}