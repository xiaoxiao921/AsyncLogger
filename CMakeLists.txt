cmake_minimum_required(VERSION 3.20)

project(AsyncLogger LANGUAGES CXX VERSION 0.0.1 DESCRIPTION "A lightweight C++20 asyncronous logger.")

set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(PUBLIC_HEADER_DIR "${PROJECT_SOURCE_DIR}/include")

# check std::format support
include(CheckIncludeFileCXX)
check_include_file_cxx("format" CXX_FORMAT_SUPPORT)

file(GLOB_RECURSE SRC_FILES
    "${SRC_DIR}/**.cpp"
    "${SRC_DIR}/**.hpp"
)
file(GLOB_RECURSE PUBLIC_HEADER_FILES
    "${PUBLIC_HEADER_DIR}/**.hpp"
)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES} ${PUBLIC_HEADER_FILES})

# does the -lpthread linking for us on Linux
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads )

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

target_include_directories(${PROJECT_NAME} PRIVATE "${PUBLIC_HEADER_DIR}/AsyncLogger/")
target_include_directories(${PROJECT_NAME} PUBLIC "${SRC_DIR}")
target_precompile_headers(${PROJECT_NAME} PRIVATE "${SRC_DIR}/common.hpp")

# public stuff
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADER_FILES}")
target_include_directories(${PROJECT_NAME} PUBLIC "${PUBLIC_HEADER_DIR}")