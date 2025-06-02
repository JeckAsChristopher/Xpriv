set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${SRC_DIR}/include)
set(ETC_DIR ${SRC_DIR}/etc)

# Flex/Bison setup
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(FLEX_FILE ${SRC_DIR}/Flex/xpriv.l)
set(BISON_FILE ${SRC_DIR}/Bison/Linux-Mac-Os/xpriv.y)
set(GENERATED_DIR ${CMAKE_CURRENT_BINARY_DIR})

FLEX_TARGET(Lexer ${FLEX_FILE} ${GENERATED_DIR}/lex.yy.c)
BISON_TARGET(Parser ${BISON_FILE} ${GENERATED_DIR}/xpriv.tab.c
    DEFINES_FILE ${GENERATED_DIR}/xpriv.tab.h
)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

# Source files
set(XPRIV_SOURCES
    ${GENERATED_DIR}/lex.yy.c
    ${GENERATED_DIR}/xpriv.tab.c
    ${SRC_DIR}/mains/main.c
    ${ETC_DIR}/debug.c
)

# Include directories
set(XPRIV_INCLUDE_DIRS
    ${INCLUDE_DIR}
    ${GENERATED_DIR}
)

include_directories(${XPRIV_INCLUDE_DIRS})
