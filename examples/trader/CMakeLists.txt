cmake_minimum_required(VERSION 3.31)
project(trader)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_definitions(
    -UNDEBUG
    -DDTF_HEADER_ONLY
)

include_directories(
    ../../include
    $ENV{CONDA_PREFIX}/include
)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    z
    crypto
    ssl
    binapi
    pthread
)
