#include <iostream>
#include "CMyStringEx.h"

using namespace std;

CMyStringEx::CMyStringEx() {
	cout << "CMyStringEx()" << endl;
}

CMyStringEx::~CMyStringEx() {
	cout << "~CMyStringEx()" << endl;
}

CMyStringEx& CMyStringEx::operator=(const char* pParam) {
	this->setData(pParam);
	return *this;
}


void CMyStringEx::setData(const char* pParam)
{
	cout << "CMyStringEx::setData()" << endl;
	if (pParam != nullptr) {
		if (strcmp(pParam, "¸Û¸ÛÀÌ¾Æµé") == 0) {
			CMyString::setData("ÂøÇÑ¾Æµé");
			return;
		}
	}

	CMyString::setData(pParam);
}
