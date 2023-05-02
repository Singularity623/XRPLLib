// ledger.h
#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "utils.h"
#include <optional>

namespace xrpl 
{
    class Ledger 
    {
        public:
            Ledger(const Utils& utils);

            nlohmann::json getLedger(const std::optional<nlohmann::json>& params);
            nlohmann::json getLedgerEntry(const std::optional<nlohmann::json>& params);
            nlohmann::json getLedgerHeader(const std::optional<nlohmann::json>& params);
            nlohmann::json ledgerClosed();
            nlohmann::json ledgerCurrent();
            nlohmann::json ledgerData(const std::optional<nlohmann::json>& params);

        private:
            Utils _utils;
    };
}