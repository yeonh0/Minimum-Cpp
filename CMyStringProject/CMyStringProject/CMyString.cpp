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

CMyString CMyString::operator+(const CMyString& rhs) {
	cout << "operator(const CMyString&)" << endl;
	CMyString result(this->m_pszData);
	result.append(rhs.getData());

	return result;
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

size_t CMyString::append(const char* pParam) {
	if (pParam == nullptr)
		return -1;

	if (this->m_pszData == nullptr) {
		this->setData(pParam);
		this->length = strlen(pParam);
		return length;
	}

	size_t lenAppend = strlen(pParam);
	char* pResult = new char[length + lenAppend + 1];

	strcpy_s(pResult, length + lenAppend + 1, m_pszData);
	strcat_s(pResult + length, lenAppend + 1, pParam);
	this->length += lenAppend;

	delete[]m_pszData;
	m_pszData = pResult;

	return this->length;
}

CMyString operator+(const char* pLeft, const CMyString& rhs) {
	CMyString result(pLeft);
	result.append(rhs.getData());

	return result;
}