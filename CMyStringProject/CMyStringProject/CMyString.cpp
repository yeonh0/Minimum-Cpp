#include <iostream>
#include "CMyString.h"

using namespace std;

CMyString::CMyString() {
	cout << "CMyString()" << endl;
}

CMyString::CMyString(const char* param) {
	cout << "CMyString(const char*)" << endl;
	this->setData(param);
}

CMyString::CMyString(const CMyString& rhs) {
	cout << "CMyString(const CMyString&)" << endl;
	this->setData(rhs.getData());
}

CMyString::CMyString(CMyString&& rhs) noexcept {
	cout << "CMyString(CMyString&&) - move" << endl;
	delete[] this->m_pszData;
	this->m_pszData = rhs.m_pszData;
	rhs.m_pszData = nullptr;
}

void CMyString::operator=(CMyString&& rhs) noexcept {
	cout << "operator=(CMyString&&) - move" << endl;
	delete[] this->m_pszData;
	this->m_pszData = rhs.m_pszData;
	rhs.m_pszData = nullptr;
}

CMyString::~CMyString() {
	cout << "~CMyString()" << endl;
	delete[] m_pszData;
}

void CMyString::setData(const char* pParam) {
	if (m_pszData != nullptr)
		delete[] m_pszData;
	length = strlen(pParam);
	m_pszData = new char[length + 1];

	strcpy_s(m_pszData, length + 1, pParam);
}
