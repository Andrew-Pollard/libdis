cmake_minimum_required(VERSION 3.8)

project(libdis)

file(GLOB LIB_DIS_SOURCE
    "include/*"
    "src/*"
)

add_library(libdis SHARED ${LIB_DIS_SOURCE})

target_include_directories(libdis PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)