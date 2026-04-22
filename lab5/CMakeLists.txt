cmake_minimum_required(VERSION 3.10)
project(Lab5_Templates)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    main.cpp
    src/array_functions.cpp
)

add_executable(lab5 ${SOURCES})

target_compile_options(lab5 PRIVATE -Wall -Wextra)