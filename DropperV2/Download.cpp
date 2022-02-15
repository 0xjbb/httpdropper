#include "Download.h"

std::vector<char> Download::DownloadFile(std::string szUrl){
    HINTERNET hInetOpen = nullptr, hInetUrl = nullptr;
    char szTemp[1024] = "";
    DWORD dwBytesRead, dwRead;

    std::vector<char> data;

    hInetOpen = InternetOpen(" ", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);

    if (hInetOpen != INVALID_HANDLE_VALUE)
    {
        hInetUrl = InternetOpenUrl(hInetOpen, szUrl.c_str(), NULL, NULL, INTERNET_FLAG_DONT_CACHE, NULL);

        if (hInetUrl)
        {
            do
            {
                InternetReadFile(hInetUrl, szTemp, 1024, &dwBytesRead);
                data.insert(data.end(), std::begin(szTemp), std::end(szTemp));

            } while (dwBytesRead == 1024);

            InternetCloseHandle(hInetUrl);
        }

        InternetCloseHandle(hInetOpen);
    }

    return data;
}