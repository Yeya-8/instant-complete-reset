cmake_minimum_required(VERSION 3.25)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

project(InstantCompleteReset VERSION 1.0.0 LANGUAGES CXX)

find_package(Geode REQUIRED)

add_geode_mod(
    instant_complete_reset
    VERSION 1.0.0
    DEVELOPER Yeya
)

setup_geode_mod(instant_complete_reset)
