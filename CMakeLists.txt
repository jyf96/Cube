cmake_minimum_required(VERSION 3.0.0)
project(cube VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)

# 输出 compile_commands.json 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INSTALL_PREFIX ./)
add_subdirectory(lib)
include_directories(glfw/include)
include_directories(glad/include)
include_directories(glm)
include_directories(stb)
add_subdirectory(cube)