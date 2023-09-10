cmake_minimum_required(VERSION 3.14)

project(cpp_learning)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/8a6feabf04bec8fb125e0df0ad1195c42350725f.zip
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

FetchContent_MakeAvailable(googletest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

file(GLOB_RECURSE SRC "src/*.cpp")
add_library(src SHARED ${SRC})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
