#pragma once
#include <windows.h>
#include <string>
#include <vector>
#include "TypeDefs.h"
#include "Obfus.h"

class Download
{

public:
	std::string download(std::string host, std::string path, int port);
};

