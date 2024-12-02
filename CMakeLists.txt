cmake_minimum_required(VERSION 3.25)

project(laurent LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp include/*.hpp)
add_executable(laurent ${SOURCE_FILES})

find_library(DPP_LIB dpp REQUIRED)
target_link_libraries(laurent PRIVATE ${DPP_LIB})
