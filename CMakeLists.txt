cmake_minimum_required(VERSION 3.8)

project(dis)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

add_library(dis
    "include/dis.h"
    "src/dis.c"
)

set_target_properties(dis PROPERTIES
    VERSION 0.1
    C_EXTENSIONS OFF
    C_STANDARD 11
    POSITION_INDEPENDENT_CODE ON
)

if (BUILD_SHARED_LIBS)
    set_property(TARGET dis PROPERTY DEFINE_SYMBOL DIS_BUILD_SHARED)

    if (UNIX)
        # Hide symbols not explicitly tagged for export from the shared library
        target_compile_options(dis PRIVATE "-fvisibility=hidden")
    endif()
endif()

target_include_directories(dis PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
