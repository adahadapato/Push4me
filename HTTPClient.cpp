#include "HTTPClient.h"

void HTTPClient::Post(std::string url, std::string data)
{
    // Initialize the curl library
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Create a curl handle
    CURL* handle = curl_easy_init();

    struct curl_slist* headers = NULL;
    //curl_slist_append(headers, "http://10.0.1.31/managerapi/api/subjects/bece/scanning/obj/2024");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);


    // Set the request method to POST
    curl_easy_setopt(handle, CURLOPT_CUSTOMREQUEST, "POST");
    //char* _data = data;
    // Set the request body
    curl_easy_setopt(handle, CURLOPT_POSTFIELDS, data.c_str());

    // Set the URL to request
    curl_easy_setopt(handle, CURLOPT_URL, url.c_str());

   curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, WriteCallback);

    // Set the user pointer to be an ostream to which the response will be written
    //std::ostringstream response;
    std::string response;
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);

    // Perform the request
    CURLcode result = curl_easy_perform(handle);
    long http_code = 0;
    curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &http_code);
    // Check the result
    if (result != CURLE_OK) {
        // If the request failed, print an error message
        //std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(result) << std::endl;
       // _response = _utilService->to_wstring(curl_easy_strerror(result));
    }
    else {


        // If the request was successful, print the response
        //std::cout << response << std::endl;
        //_response = to_wstring(response.str());

        //_responseResult.code = http_code;
        //std::string str = std::quoted(response.str());
        //_responseResult.content = _utilService->to_wstring(response);
    }

    // Clean up
    curl_easy_cleanup(handle);
    curl_global_cleanup();
}
