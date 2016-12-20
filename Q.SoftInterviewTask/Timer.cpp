
#include "stdafx.h"
#include "Timer.h"

std::string CTimer::GetDiffrent(const SYSTEMTIME& pSr,const SYSTEMTIME& pSl)
{
	SYSTEMTIME t_res;

	FILETIME v_ftime;
	ULARGE_INTEGER v_ui;
	__int64 v_right,v_left,v_res;
	SystemTimeToFileTime(&pSr,&v_ftime);
	v_ui.LowPart=v_ftime.dwLowDateTime;
	v_ui.HighPart=v_ftime.dwHighDateTime;
	v_right=v_ui.QuadPart;

	SystemTimeToFileTime(&pSl,&v_ftime);
	v_ui.LowPart=v_ftime.dwLowDateTime;
	v_ui.HighPart=v_ftime.dwHighDateTime;
	v_left=v_ui.QuadPart;

	v_res=v_right-v_left;

	v_ui.QuadPart=v_res;
	v_ftime.dwLowDateTime=v_ui.LowPart;
	v_ftime.dwHighDateTime=v_ui.HighPart;
	FileTimeToSystemTime(&v_ftime,&t_res);

	std::string time;
	char buff[100];
	sprintf_s(buff, sizeof(buff), " %03u.%03u", t_res.wMinute*60 + t_res.wSecond, t_res.wMilliseconds);
	time = buff;

	return time;
}