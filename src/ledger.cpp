#include "xrpl/ledger.h"

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