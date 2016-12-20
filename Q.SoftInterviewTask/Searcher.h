
#pragma once
#include <string>
#include <list>

class CSearcher
{
	friend class CManager;

private:
	std::list<std::wstring> m_searches;
	int m_nRecords;

public:
	bool Load(TCHAR* fileName);
};