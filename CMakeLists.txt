cmake_minimum_required(VERSION 3.31)
project(binapi)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fsanitize=address")

add_definitions(
    -UNDEBUG
    -DDTF_HEADER_ONLY
)

include_directories(
    ./include
    $ENV{CONDA_PREFIX}/include
)

file(
    GLOB_RECURSE
    BINAPI_HEADERS
    ${CMAKE_SOURCE_DIR}/binapi/*.h
    ${CMAKE_SOURCE_DIR}/binapi/*.hpp)

file(
    GLOB_RECURSE
    BINAPI_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cc
    ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_library(
    ${PROJECT_NAME}
    SHARED
    ${BINAPI_SOURCES}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${BOOST_LIB_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
    z
    ssl
    crypto
    pthread
)

add_subdirectory(examples/trader)
add_subdirectory(examples/synchronous)
