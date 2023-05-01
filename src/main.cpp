#include <iostream>
#include "xrpl/utils.h"

using namespace xrpl;

int main() 
{
    Utils utils("https://s.altnet.rippletest.net:51234");

    nlohmann::json latestLedger = utils.getLatestValidatedLedger();

    std::cout << "Latest validated ledger: " << latestLedger << std::endl;

    std::cout << "Press Enter to exit." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return 0;
}