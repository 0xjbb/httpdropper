#include "util.h"

#include "Obfus.h"


void DefenderEmulator() {
	long unsigned int bufsize = 257;
	CHAR user[257];

	GetUserNameA((LPSTR)user, &bufsize);

	if (user == AY_OBFUSCATE("JohnDoe")) {
		Sleep(1000);
		ExitProcess(-1);
	}
}
