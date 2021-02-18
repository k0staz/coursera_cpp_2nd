cmake_minimum_required(VERSION 3.13)
project(FinalP2)

set(CMAKE_CXX_STANDARD 17)

add_executable(FinalP2 main.cpp token.h token.cpp condition_parser.cpp condition_parser.h date.cpp date.h database.cpp database.h node.cpp node.h test_runner.cpp test_runner.h condition_parser_test.cpp)