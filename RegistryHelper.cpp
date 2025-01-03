#include "RegistryHelper.h"

BOOL RegistryHelper::ReadStringFromRegistry(HKEY hKeyParent, LPCWSTR subkey, LPCTSTR valueName, PWCHAR* readData)
{
    HKEY hKey;
    DWORD len = TOTAL_BYTES_READ;
    DWORD readDataLen = len;
    PWCHAR readBuffer = (PWCHAR)malloc(sizeof(PWCHAR) * len);
    if (readBuffer == NULL)
        return FALSE;
    //Check if the registry exists
    DWORD Ret = RegOpenKeyEx(
        hKeyParent,
        subkey,
        0,
        KEY_READ,
        &hKey
    );
    if (Ret == ERROR_SUCCESS)
    {
        Ret = RegQueryValueEx(
            hKey,
            valueName,
            NULL,
            NULL,
            (BYTE*)readBuffer,
            &readDataLen
        );
        while (Ret == ERROR_MORE_DATA)
        {
            // Get a buffer that is big enough.
            len += OFFSET_BYTES;
            readBuffer = (PWCHAR)realloc(readBuffer, len);
            readDataLen = len;
            Ret = RegQueryValueEx(
                hKey,
                valueName,
                NULL,
                NULL,
                (BYTE*)readBuffer,
                &readDataLen
            );
        }
        if (Ret != ERROR_SUCCESS)
        {
            RegCloseKey(hKey);
            return false;;
        }
        *readData = readBuffer;
        RegCloseKey(hKey);
        return true;
    }
    else
    {
        return false;
    }
}

std::string RegistryHelper::GetExamType()
{
    PWCHAR readMessage = nullptr;
    RegistryHelper* _regHelper = new RegistryHelper();
    BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_EXAMTYPE, &readMessage); //read string
    if (status == TRUE)
    {
        if (readMessage != nullptr)
        {
            std::wstring str(readMessage);
            std::string regValue(str.begin(), str.end());

            delete(readMessage);
            delete(_regHelper);
            return regValue;
        }
    }
    delete(readMessage);
    delete(_regHelper);
    return "";
}

std::string RegistryHelper::GetExamination()
{
    PWCHAR readMessage = nullptr;
    RegistryHelper* _regHelper = new RegistryHelper();
    BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_EXAMINATION, &readMessage); //read string
    if (status == TRUE)
    {
        if (readMessage != nullptr)
        {
            std::wstring str(readMessage);
            std::string regValue(str.begin(), str.end());

            delete(readMessage);
            delete(_regHelper);
            return regValue;
        }
    }
    delete(readMessage);
    delete(_regHelper);
    return "";
}

std::string RegistryHelper::GetExamYear()
{
    PWCHAR readMessage = nullptr;
    RegistryHelper* _regHelper = new RegistryHelper();
    BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_EXAMYEAR, &readMessage); //read string
    if (status == TRUE)
    {
        if (readMessage != nullptr)
        {
            std::wstring str(readMessage);
            std::string regValue(str.begin(), str.end());

            delete(readMessage);
            delete(_regHelper);
            return regValue;
        }
    }
    delete(readMessage);
    delete(_regHelper);
    return "";
}

std::string RegistryHelper::GetJobS()
{
    PWCHAR readMessage = nullptr;
    RegistryHelper* _regHelper = new RegistryHelper();
    BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_JOB, &readMessage); //read string
    if (status == TRUE)
    {
        if (readMessage != nullptr)
        {
            std::wstring str(readMessage);
            std::string regValue(str.begin(), str.end());

            delete(readMessage);
            delete(_regHelper);
            return regValue;
        }
    }
    delete(readMessage);
    delete(_regHelper);
    return "";
}

std::string RegistryHelper::GetOpeartorId()
{
    PWCHAR readMessage = nullptr;
    RegistryHelper* _regHelper = new RegistryHelper();
    BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_OPERATORID, &readMessage); //read string
    if (status == TRUE)
    {
        if (readMessage != nullptr)
        {
            std::wstring str(readMessage);
            std::string regValue(str.begin(), str.end());

            delete(readMessage);
            delete(_regHelper);
            return regValue;
        }
    }
    delete(readMessage);
    delete(_regHelper);
    return "";
}

std::string RegistryHelper::GetDeviceId()
{
    PWCHAR readMessage = nullptr;
    RegistryHelper* _regHelper = new RegistryHelper();
    BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_DEVICEID, &readMessage); //read string
    if (status == TRUE)
    {
        if (readMessage != nullptr)
        {
            std::wstring str(readMessage);
            std::string regValue(str.begin(), str.end());

            delete(readMessage);
            delete(_regHelper);
            return regValue;
        }
    }
    delete(readMessage);
    delete(_regHelper);
    return "";
}

std::string RegistryHelper::GetShortSubject()
{
    PWCHAR readMessage = nullptr;
    RegistryHelper* _regHelper = new RegistryHelper();
    BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_SHORTSUBJECT, &readMessage); //read string
    if (status == TRUE)
    {
        if (readMessage != nullptr)
        {
            std::wstring str(readMessage);
            std::string regValue(str.begin(), str.end());

            delete(readMessage);
            delete(_regHelper);
            return regValue;
        }
    }
    delete(readMessage);
    delete(_regHelper);
    return "";
}

std::string RegistryHelper::GetPaper()
{
    PWCHAR readMessage = nullptr;
    RegistryHelper* _regHelper = new RegistryHelper();
    BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_PAPER, &readMessage); //read string
    if (status == TRUE)
    {
        if (readMessage != nullptr)
        {
            std::wstring str(readMessage);
            std::string regValue(str.begin(), str.end());

            delete(readMessage);
            delete(_regHelper);
            return regValue;
        }
    }
    delete(readMessage);
    delete(_regHelper);
    return std::string();
}

std::string RegistryHelper::GetSOSDirectory()
{
    PWCHAR readMessage = nullptr;
    RegistryHelper* _regHelper = new RegistryHelper();
    BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_SOSDIR, &readMessage); //read string
    if (status == TRUE)
    {
        if (readMessage != nullptr)
        {
            std::wstring str(readMessage);
            std::string regValue(str.begin(), str.end());

            delete(readMessage);
            delete(_regHelper);
            return regValue;
        }
    }
    delete(readMessage);
    delete(_regHelper);
    return "";
}

std::string RegistryHelper::GetScanType()
{
    PWCHAR readMessage = nullptr;
    RegistryHelper* _regHelper = new RegistryHelper();
    BOOL status = _regHelper->ReadStringFromRegistry(HKEY_CURRENT_USER, REGISTRY_NECOSCAN, REGISTRY_NECOSCAN_SUBKEY_SCANTYPE, &readMessage); //read string
    if (status == TRUE)
    {
        if (readMessage != nullptr)
        {
            std::wstring str(readMessage);
            std::string regValue(str.begin(), str.end());

            delete(readMessage);
            delete(_regHelper);
            return regValue;
        }
    }
    delete(readMessage);
    delete(_regHelper);
    return "";
}
