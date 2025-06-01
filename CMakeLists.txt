cmake_minimum_required(VERSION 3.10)
project(xpriv LANGUAGES C)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(INCLUDE_DIR ${SRC_DIR}/src/include)

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

# Include directories
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${INCLUDE_DIR}
)

# OS-specific main file logic
if(WIN32)
    set(MAIN_FILE ${SRC_DIR}/src/mains/Windows/windowsmain.c)
    set(EXECUTABLE_NAME "xpriv.exe")
    message(STATUS "Building on Windows, using windowsmain.c")
elseif(APPLE)
    set(MAIN_FILE ${SRC_DIR}/src/mains/Mac-os/macosmain.c)
    set(EXECUTABLE_NAME "xpriv")
    message(STATUS "Building on macOS, using macosmain.c")
elseif(UNIX)
    set(MAIN_FILE ${SRC_DIR}/src/mains/main.c)
    set(EXECUTABLE_NAME "xpriv")
    message(STATUS "Building on Unix/Linux, using main.c")
else()
    set(MAIN_FILE ${SRC_DIR}/src/mains/main.c)
    set(EXECUTABLE_NAME "xpriv")
    message(WARNING "Unknown OS. Defaulting to main.c")
endif()

# Build the executable
add_executable(${EXECUTABLE_NAME}
    ${MAIN_FILE}
    ${SRC_DIR}/src/etc/debug.c
    ${FLEX_Lexer_OUTPUTS}
    ${BISON_Parser_OUTPUTS}
)

target_compile_definitions(${EXECUTABLE_NAME} PRIVATE XPRIV_DEBUG)
