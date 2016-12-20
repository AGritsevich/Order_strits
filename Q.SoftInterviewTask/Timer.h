
#pragma once

#include <windows.h>
#include <string>

class CTimer
{
public:
	static std::string GetDiffrent(const SYSTEMTIME& pSr,const SYSTEMTIME& pSl);
};