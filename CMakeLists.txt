cmake_minimum_required(VERSION 3.2)
project(SDL2DEngine)

set(CMAKE_CXX_VERSION 20)

find_package(SDL2 REQUIRED)

add_library(SDLEngine
  src/Application.cpp
  src/Debug/Assertion.cpp
  src/Events/SDLEventHandler.cpp
  src/Events/ApplicationEventHandler.cpp
)
target_link_libraries(SDLEngine PUBLIC SDL2)
target_include_directories(SDLEngine PUBLIC include/)

add_executable(app src/Main.cpp)

target_link_libraries(app PUBLIC SDLEngine)
