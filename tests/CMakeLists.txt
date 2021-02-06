cmake_minimum_required(VERSION 3.16.3)

project(TicTacToe)

add_library(tictactoe ../src/tictactoe.cpp)

add_executable(test main.cpp)

include_directories(../includes ./includes/)

target_link_libraries(test PUBLIC gtest)
target_link_libraries(test PUBLIC gtest_main)
target_link_libraries(test PUBLIC pthread)
target_link_libraries(test PUBLIC tictactoe)