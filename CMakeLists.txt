cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(batstat LANGUAGES CXX)

add_library(batinfo include/batinfo.h src/batinfo.cc)
add_library(totalinfo include/totalinfo.h src/totalinfo.cc)

target_include_directories(batinfo PUBLIC "include")
target_include_directories(totalinfo PUBLIC "include")

include(FetchContent)
FetchContent_Declare(
  cxxopts
  GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
  GIT_TAG        v2.2.0
)
FetchContent_MakeAvailable(cxxopts)

add_executable(batstat src/main.cc)


target_link_libraries(${PROJECT_NAME} batinfo totalinfo cxxopts)
