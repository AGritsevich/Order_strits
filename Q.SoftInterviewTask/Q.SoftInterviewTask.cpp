// Q.SoftInterviewTask.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Timer.h"
#include "Manager.h"

const int MIN_PARAMS = 3;

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != MIN_PARAMS )
	{
		std::cout << "Invalid command line. ";
		system("pause");
		return 1;
	}

	SYSTEMTIME  startTime, preproccessingTime, startIO1, startIO2, finishIO1, finishTime;

	//pre-proccessing

	CDictionary dict;
	CSearcher searcher;
	CManager manager(dict, searcher);

	GetSystemTime(&startTime);

	if ( !dict.Load(argv[1]))
	{
		std::cout << "Can't load dictionary :( " << std::endl;
		return 1;
	}

	GetSystemTime(&preproccessingTime);
	std::cout << "Pre-proccessing time is "<< CTimer::GetDiffrent(preproccessingTime, startTime)<< " seconds." << std::endl;

	//I
	GetSystemTime(&startIO1);
	if ( !searcher.Load(argv[2]))
	{
		std::cout << "Can't load search file :( " << std::endl;
		return 1;
	}
	GetSystemTime(&finishIO1);

	//search
	manager.Find();

	//O
	GetSystemTime(&startIO2);
	if ( !manager.Unload() )
	{
		std::cout << "Can't unload output file :( " << std::endl;
		return 1;
	}

	GetSystemTime(&finishTime);

	std::cout << "Total search time is " << CTimer::GetDiffrent( finishTime, startIO1) << " seconds.\n";
	std::cout << "Total pure search time is " << CTimer::GetDiffrent( startIO2, finishIO1) << " seconds.\n";
	
	system("pause");
	return 0;
}

