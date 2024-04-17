cmake_minimum_required(VERSION 3.20)

project(MarketMaker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(
    Boost 1.76.0 
    REQUIRED COMPONENTS 
        iostreams 
        # filesystem
)

add_subdirectory(src)
target_include_directories(
    MarketMaker 
    PUBLIC  include)
target_link_libraries(
    MarketMaker 
    PUBLIC  Boost::iostreams 
            # Boost::filesystem
)