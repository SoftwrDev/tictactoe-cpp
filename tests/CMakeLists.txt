cmake_minimum_required(VERSION 3.16.3)

project(TicTacToe)

include(GoogleTest)
add_library(lib_tictactoe ../src/tictactoe.cpp)

add_executable(test main.cpp)

include_directories(../includes /usr/include/google_test/)

target_link_libraries(test PUBLIC gtest)
target_link_libraries(test PUBLIC gtest_main)
target_link_libraries(test PUBLIC pthread)
target_link_libraries(test PUBLIC lib_tictactoe)