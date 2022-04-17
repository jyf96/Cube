cmake_minimum_required(VERSION 3.0.0)
project(myX11 VERSION 0.1.0)
SET(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 20)

include_directories(src)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

add_subdirectory(src bin)
# add_subdirectory(lib/googletest gtest)
# add_subdirectory(test test)