cmake_minimum_required(VERSION 3.20)
project(flappydragon)

set(CMAKE_CXX_STANDARD 14)

add_executable(flappydragon main.cpp Animation.cpp Animation.h Dragon.cpp Dragon.h Wall.cpp Wall.h)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR C:/Program Files (x86)/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/Program Files (x86)/SFML/include)

target_link_libraries(flappydragon sfml-system sfml-window sfml-graphics sfml-audio sfml-network)