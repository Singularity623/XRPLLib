#ifndef XRPL_XRPLEXCEPTION_H
#define XRPL_XRPLEXCEPTION_H

#include <string>
#include <stdexcept>

namespace xrpl 
{
    //Exception Class for XRPL Errors
    class XrplException : public std::runtime_error 
    {
        public:
            explicit XrplException(const std::string& message) : std::runtime_error(message) {}
    };
}

#endif