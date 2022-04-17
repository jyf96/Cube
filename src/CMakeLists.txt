set(BINARY ${CMAKE_PROJECT_NAME}_run)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

# pkg-config --cflags --libs x11
add_executable(${BINARY} ${SOURCES})
include_directories(/usr/include/eigen3)
target_link_libraries(${BINARY} X11)
# add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})