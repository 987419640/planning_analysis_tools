cmake_minimum_required(VERSION 3.2)

project(main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE "Release")

add_subdirectory(planning_uviz)

add_executable(${PROJECT_NAME}  main.cc
                                planning_uviz/uviz_data.cc
                                )
target_link_libraries(${PROJECT_NAME} planning_uviz_lib
                                      pthread
                                      )