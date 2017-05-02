cmake_minimum_required(VERSION 3.3)

project(Coroutine)

set(CMAKE_BUILD_TYPE Debug)

set(BUILD_ROOT "${CMAKE_SOURCE_DIR}/build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")

set(SourceDir ${PROJECT_SOURCE_DIR}/src)

file(GLOB SOURCES "src/*")

include_directories(include)

add_executable(Coroutine ${SOURCES})
