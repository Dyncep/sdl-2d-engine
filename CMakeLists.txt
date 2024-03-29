cmake_minimum_required(VERSION 3.2)
project(SDL2DEngine)

set(CMAKE_CXX_VERSION 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_subdirectory(submodules/light-ecs)
add_subdirectory(submodules/glm)

add_library(SDLEngine
  src/Application.cpp
  src/TextureHelper.cpp
  src/Collision.cpp
  src/Debug/Assertion.cpp
  src/Events/SDLEventHandler.cpp
  src/Events/ApplicationEventHandler.cpp
)
target_link_libraries(SDLEngine PUBLIC SDL2)
target_link_libraries(SDLEngine PUBLIC SDL2_image)
target_link_libraries(SDLEngine PUBLIC ECS)
target_link_libraries(SDLEngine PUBLIC glm)
target_include_directories(SDLEngine PUBLIC include/)

add_executable(app src/Main.cpp)

target_link_libraries(app PUBLIC SDLEngine)
