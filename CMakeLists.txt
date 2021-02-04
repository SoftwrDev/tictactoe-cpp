cmake_minimum_required(VERSION 3.16.3)

project(TicTacToe VERSION 1.0.0)

add_library(lib_tictactoe src/tictactoe.cpp)

add_executable(tictactoe main.cpp)

include_directories(includes)
target_link_libraries(tictactoe PUBLIC lib_tictactoe)