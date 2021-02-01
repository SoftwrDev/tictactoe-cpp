#include <iostream>
#include <exception>
#include "tictactoe.h"

int main(int argv, char* argc[]) {
    TicTacToe::TicTacToe game;
    
    while(game.isPlaying()) {
        std::cout << game.getCurrentPlaying() << std::endl;
        std::cout << "Type a row and column - ex: r,c: ";
        std::string play;
        std::cin >> play;
        TicTacToe::clearConsole();

        std::string delimiter = ",";
        size_t row_t = play.find(delimiter, 0);
        size_t start_t = row_t + delimiter.length();

        std::string row = play.substr(0, play.find(delimiter, 0));
        std::string column = play.substr(start_t, play.find(delimiter, 0));

        std::cout << "You played " << row << std::endl;
        std::cout << "You played " << column << std::endl;
        
        try {
            game.makePlay(std::atoi(row.c_str()), std::atoi(column.c_str()));
            std::cout << game.showBoard() << std::endl;
            game.changeTurn();
        } catch(TicTacToe::InvalidPlayException& err) {
            std::cout << err.what() << std::endl;
            std::cout << game.showBoard() << std::endl;
        } 
        
    }
    
    std::cout << game.getWinner() << std::endl;

    return 0;
}