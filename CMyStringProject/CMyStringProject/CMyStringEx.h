#pragma once
#include "CMyString.h"

class CMyStringEx : public CMyString
{
public:
	CMyStringEx();
	~CMyStringEx();

	//void setData(const char* pParam);

	virtual void onSetData(const char*& param);

	CMyStringEx& operator=(const char* pParam);
};

