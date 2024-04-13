cmake_minimum_required(VERSION 3.5)

project(planning_uviz LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -Wall -Werror -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -Werror -pthread")

find_package(Qt5 REQUIRED Widgets
                          PrintSupport
                          )

add_library(planning_uviz_lib STATIC  main.cpp
                                      planning_uviz.cpp
                                      draw_ego_state.cc
                                      draw_obj_state.cc

                                      planning_uviz_common.cc
                                      QPainter_wrapper.cc
                                      uviz_keybroad.cc
                                      uviz_mouse.cc
                                      ../base.cc

                                      uviz_data.cc
                                      )
target_link_libraries(planning_uviz_lib PRIVATE  Qt5::Widgets
                                                 Qt5::PrintSupport
                                                 )
