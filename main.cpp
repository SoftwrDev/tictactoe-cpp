#include <iostream>
#include <tuple>
#include "tictactoe.h"

int main(int argv, char* argc[]) {
    TicTacToe::TicTacToe game;
    
    while(game.isPlaying()) {
        std::cout << game.getCurrentPlaying() << std::endl;

        std::cout << "Type a row and column - ex: r,c: ";
        std::string play;
        std::cin >> play;
        
        TicTacToe::clearConsole();

        try {
            int row, column;
            std::tie(row, column) = TicTacToe::parsePlay(play);
            std::cout << "You played " << row << std::endl;
            std::cout << "You played " << column << std::endl;
            game.makePlay(row, column);
        
            std::cout << game.showBoard();
            game.changeTurn();
        } catch(TicTacToe::InvalidPlayException& err) {
            std::cout << err.what() << std::endl;
            std::cout << game.showBoard();
        } 
        
    }
    
    std::cout << game.getWinner() << std::endl;

    return 0;
}