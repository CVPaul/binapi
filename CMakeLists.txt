cmake_minimum_required(VERSION 3.31)
project(binapi)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fsanitize=address")

# 设置默认 TRADE_TYPE 值（可选）
if(NOT DEFINED TRADE_TYPE)
    set(TRADE_TYPE 0)
endif()

# 根据 TRADE_TYPE 值打印不同的信息
if(TRADE_TYPE STREQUAL "1")
    message(STATUS "TRADE_TYPE 1 selected: This is for UM.")
elseif(TRADE_TYPE STREQUAL "2")
    message(STATUS "TRADE_TYPE 2 selected: This is for CM.")
else()
    message(STATUS "Default TRADE_TYPE selected: TRADE_TYPE=${TRADE_TYPE}, this is for Spot")
endif()

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

target_compile_definitions(
    ${PROJECT_NAME}
    PUBLIC TRADE_TYPE=${TRADE_TYPE})

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
# add_subdirectory(examples/synchronous)
