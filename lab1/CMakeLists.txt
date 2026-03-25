cmake_minimum_required(VERSION 3.10)
project(StudentDatabase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wextra -Werror -Wpedantic)
endif()

# Пути поиска
include_directories(.)
include_directories(com/artemyasnik/classes)
include_directories(com/artemyasnik/commands)
include_directories(com/artemyasnik/interfaces)

# Поиск исходников
file(GLOB_RECURSE SOURCES 
    "main.cpp"
    "com/artemyasnik/classes/*.cpp"
    "com/artemyasnik/commands/*.cpp"
)

add_executable(student_app ${SOURCES})