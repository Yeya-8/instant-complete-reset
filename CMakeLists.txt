cmake_minimum_required(VERSION 3.25)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

project(InstantCompleteReset VERSION 1.0.0 LANGUAGES CXX)

# Tell Geode explicitly where the SDK folder lives so it can read its VERSION file
set(GEODE_SDK_PATH "$ENV{GEODE_SDK}")

include("${GEODE_SDK_PATH}/cmake/GeodeFile.cmake")

setup_geode_mod(InstantCompleteReset)
