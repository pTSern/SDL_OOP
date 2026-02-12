
cmake_minimum_required(VERSION 3.15)
project(SDL_OOP CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 CONFIG REQUIRED)

add_subdirectory(src/pTS)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<TARGET_NAME_IF_EXISTS:SDL2::SDL2-static> SDL2::SDL2 pTS)

