cmake_minimum_required(VERSION 3.16.3)

project(BusyBiscuits_Database)

set(CMAKE_CXX_STANDARD 14)

add_executable(main ./src/main.cpp ./src/database/database.cpp)