
#include "stdafx.h"
#include "Manager.h"
#include <fstream>
#include <string>
#include <process.h>

CManager::CManager(CDictionary &dict, CSearcher &search) :
	m_dict(dict),
	m_searcher(search),
	FileName("Output.txt")
{}

CManager::~CManager(){}

void CManager::Find( )
{
	for ( std::list<std::wstring>::iterator it = m_searcher.m_searches.begin(); it != m_searcher.m_searches.end(); it++)
	{
		m_output.push_back( m_dict.IsItPresent(*it) );
	}
}

bool CManager::Unload()
{
	std::ofstream outfile (FileName);

	if ( !outfile.is_open() ) return false;

	outfile << m_output.size() << "\n";

	for (std::list<int>::iterator it = m_output.begin(); it != m_output.end(); ++it)
		outfile << *it << "\n";

	outfile.close();

	return true;
}