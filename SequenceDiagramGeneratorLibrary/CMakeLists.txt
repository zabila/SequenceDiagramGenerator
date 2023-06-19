cmake_minimum_required(VERSION 3.20)

project(SequenceDiagramGeneratorLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

# Tests
option(TEST_ENABLED "Enable tests" ON)
find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (TEST_ENABLED)
    enable_testing()
    add_subdirectory(test)
endif ()