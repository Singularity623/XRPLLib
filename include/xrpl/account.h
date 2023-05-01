#ifndef XRPL_ACCOUNT_H
#define XRPL_ACCOUNT_H

#include <string>
#include "utils.h"

namespace xrpl {
    class Account {  
        public:
            Account(const std::string& address);
            std::string getAccountInfo() const;
        
        private:
            std::string address_;
    };
}

#endif