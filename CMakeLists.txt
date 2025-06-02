cmake_minimum_required(VERSION 3.10)
project(xpriv LANGUAGES C)

# Platform-specific CMake
if(WIN32)
    include(cmake/windows.cmake)
elseif(APPLE OR UNIX)
    include(cmake/unix.cmake)
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

add_executable(xpriv ${XPRIV_SOURCES})
target_include_directories(xpriv PRIVATE ${XPRIV_INCLUDE_DIRS})
