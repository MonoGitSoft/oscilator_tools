cmake_minimum_required(VERSION 2.8)

project(oscilator_norm)

INCLUDE_DIRECTORIES(include)

add_subdirectory(src)

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} ThreadedOscilTools pthread)
#target_link_libraries(${PROJECT_NAME} EmbeddedOscilTools)
