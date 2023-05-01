#ifndef XRPL_LEDGER_H
#define XRPL_LEDGER_H

#pragma once

#include "utils.h"

namespace xrpl {
    class Ledger {
        public:
            Ledger(const Utils& utils);
            nlohmann::json getLatestValidatedLedger();

            nlohmann::json getLedger(const std::string& options);
            nlohmann::json getLedgerEntry(const std::string& options);
            nlohmann::json getLedgerHeader(const std::string& options);
            nlohmann::json ledgerClosed();
            nlohmann::json ledgerCurrent();
            nlohmann::json ledgerData(const std::string& options);

        private:
            Utils _utils;
    };
}

#endif