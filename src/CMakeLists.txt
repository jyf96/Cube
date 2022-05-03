set(BINARY launch)

add_subdirectory(x11)
# include_directories(/usr/include/eigen3)

# pkg-config --cflags --libs x11
add_executable(${BINARY} main.cpp)
target_link_libraries(${BINARY} pthread)
target_link_libraries(${BINARY} agentx11)
# add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})