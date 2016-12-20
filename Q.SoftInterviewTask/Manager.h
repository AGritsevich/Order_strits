#pragma once
#include "Searcher.h"
#include "Dictionary.h"
#include <windows.h>

class CManager
{
private:
	CDictionary& m_dict;
	CSearcher& m_searcher;
	const std::string FileName;
	
	std::list<int> m_output;

public:

	CManager(CDictionary &dict, CSearcher &search);
	~CManager();

	void Find();
	bool Unload();

	static unsigned int WINAPI Finder(void* ptr);
	
};


