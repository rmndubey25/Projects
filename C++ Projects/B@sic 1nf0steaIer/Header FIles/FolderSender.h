#pragma once
#include <string>

bool SendFolderToDiscord(
    const std::wstring& folderPath,
    const std::wstring& webhookUrl
);
