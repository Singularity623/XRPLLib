#ifndef XRPL_UTILS_H
#define XRPL_UTILS_H

#include <string>
#include <stdexcept>
#include <nlohmann/json.hpp>

namespace xrpl 
{
    //Utils Class for triggering the HttpRequests and Parse The Json Data
    class Utils 
    {
        public:
            Utils(const std::string& apiUrl);
            nlohmann::json sendRequest(const std:string& request_body);
            std::string buildRequestBody(const std::string& method, const nlohmann::json& params);
            nlohmann::json getLatestValidatedLedger();
        private:
            std::string apiUrl;
    };

}

#endif