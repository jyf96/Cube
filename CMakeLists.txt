cmake_minimum_required(VERSION 3.0.0)
project(cube VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)

# 输出 compile_commands.json 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INSTALL_PREFIX ./)
add_subdirectory(lib)
include_directories(lib/glfw/include)
include_directories(lib/glad/include)
include_directories(lib/stb)
add_subdirectory(cube)