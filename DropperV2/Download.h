#pragma once
#include <windows.h>
#include <wininet.h>
#include <string>
#include <vector>
#include "TypeDefs.h"

#pragma comment(lib, "wininet.lib")

class Download
{

public:
	std::vector<char> DownloadFile(std::string szUrl);
};

