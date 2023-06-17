cmake_minimum_required(VERSION 3.25)
project(FC01)

set(CMAKE_CXX_STANDARD 23)

add_executable(FC01 main.cpp Equation.cpp Equation.h Statement.cpp Statement.h Grapher.cpp Grapher.h)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(FC01 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
