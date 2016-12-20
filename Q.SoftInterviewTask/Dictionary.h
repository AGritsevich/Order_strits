
#pragma once
#include <string>
#include <set>

class CDictionary
{
protected:
	struct comparator 
	{
		bool operator () (const std::wstring& leftSubTree, const std::wstring& rightSubTree) const;
	};

private:
	std::set<std::wstring, comparator> m_dict;
	 
public:
	CDictionary();
	~CDictionary();

	bool Load(TCHAR* fileName);
	int IsItPresent(std::wstring &str);
};