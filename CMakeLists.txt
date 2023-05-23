cmake_minimum_required(VERSION 3.10)

project(SequenceDiagramGenerator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)
find_package(benchmark REQUIRED)

set(SRC_FILES
        main.cpp
#        qml.qrc
        )

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick benchmark::benchmark)
