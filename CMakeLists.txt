cmake_minimum_required(VERSION 2.6)
project(graph_kahn)

add_executable(graph_kahn main.cpp)

install(TARGETS graph_kahn RUNTIME DESTINATION bin)
