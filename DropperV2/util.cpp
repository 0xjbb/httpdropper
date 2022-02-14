#include "util.h"


void DefenderEmulator() {
	long unsigned int bufsize = 257;
	CHAR user[257];

	GetUserNameA((LPSTR)user, &bufsize);

	if (user == "JohnDoe") {
		std::cout << "fuck youuuuuuuuuu" << std::endl;
		Sleep(1000);
		ExitProcess(-1);
	}
}