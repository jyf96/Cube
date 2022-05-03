# pkg-config --cflags --libs x11
include_directories(../include)
add_library(usr usr.cpp)
target_link_libraries(usr agentx11)