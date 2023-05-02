#include "headers/ledger.h"

using namespace xrpl;

int main() 
{
    Utils utils("https://s.altnet.rippletest.net:51234");
    Ledger ledger(utils);
    // nlohmann::json latestLedger = ledger.getLatestValidatedLedger();

    // std::cout << "Latest validated ledger: " << latestLedger << std::endl;

    //std::cout << "Press Enter to see ledger closed." << std::endl;
    //std::cin.get();

    // nlohmann::json ledgerClosedResult = ledger.ledgerClosed();
    // std::cout << "Ledger Closed: " << ledgerClosedResult << std::endl;

    nlohmann::json ledgerResult = ledger.getLedger(std::nullopt);
    std::cout << "Current Ledger: " << std::endl << ledgerResult << std::endl;

    std::cout << "Press Enter to exit." << std::endl;
    std::cin.get();

    return 0;
}