cmake_minimum_required(VERSION 3.10)
project(xpriv LANGUAGES C)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(FLEX_FILE ${SRC_DIR}/src/Flex/xpriv.l)
set(BISON_FILE ${SRC_DIR}/src/Bison/xpriv.y)

# Define the lexer target
FLEX_TARGET(Lexer
    ${FLEX_FILE}
    ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
)

BISON_TARGET(Parser
    ${BISON_FILE}
    ${CMAKE_CURRENT_BINARY_DIR}/xpriv.tab.c
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/xpriv.tab.h
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(EXECUTABLE_NAME xpriv)

if(WIN32)
    set(EXECUTABLE_NAME "${EXECUTABLE_NAME}.exe")
    message(STATUS "Building on Windows, executable will be ${EXECUTABLE_NAME}")
elseif(APPLE)
    message(STATUS "Building on macOS")
elseif(UNIX)
    message(STATUS "Building on Unix/Linux")
else()
    message(WARNING "Unknown OS, default settings applied")
endif()

add_executable(${EXECUTABLE_NAME}
    ${SRC_DIR}/src/main.c
    ${SRC_DIR}/src/exc/debug.c
    ${FLEX_Lexer_OUTPUTS}
    ${BISON_Parser_OUTPUTS}
)
