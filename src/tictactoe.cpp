#include <tuple>
#include <regex>
#include "tictactoe.h"

namespace TicTacToe {
    TicTacToe::TicTacToe():
        board{
            {0,0,0},
            {0,0,0},
            {0,0,0}
        }, 
        playing(true),
        turn(BOARD_X)
        {}

    bool TicTacToe::isPlaying() {
        return this->playing;
    }

    int TicTacToe::getBoardLength() {
        return sizeof(this->board) / sizeof(*this->board);
    }

    std::string TicTacToe::showBoard() {
        std::string boardRepresentation = "";
        int column = 0;

        for(int i = 0; i < this->getBoardLength(); i++) {
            for(int column = 0; column < 3; column++) {
                if(this->board[i][column] == BOARD_EMPTY) {
                    boardRepresentation.append(" - ");
                    continue;
                }
                if(this->board[i][column] == BOARD_X) {
                    boardRepresentation.append(" X ");
                    continue;
                }
                if(this->board[i][column] == BOARD_O) {
                    boardRepresentation.append(" O ");
                    continue;
                }
                boardRepresentation.append(" - ");
            }
            boardRepresentation.append("\n");
        }

        return boardRepresentation.substr(0, boardRepresentation.size() - 1);
    }

    std::string TicTacToe::getCurrentPlaying() {
        return turn == BOARD_X ? "X turn" : "O turn";
    }

    void TicTacToe::changeTurn() {
        if(didGameEnd()) return;
        turn = turn == BOARD_X ? BOARD_O : BOARD_X;
    }

    void TicTacToe::makePlay(int row, int column) {
        row--;
        column--;
        if(row >= 0 && row <=2 && column >= 0 && column <= 2) {
            if(board[row][column] != BOARD_EMPTY) {
                throw InvalidPlayException();
            }
            board[row][column] = turn == BOARD_X ? BOARD_X : BOARD_O;
            return;
        } 
        throw InvalidPlayException();
    }

    std::string TicTacToe::getWinner() {
        return winner == BOARD_X ? "X wins!!" : "O wins!!";
    }
    
    void clearConsole() {
        #ifdef _WIN32
            system("cls");
        #endif

        #ifdef __linux__
            system("clear");
        #endif
    }

    std::tuple<int, int> parsePlay(const std::string& play) {
        std::cmatch m;

        std::regex_match(play.c_str(), m, std::regex("[1-3],[1-3]"));

        if(m.size() == 0) {
            throw InvalidPlayException();
        }

        std::string delimiter = ",";
        size_t row_t = play.find(delimiter, 0);
        size_t start_t = row_t + delimiter.length();

        std::string row = play.substr(0, play.find(delimiter, 0));
        std::string column = play.substr(start_t, play.find(delimiter, 0));

        return std::make_tuple(std::atoi(row.c_str()), std::atoi(column.c_str()));
    }
};
