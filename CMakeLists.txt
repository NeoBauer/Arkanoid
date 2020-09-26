cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Arkanoid)

SET(GCC_COVERAGE_LINK_FLAGS "-lX11 -lGL -lpthread -lpng -lstdc++fs")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

set(SRC Game.cpp)

add_library(LIB STATIC ${SRC})
add_executable(${PROJECT_NAME} main.cpp )
target_link_libraries(${PROJECT_NAME} ${LIB})
target_link_libraries(${PROJECT_NAME} PRIVATE X11 GL pthread png stdc++fs)

# target_compile_options(${PROJECT_NAME} PRIVATE -lX11 -lGL -lpthread -lpng -lstdc++fs)