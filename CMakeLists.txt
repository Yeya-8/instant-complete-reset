cmake_minimum_required(VERSION 3.25)

project(InstantCompleteReset VERSION 1.0.0 LANGUAGES CXX)

include($ENV{GEODE_SDK}/cmake/GeodeFile.cmake)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

setup_geode_mod(${PROJECT_NAME})
