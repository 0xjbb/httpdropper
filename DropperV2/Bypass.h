#pragma once
#include <windows.h>
#include <string>
#include <vector>
#include "TypeDefs.h"
#include "Obfus.h"

struct Patch{
	int size;
	std::vector<byte> patchBytes;
	std::vector<byte> oldBytes;
};

class Bypass
{
private:
	void WriteMem(FARPROC addr, Patch patch);
	FARPROC GetAddr(std::string dllName, std::string fName);
public:
	bool PatchETW(){}
	bool PatchAMSI(){}

	//add these later
	//bool UnPatchETW() {}
	//bool UnPatchAMSI() {}

};

