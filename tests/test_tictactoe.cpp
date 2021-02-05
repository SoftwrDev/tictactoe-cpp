#include <gtest/gtest.h>
#include <tuple>
#include "tictactoe.h"

TEST(TicTacToe, parsePlay) {
    int row, column;
    std::tie(row, column) = TicTacToe::parsePlay("1,2");
    ASSERT_EQ(row, 1);
    ASSERT_EQ(column, 2);

    std::tie(row, column) = TicTacToe::parsePlay("1,1");
    ASSERT_EQ(row, 1);
    ASSERT_EQ(column, 1);

    std::tie(row, column) = TicTacToe::parsePlay("3,1");
    ASSERT_EQ(row, 3);
    ASSERT_EQ(column, 1);

    ASSERT_ANY_THROW(TicTacToe::parsePlay("1,x"));
    ASSERT_ANY_THROW(TicTacToe::parsePlay("10,10"));
    ASSERT_ANY_THROW(TicTacToe::parsePlay("1x1"));
}