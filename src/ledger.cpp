#include "headers/ledger.h"

using namespace std;
using namespace xrpl;

Ledger::Ledger(const Utils& utils) : _utils(utils) {}

// nlohmann::json Ledger::getLatestValidatedLedger()
// {
//     nlohmann::json params = {
//         {"ledger_index", "validated"}
//     };

//     std::string requestBody = _utils.buildRequestBody("ledger", params);
//     nlohmann::json response = _utils.sendRequest(requestBody);

//     return response;
// }

nlohmann::json Ledger::getLedger(const std::optional<nlohmann::json>& params)
{
    std::string command = "ledger";

    nlohmann::json requestBody;

    if(!params)
    {
        nlohmann::json defaultParams = {
            {"ledger_index", "validated"},
            {"accounts", false},
            {"full", false},
            {"transactions", false},
            {"expand", false},
            {"owner_funds", false}
        };

        requestBody = _utils.buildRequestBody(command, defaultParams);
    }
    else
    {
        nlohmann::json requestBody = _utils.buildRequestBody(command, params.value());
    }

    std::string response;

    bool success = _utils.sendRequest(requestBody.dump(), response);

    if(!success) 
    {
        std::cerr << "Error: Unable to send request to the XRPL server." << std::endl;
        return nlohmann::json::object();
    }

    try 
    {
        nlohmann::json jsonResponse = nlohmann::json::parse(response);
        if(jsonResponse.contains("error"))
        {
            std::string errorMsg = jsonResponse["error"].get<std::string>();
            std::cerr << "Error: XRPL server responded with an error: " << errorMsg << std::endl;
            return nlohmann::json::object();
        }
        return jsonResponse;
    } 
    catch (const nlohmann::json::parse_error& e) 
    {
        std::cerr << "Error: Unable to parse response from the XRPL server: " << e.what() << std::endl;
        return nlohmann::json::object();
    }

    return response;
}

// nlohmann::json Ledger::getLedgerEntry(const nlohmann::json& params)
// {
//     std::string command = "ledger_entry";
//     nlohmann::json response = _utils.sendRequest(command, params);
//     return response;
// }

// nlohmann::json Ledger::getLedgerHeader(const nlohmann::json& params)
// {
//     std::string command = "ledger_header";
//     nlohmann::json response = _utils.sendRequest(command, params);
//     return response;
// }

// nlohmann::json Ledger::ledgerClosed()
// {
//     std::string command = "ledger_closed";
//     nlohmann::json response = _utils.sendRequest(command,nlohmann::json::object());
//     return response;
// }

// nlohmann::json Ledger::ledgerCurrent()
// {
//     std::string command = "ledger_current";
//     nlohmann::json response = _utils.sendRequest(command);
//     return response;
// }

// nlohmann::json Ledger::ledgerData(const nlohmann::json& params)
// {
//     std::string command = "ledger_data";
//     nlohmann::json response = _utils.sendRequest(command, params);
//     return response;
// }