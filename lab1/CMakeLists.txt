cmake_minimum_required(VERSION 3.10)
project(StudentDatabase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(-Wall -Wextra -Werror -Wpedantic)
endif()

file(GLOB_RECURSE SOURCES 
    "main.cpp"
    "com/artemyasnik/*.cpp"
)

add_executable(student_app ${SOURCES})

target_include_directories(student_app PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

file(GLOB_RECURSE HEADER_FILES "com/artemyasnik/*.hpp")
foreach(HEADER_FILE ${HEADER_FILES})
    get_filename_component(HEADER_DIR ${HEADER_FILE} DIRECTORY)
    target_include_directories(student_app PRIVATE ${HEADER_DIR})
endforeach()