add_compile_options("-g")
# add_compile_options("-fsanitize=address")
set(BINARY launch)

add_subdirectory(x11)
add_subdirectory(usr)
add_subdirectory(cube)

add_executable(${BINARY} main.cpp)
# target_link_libraries(${BINARY} asan)
target_link_libraries(${BINARY} pthread)
target_link_libraries(${BINARY} agentx11)
target_link_libraries(${BINARY} usr)
target_link_libraries(${BINARY} cube)
