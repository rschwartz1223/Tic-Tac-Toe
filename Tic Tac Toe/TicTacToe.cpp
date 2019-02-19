//
//  TicTacToe.cpp
//  Tic Tac Toe
//
//  Created by Robert Schwartz on 2/19/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#include "TicTacToe.hpp"
#include <iostream>
#include <vector>

//default constructor
TicTacToe ::TicTacToe()
{
    this->empty_token = '-';
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            this->grid[i][j] = '-';
}
//constructor
TicTacToe::TicTacToe(char _empty_token)
{
    this->empty_token = _empty_token;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            this->grid[i][j] = _empty_token;
}
//constructor for previous save state
TicTacToe::TicTacToe(char _empty_token, std::vector<char> init_tokens)
{
    this->empty_token = _empty_token;
    if(init_tokens.size() == 9)
    {
        int counter = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                this->grid[i][j] = init_tokens[counter++];
    }
    else
    {
        std::cout << "WARNING: Previous game board state must be initialized with 9 tokens.\n";
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                this->grid[i][j] = _empty_token;
    }
}
//print current grid state
void TicTacToe::print_grid()
{
    int row_counter = 1;
    std::cout << "  1 2 3" << std::endl;
    for(int i = 0; i < 3; i++)
    {
        std::cout << row_counter++ << " ";
        for(int j = 0; j < 3; j++)
            std::cout << this->grid[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
//player turn
bool TicTacToe::take_turn(int rownum, int colnum, char player_token)
{
    //check for valid grid position
    if(rownum < 1 || rownum > 3 || colnum < 1 || colnum > 3)
    {
        std::cout << "ERROR: Row and Column positions must be entered in range [1,3]. Please enter a valid position.\n";
        return false;
    }
    //check to see if grid position is not already filled
    if(this->grid[rownum - 1][colnum - 1] == this->empty_token)
    {
        this->grid[rownum - 1][colnum - 1] = player_token;
        return true;
    }
    else
    {
        std::cout << "ERROR: This position is currently occupied by " << this->grid[rownum - 1][colnum - 1] << " . Please enter an unoccupied position.\n";
        return false;
    }
}
//check for winning position
bool TicTacToe::is_win(char player_token)
{
    //check first row
    if(this->grid[0][0] == player_token &&
       this->grid[0][1] == player_token &&
       this->grid[0][2] == player_token)
    {
        std::cout << player_token << " has won on the first row.\n";
        return true;
    }
    //check second row
    else if(this->grid[1][0] == player_token &&
            this->grid[1][1] == player_token &&
            this->grid[1][2] == player_token)
    {
        std::cout << player_token << " has won on the second row.\n";
        return true;
    }
    //check third row
    else if(this->grid[2][0] == player_token &&
            this->grid[2][1] == player_token &&
            this->grid[2][2] == player_token)
    {
        std::cout << player_token << " has won on the third row.\n";
        return true;
    }
    //check first column
    else if(this->grid[0][0] == player_token &&
            this->grid[1][0] == player_token &&
            this->grid[2][0] == player_token)
    {
        std::cout << player_token << " has won on the first column.\n";
        return true;
    }
    //check second column
    else if(this->grid[0][1] == player_token &&
            this->grid[1][1] == player_token &&
            this->grid[2][1] == player_token)
    {
        std::cout << player_token << " has won on the second column.\n";
        return true;
    }
    //check third column
    else if(this->grid[0][2] == player_token &&
            this->grid[1][2] == player_token &&
            this->grid[2][2] == player_token)
    {
        std::cout << player_token << " has won on the third column.\n";
        return true;
    }
    //check first diagonal
    else if(this->grid[0][0] == player_token &&
            this->grid[1][1] == player_token &&
            this->grid[2][2] == player_token)
    {
        std::cout << player_token << " has won on the first diagonal.\n";
        return true;
    }
    //check second diagonal
    else if(this->grid[0][2] == player_token &&
            this->grid[1][1] == player_token &&
            this->grid[2][0] == player_token)
    {
        std::cout << player_token << " has won on the second diagonal.\n";
        return true;
    }
    return false;
}
//check for current tie
bool TicTacToe::is_tie(char player_token)
{
    if(this->is_win(player_token))
        return false;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(this->grid[i][j] == this->empty_token)
                return false;
    std::cout << "The game is a tie.\n";
    return true;
    
}
