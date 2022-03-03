add_executable(myX11 myX11.cpp cube.cpp)
# pkg-config --cflags --libs x11
target_link_libraries(myX11 X11)