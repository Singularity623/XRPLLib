
#include "headers/utils.h"

using namespace std;
using namespace xrpl;

Utils::Utils(const::string& apiUrl) : _apiUrl(apiUrl) {}

static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

nlohmann::json Utils::sendRequest(const std::string& requestBody)
{
    CURL * curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, _apiUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestBody.c_str());
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); //SH: this is not validate the peer, debugging
        curl_easy_setopt(curl, CURLOPT_CAINFO, "..\\..\\ca-bundle.crt");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
        {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return nlohmann::json::parse(readBuffer);
}
nlohmann::json Utils::sendRequest(const std::string& command, const nlohmann::json& params)
{
    std::string payload = buildRequestPayload(command, params);

    return Utils::sendRequest(payload);
}


std::string Utils::buildRequestBody(const std::string& method, const nlohmann::json& params)
{
    nlohmann::json request = {
        {"method", method},
        {"params", {params}}
    };

    return request.dump();
}

std::string Utils::buildRequestPayload(const std::string& command, const nlohmann::json& params)
{
    // nlohmann::json payload = {
    //     {"id", 1},
    //     {"jsonrpc", "2.0"},
    //     {"method", command}
    // };

    //  if(!params.empty()) {
    //      payload["params"] = {params};
    //  }


    nlohmann::json request = {
        {"method","ledger_closed"},
        {"params", {params}}
    };

    return request.dump();
}

nlohmann::json Utils::processResponse(const nlohmann::json& response)
{
    if(response.contains("error"))
    {
        std::cerr << "Error in JSON-RPC response: " << response["error"]["message"] << std::endl;

        return nlohmann::json::object();
    }

    return response["result"];
}