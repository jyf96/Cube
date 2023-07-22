# pkg-config --cflags --libs x11
include_directories(../include)
add_library(agentx11 agent.cpp)
target_link_libraries(agentx11 X11)