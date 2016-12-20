
#include "stdafx.h"
#include "Dictionary.h"
#include <fstream>
#include <sstream>

bool CDictionary::comparator::operator () (const std::wstring& leftSubTree, const std::wstring& rightSubTree) const 
{
	if ( _wcsnicmp(leftSubTree.c_str(), 
		rightSubTree.c_str(), 
		( (leftSubTree.size() > rightSubTree.size()) ? leftSubTree.size() : rightSubTree.size() ) 
		) < 0)
		return true;

	return false;
}

CDictionary::CDictionary(){}

CDictionary::~CDictionary(){}

bool CDictionary::Load( TCHAR* fileName )
{	
	std::wifstream infile(fileName);
	std::set<std::wstring>::iterator it = m_dict.begin();

	if ( !infile.is_open() ) return false;

	std::wstring header;
	std::getline(infile, header);

	std::wstring line;
	while ( std::getline(infile, line) )
	{
		m_dict.insert (it, line);  // max efficiency inserting
	}

	//infile.close();

	return true;
}

int CDictionary::IsItPresent( std::wstring &str )
{
	std::set<std::wstring>::iterator it;

	 it = m_dict.find(str);

	 if ( it == m_dict.end() ) return 0;

	 return 1;
}