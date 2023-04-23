cmake_minimum_required(VERSION 3.9)

project(v2x_software)

SET(L2_SRC
    ./src/l2/raw_eth/raw_eth.cc)

SET(SRC
    ${L2_SRC}
    ./src/v2xd.cc)

SET(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wno-unused-parameter")

include_directories(./src/
                    ./src/l2/
                    ./src/l2/raw_eth/)

add_executable(v2xd ${SRC})
