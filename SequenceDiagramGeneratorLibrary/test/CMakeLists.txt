cmake_minimum_required(VERSION 3.20)

enable_testing()

add_executable(SequenceDiagramGeneratorLibraryTest main.cpp)

target_link_libraries(SequenceDiagramGeneratorLibraryTest SequenceDiagramGeneratorLibrary)

add_test(NAME my_test COMMAND myapp_tests)