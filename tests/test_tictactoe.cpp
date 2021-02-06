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

TEST(TicTacToe, makePlay) {
    TicTacToe::TicTacToe game;

    ASSERT_TRUE(game.isPlaying());
    ASSERT_EQ(game.getCurrentPlaying(), "X turn");

    game.makePlay(1, 1);
    game.changeTurn();

    ASSERT_EQ(game.getCurrentPlaying(), "O turn");

    ASSERT_ANY_THROW(game.makePlay(1, 1));
}

TEST(TicTacToe, finishGame) {
    TicTacToe::TicTacToe game;

    ASSERT_TRUE(game.isPlaying());
    ASSERT_EQ(game.getCurrentPlaying(), "X turn");

    game.makePlay(1, 1);
    game.changeTurn();

    ASSERT_EQ(game.getCurrentPlaying(), "O turn");
    game.makePlay(2, 1);
    game.changeTurn();

    ASSERT_EQ(game.getCurrentPlaying(), "X turn");

    game.makePlay(1, 2);
    game.changeTurn();

    ASSERT_EQ(game.getCurrentPlaying(), "O turn");

    game.makePlay(2, 2);
    game.changeTurn();

    ASSERT_EQ(game.getCurrentPlaying(), "X turn");

    game.makePlay(1, 3);
    game.changeTurn();

    ASSERT_FALSE(game.isPlaying());

    ASSERT_EQ(game.getWinner(), "X wins!!");
}