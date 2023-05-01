cmake_minimum_required(VERSION 3.0)
project(xrpl_lib)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(CURL CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(xrpl_lib src/main.cpp src/Utils.cpp src/Ledger.cpp)

target_link_libraries(xrpl_lib PRIVATE nlohmann_json::nlohmann_json CURL::libcurl OpenSSL::SSL OpenSSL::Crypto)