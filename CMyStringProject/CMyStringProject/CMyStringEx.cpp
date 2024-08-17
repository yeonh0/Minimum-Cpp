#include <iostream>
#include "CMyStringEx.h"

using namespace std;

CMyStringEx::CMyStringEx() {
	cout << "CMyStringEx()" << endl;
}

CMyStringEx::~CMyStringEx() {
	cout << "~CMyStringEx()" << endl;
}

// Called by Framework
void CMyStringEx::onSetData(const char*& param) {
	cout << "CMyStringEx::onSetData" << endl;
	if (param != nullptr) {
		if (strcmp(param, "�۸��̾Ƶ�") == 0) {
			param = "�츮���۾Ƶ�";
		}
	}

	CMyString::onSetData(param);
}

CMyStringEx& CMyStringEx::operator=(const char* pParam) {
	this->setData(pParam);
	return *this;
}

/*
void CMyStringEx::setData(const char* pParam)
{
	cout << "CMyStringEx::setData()" << endl;
	if (pParam != nullptr) {
		if (strcmp(pParam, "�۸��̾Ƶ�") == 0) {
			CMyString::setData("���ѾƵ�");
			return;
		}
	}

	CMyString::setData(pParam);
}
*/