add_executable(myWindow main.cpp show.cpp cube.cpp)
# pkg-config --cflags --libs x11
include_directories(/usr/include/eigen3)
target_link_libraries(myWindow X11)