#include <gtest/gtest.h>
#include <tuple>
#include "tictactoe.h"

TEST(TicTacToe, parsePlay) {
    int row, column;
    std::tie(row, column) = TicTacToe::parsePlay("1,2");
    ASSERT_EQ(row, 1);
    ASSERT_EQ(column, 2);
}