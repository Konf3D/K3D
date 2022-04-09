#pragma once
#include "WinK3D.h"
#include <unordered_map>
#include <string>
#include <sstream>
#include <iomanip>

class WindowsMessageMap
{
public:
	WindowsMessageMap();
	std::string operator() (DWORD msg, LPARAM lp, WPARAM wp) const noexcept;
private:
	std::unordered_map<DWORD, std::string> map;
};