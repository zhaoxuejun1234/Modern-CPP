cmake_minimum_required(VERSION 3.10)
project(Features_1)

set(CMAKE_CXX_STANDARD 14)
find_library(jsonlib jsoncpp /usr/local/lib)
add_executable(Features_1
           15_Json_cpp.cpp)
target_link_libraries(Features_1 ${jsonlib})
#find_package(Threads REQUIRED)
#target_link_libraries(Features_1 Threads::Threads)