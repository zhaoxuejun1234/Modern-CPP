cmake_minimum_required(VERSION 3.25)
project(Features_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Features_1
          14_multi_state.cpp)
find_package(Threads REQUIRED)
target_link_libraries(Features_1 Threads::Threads)