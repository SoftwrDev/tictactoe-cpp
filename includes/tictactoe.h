#include <string>
#include <cstdlib>
#include <exception>

#ifndef TICTACTOE
#define TICTACTOE

namespace TicTacToe {
    enum PlayOptions {
        BOARD_EMPTY = 0,
        BOARD_X = 1,
        BOARD_O = 2
    };

    struct InvalidPlayException : public std::exception {
        const char * what () const throw () {
            return "Illegal move. Play a valid one.";
        }
    } typedef InvalidPlayException;

    class TicTacToe {
        private:
            int board[3][3];
            int getBoardLength();
            bool playing;
            PlayOptions turn;
            PlayOptions winner;          
              
            bool didGameEnd() {
                bool winningScenarios[8] {
                    board[0][0] != BOARD_EMPTY && board[0][0] == board[0][1] && board[0][1] == board[0][2],
                    board[1][0] != BOARD_EMPTY && board[1][0] == board[1][1] && board[1][1] == board[1][2],
                    board[2][0] != BOARD_EMPTY && board[2][0] == board[2][1] && board[2][1] == board[2][2],
                    board[0][0] != BOARD_EMPTY && board[0][0] == board[1][0] && board[1][0] == board[2][0],
                    board[0][1] != BOARD_EMPTY && board[0][1] == board[1][1] && board[1][1] == board[2][1],
                    board[0][2] != BOARD_EMPTY && board[0][2] == board[1][2] && board[1][2] == board[2][2],
                    board[0][0] != BOARD_EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2],
                    board[0][2] != BOARD_EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]
                };

                bool* search = std::find(std::begin(winningScenarios), std::end(winningScenarios), true);
                if(search == std::end(winningScenarios)) {
                    return false;
                }
                
                playing = false;
                winner = turn;
                return true;
            }

        public:
            TicTacToe();
            std::string showBoard();
            bool isPlaying();
            std::string getCurrentPlaying();
            void changeTurn();
            void makePlay(int row, int column);
            std::string getWinner();
    };

    
    void clearConsole();
    std::tuple<int, int> parsePlay(const std::string& play);
}


#endif