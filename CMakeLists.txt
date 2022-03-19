cmake_minimum_required(VERSION 3.0.0)
project(myX11 VERSION 0.1.0)
SET(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()
add_subdirectory(src bin)
include(CPack)
