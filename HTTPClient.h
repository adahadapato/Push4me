#pragma once
#include <string>
#include <curl/curl.h>
#include <curl/easy.h>


#define HTTP_SERVER_31_MANAGER_API_BASE_URL "http://10.0.1.31/ManagerApi/api/"

class HTTPClient
{
private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
    {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

public:
    void Post(std::string url, std::string data);
};

