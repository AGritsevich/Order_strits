
#include "stdafx.h"
#include "Searcher.h"
#include <fstream>

bool CSearcher::Load( TCHAR* fileName )
{
	std::wifstream infile(fileName);

	if ( !infile.is_open() ) return false;

	std::wstring header;
	std::getline(infile, header);

	std::wstring line;
	while ( std::getline(infile, line) )
	{
		m_searches.push_back(line);
	}

	infile.close();

	return true;
}