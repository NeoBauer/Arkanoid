cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(Arkanoid)

##Insert project source files here.##
set(SOURCES
    Game.cpp
    Ball.cpp
    Padle.cpp 
    olcPixelGameEngine.cpp

)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCES})
add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
# target_link_libraries(${PROJECT_NAME} X11 GL pthread png stdc++fs)
target_compile_options(${PROJECT_NAME} PRIVATE -lX11 -lGL -lpthread -lpng -lstdc++fs)
