#include <iostream>
#include "headers/ledger.h"

using namespace xrpl;

int main() 
{
    Utils utils("https://s.altnet.rippletest.net:51234");
    Ledger ledger(utils);
    nlohmann::json latestLedger = ledger.getLatestValidatedLedger();

    std::cout << "Latest validated ledger: " << latestLedger << std::endl;

    std::cout << "Press Enter to exit." << std::endl;
    std::cin.get();

    return 0;
}