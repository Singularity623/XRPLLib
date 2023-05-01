#ifndef XRPL_LEDGER_H
#define XRPL_LEDGER_H

#pragma once

#include "utils.h"

namespace xrpl {
    class Ledger {
        public:
            Ledger(const Utils& utils);
            nlohmann::json getLatestValidatedLedger();
        private:
            Utils _utils;
    };
}

#endif