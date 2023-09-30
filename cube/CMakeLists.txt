include_directories(include)

set(srcFiles main.cpp)
add_executable(cube ${srcFiles})
target_link_libraries(cube opengl32)
target_link_libraries(cube glad)
target_link_libraries(cube glfw)

install(TARGETS cube DESTINATION bin)
install(DIRECTORY resources/ DESTINATION bin)
install(DIRECTORY shader/ DESTINATION bin/shader)