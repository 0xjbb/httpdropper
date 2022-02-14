#pragma once
#include <Windows.h>


typedef LPVOID(WINAPI* virtaloc_def)(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD  flProtect);
//RtlMoveMemory - Ntdll.dll
typedef VOID (WINAPI *rtlmov_def)(VOID UNALIGNED* Destination,const VOID UNALIGNED* Source,SIZE_T Length);
//VirtualProtect - Kernel32.dll
typedef BOOL(WINAPI* virtprot_def)(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect);
//CreateThread - Kernel32.dll
typedef HANDLE(WINAPI* createthread_def)(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE  lpStartAddress, __drv_aliasesMem LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
//WaitForSingleObject - Kernel32.dll
typedef DWORD(WINAPI* waitforsingle_def)(HANDLE hHandle, DWORD  dwMilliseconds);