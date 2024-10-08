#pragma once

class CMyString
{
	friend CMyString operator+(const char*, const CMyString&);
public:
	CMyString();
	explicit CMyString(const char* param);
	CMyString(const CMyString& rhs);
	CMyString(CMyString&& rhs) noexcept;
	virtual ~CMyString();

	const char* getData() const {
		return m_pszData;
	}

	operator const char* () const {
		return m_pszData;
	}

	size_t getLength() const {
		return this->length;
	}

	CMyString& operator=(const CMyString& rhs) {
		this->setData(rhs.getData());
		return *this;
	}

	CMyString& operator=(const char* pParam) {
		this->setData(pParam);
		return *this;
	}

	CMyString operator+(const CMyString& rhs);
	CMyString operator+(const char* pParam);

	CMyString& operator+=(const char* pParam);

	char operator[](int index) const;

	CMyString& operator=(CMyString&& rhs) noexcept;

	void setData(const char* pParam);
	virtual void onSetData(const char*& param) {}

	size_t append(const char* pParam);

private:
	char* m_pszData = nullptr;	
	size_t length = 0;
};

CMyString operator+(const char* pLeft, const CMyString& rhs);