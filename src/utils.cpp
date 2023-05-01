
#include "Utils.h"
#include <iostream>
#include <curl/curl.h>

Utils::Utils(const::string& apiUrl) : apiUrl(apiUrl) {}

static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

nlohmann::json Utils::sendRequest(const std::string& requestBody)
{
    CURL * curl;
    CURLcode res;
    std::String readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_east_init();
    if(curl)
    {
        curl_easy_Setopt(curl, CURLOPT_URL, apiUrl.c_str());
        curl_easy_Setopt(curl, CURLOPT_POSTFIELDS, requestBody.c_str());
        curl_easy_Setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_Setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
        {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std:endl;
        }
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return nlohmann::json::parse(readBuffer);
}

std::string Utils::buildRequestBody(const std::string& method, const nlohmann::json& params)
{
    nlohmann::json request = {
        {"method", method},
        {"params", {params}}
    };

    request.dump();
}

nlohmann::json Utils::getLatestValidatedLedger()
{
    nlohmann::json params = {
        {"ledger_index", "validated"}
    };

    std::string requestBody = buildRequestBody("ledger", params);
    nlohmann::json response = sendRequest(requestBody);

    return response;
}