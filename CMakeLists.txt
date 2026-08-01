cmake_minimum_required(VERSION 3.25)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

project(InstantCompleteReset)

include($ENV{GEODE_SDK}/cmake/GeodeFile.cmake)

add_geode_mod(InstantCompleteReset)

setup_geode_mod(InstantCompleteReset)
