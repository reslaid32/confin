cmake_minimum_required(VERSION 3.10)
project(cftest)

# Detect the compiler and set flags
if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4 /WX")
elseif(CMAKE_C_COMPILER_ID STREQUAL "Clang" OR CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
else()
    message(FATAL_ERROR "Unsupported compiler: ${CMAKE_C_COMPILER_ID}")
endif()

# Source files
set(SRC_DIR .)
set(TEST_DIR tests)
set(CONFIN_DIR confin)
set(SRC_FILES
    ${SRC_DIR}/main.c
    ${CONFIN_DIR}/confin.c
    ${TEST_DIR}/unit.c
)

# Add executable
add_executable(main ${SRC_FILES})
