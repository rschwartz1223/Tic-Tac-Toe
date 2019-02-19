//
//  TicTacToe.hpp
//  Tic Tac Toe
//
//  Created by Robert Schwartz on 2/19/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdio.h>
#include <vector>
#include <string>

class TicTacToe
{
private:
    char grid[3][3];
    char empty_token;
    
public:
    //default constructor
    TicTacToe();
    //constructors
    TicTacToe(char);
    //construct game board w/previous state
    TicTacToe(char, std::vector<char>);
    //method to print the private grid member
    void print_grid();
    //player turn
    bool take_turn(int, int, char);
    //check if player has won the game
    bool is_win(char);
    //check if the game is a tie
    bool is_tie(char);
};

#endif
