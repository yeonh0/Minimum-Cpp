#pragma once
#include "CMyString.h"

class CMyStringEx : public CMyString
{
public:
	CMyStringEx();
	~CMyStringEx();
	CMyStringEx& operator=(const char* pParam);
	void setData(const char* pParam);
};

