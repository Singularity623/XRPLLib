// Utils.h
#pragma once

#include <string>
#include <stdexcept>
#include <nlohmann/json.hpp>
#include <iostream>
#include <curl/curl.h>

using namespace std;

namespace xrpl 
{
    //Utils Class for triggering the HttpRequests and Parse The Json Data
    class Utils
    {
        public:
            Utils(const std::string& apiUrl);
            
            bool sendRequest(const std::string& request, std::string& response);
            
            nlohmann::json buildRequestBody(const std::string& method, const nlohmann::json& params);
            
        private:
            std::string _apiUrl;
    };

}