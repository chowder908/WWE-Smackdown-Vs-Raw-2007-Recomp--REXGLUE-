
# svr2007 - ReXGlue Recompiled Project
#
# This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(svr2007 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(generated/rexglue.cmake)

# Sources
set(SVR2007_SOURCES
    src/main.cpp
)

if(WIN32)
    add_executable(svr2007 WIN32 ${SVR2007_SOURCES})
else()
    add_executable(svr2007 ${SVR2007_SOURCES})
endif()

rexglue_setup_target(svr2007)
