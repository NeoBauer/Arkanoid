cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(Arkanoid)

add_executable(${PROJECT_NAME} main.cpp Game.cpp Ball.cpp Padle.cpp olcPixelGameEngine.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC X11 GL pthread png stdc++fs)
