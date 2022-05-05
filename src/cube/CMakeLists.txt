include_directories(../include)
include_directories(/usr/include/eigen3)
add_library(cube cube.cpp)
target_link_libraries(cube agentx11)