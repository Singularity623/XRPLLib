cmake_minimum_required(VERSION 3.0)
project(XRPLLib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(CURL CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(XRPLLib src/main.cpp src/Utils.cpp src/Ledger.cpp)

target_link_libraries(XRPLLib PRIVATE nlohmann_json::nlohmann_json CURL::libcurl OpenSSL::SSL OpenSSL::Crypto)