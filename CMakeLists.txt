cmake_minimum_required(VERSION 3.20)

project(MarketMaker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
target_include_directories(MarketMaker PUBLIC include)