# wwesmackdownvsraw2007 - ReXGlue Recompiled Project
#
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(wwesmackdownvsraw2007 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(generated/rexglue.cmake)

# Sources
set(WWESMACKDOWNVSRAW2007_SOURCES
    src/main.cpp
)

if(WIN32)
    add_executable(wwesmackdownvsraw2007 WIN32 ${WWESMACKDOWNVSRAW2007_SOURCES})
else()
    add_executable(wwesmackdownvsraw2007 ${WWESMACKDOWNVSRAW2007_SOURCES})
endif()

rexglue_setup_target(wwesmackdownvsraw2007)
target_link_libraries(wwesmackdownvsraw2007 PRIVATE imgui::imgui)
target_include_directories(wwesmackdownvsraw2007 PRIVATE
    ${CMAKE_BINARY_DIR}/rexglue-sdk/include
)