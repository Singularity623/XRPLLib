#include "headers/ledger.h"

using namespace std;
using namespace xrpl;

Ledger::Ledger(const Utils& utils) : _utils(utils) {}

nlohmann::json Ledger::getLatestValidatedLedger()
{
    nlohmann::json params = {
        {"ledger_index", "validated"}
    };

    std::string requestBody = _utils.buildRequestBody("ledger", params);
    nlohmann::json response = _utils.sendRequest(requestBody);
    
    return response;
}

nlohmann::json Ledger::getLedger(const std::string& params)
{
    std::string command = "getLedger";
    nlohmann::json response = _utils.sendRequest(command, params);
    return response;
}

nlohmann::json Ledger::getLedgerEntry(const std::string& params)
{
    std::string command = "ledger_entry";
    nlohmann::json response = _utils.sendRequest(command, params);
    return response;
}

nlohmann::json Ledger::getLedgerHeader(const std::string& params)
{
    std::string command = "ledger_header";
    nlohmann::json response = _utils.sendRequest(command, params);
    return response;
}