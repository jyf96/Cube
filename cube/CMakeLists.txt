include_directories(include)

add_executable(cube main.cpp)
target_link_libraries(cube opengl32)
target_link_libraries(cube glad)
target_link_libraries(cube glfw)

install(TARGETS cube DESTINATION bin)
install(DIRECTORY resources/ DESTINATION bin)