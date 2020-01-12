cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(batstat)

add_library(batinfo
    include/batinfo.h
    src/batinfo.cc
)


target_include_directories(
  batinfo
  PUBLIC
    "include"
)

add_executable(batstat
  src/main.cc
)

target_link_libraries(batstat batinfo)
