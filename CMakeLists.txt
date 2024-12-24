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

file(GLOB BINAPI_HEADERS ${CMAKE_SOURCE_DIR}/binapi/*.h ${CMAKE_SOURCE_DIR}/binapi/*.hpp)
#set(BINAPI_HEADERS
#    binapi/api.hpp
#    binapi/flatjson.hpp
#    binapi/dtf.hpp
#    binapi/double_type.hpp
#    binapi/enums.hpp
#    binapi/errors.hpp
#    binapi/invoker.hpp
#    binapi/message.hpp
#    binapi/pairslist.hpp
#    binapi/reports.hpp
#    binapi/tools.hpp
#    binapi/types.hpp
#    binapi/websocket.hpp
#)
#
file(GLOB_RECURSE BINAPI_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cc ${CMAKE_SOURCE_DIR}/src/*.cpp)
#set(BINAPI_SOURCES
#    src/api.cpp
#    src/enums.cpp
#    src/errors.cpp
#    src/pairslist.cpp
#    src/reports.cpp
#    src/tools.cpp
#    src/types.cpp
#    src/websocket.cpp
#)

add_executable(
    ${PROJECT_NAME}
    #
    main.cpp
    #
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
