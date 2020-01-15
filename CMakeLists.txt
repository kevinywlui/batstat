cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(batstat LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include(FetchContent)
FetchContent_Declare(
  cxxopts
  GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
  GIT_TAG        v2.2.0
)
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        6.1.2
)
FetchContent_MakeAvailable(cxxopts fmt)

add_library(batinfo STATIC include/batinfo.h src/batinfo.cc)
target_include_directories(batinfo PUBLIC "include")

add_library(totalinfo STATIC include/totalinfo.h src/totalinfo.cc)
target_include_directories(totalinfo PUBLIC "include")
target_link_libraries(totalinfo fmt batinfo)


add_executable(batstat src/main.cc)
target_link_libraries(${PROJECT_NAME} totalinfo cxxopts fmt)
