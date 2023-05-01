#ifndef XRPL_UTILS_H
#define XRPL_UTILS_H

#include <string>
#include <stdexcept>
#include <nlohmann/json.hpp>

namespace xrpl {
    
    //Exception Class for XRPL Errors
    class XrplException : public std::runtime_error {
        public:
            explicit XrplException(const std::string& message) : std::runtime_error(message) {}
    };

    //Utils Class for triggering the HttpRequests and Parse The Json Data
    class Utils {
        public:
            static std::string httpRequest(const std::string& url, const std::string& post_data = "");
            static nlohmann::json parseJson(const std::string& jsonString);
    };

}

#endif