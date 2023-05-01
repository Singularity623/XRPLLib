#ifndef XRPL_LEDGER_H
#define XRPL_LEDGER_H

#include <string>
#include "utils.h"

namespace xrpl {
    class Ledger {
        public:
            std::string getLatestValidatedLEdger() const;
    };
}

#endif