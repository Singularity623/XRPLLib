cmake_minimum_required(VERSION 3.0)
project(xrpl_lib)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(CURL CONFIG REQUIRED)

add_executable(xrpl_lib src/main.cpp)

target_link_libraries(xrpl_lib PRIVATE nlohmann_json::nlohmann_json CURL::libcurl)