cmake_minimum_required(VERSION 3.27)
project(Cli_CMakeProjectCPP)
include_directories(${CMAKE_SOURCE_DIR}/src/include)
set(SOURCES 
    src/main.cpp
    src/suporte.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
