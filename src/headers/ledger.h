// ledger.h
#pragma once

#include "utils.h"

namespace xrpl {
    class Ledger {
        public:
            Ledger(const Utils& utils);
            nlohmann::json getLatestValidatedLedger();

            nlohmann::json getLedger(const nlohmann::json& params);
            nlohmann::json getLedgerEntry(const nlohmann::json& params);
            nlohmann::json getLedgerHeader(const nlohmann::json& params);
            nlohmann::json ledgerClosed();
            nlohmann::json ledgerCurrent();
            nlohmann::json ledgerData(const nlohmann::json& params);

        private:
            Utils _utils;
    };
}