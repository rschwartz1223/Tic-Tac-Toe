//
//  main.cpp
//  Tic Tac Toe
//
//  Created by Robert Schwartz on 2/19/19.
//  Copyright © 2019 Robert Schwartz. All rights reserved.
//

#include "TicTacToe.hpp"
#include <iostream>
#include <vector>

int main(int argc, const char * argv[])
{
    //my game instance
    TicTacToe my_game;
    
    std::cout << "\nLet's Play Tic Tac Toe...\n\nTwo players will take turns placing their \nrespective game tokens on a 3x3 grid.\n\n";
    my_game.print_grid();
    std::cout << "The goal of a player is to fill up either a \nrow, column or diagonal with their respective \ngame token (X or O) before the other player.\n\nPlayer 'X' and Player 'O' alternate turns until \neither a tie is reached or one of the players wins.\n\n";
    
    //input for row and column values
    int r, c;
    //character tokens of each player
    std::vector<char> player_tokens = {'X', 'O'};
    //integer id of current player
    int current_player_id = 0;
    
    while(true)
    {
        std::cout << player_tokens[current_player_id] << "'s turn.\nType the ROW number for your turn [1,3], \nand press ENTER: ";
        std::cin >> r;
        std::cout << "Type your COLUMN number for your turn [1,3], \nand press ENTER: ";
        std::cin >> c;
        if(my_game.take_turn(r, c, player_tokens[current_player_id]))
        {
            my_game.print_grid();
            if(my_game.is_win(player_tokens[current_player_id]))
            {
                std::cout << "Thank you for playing, goodbye!\n";
                break;
            }
            if(my_game.is_tie(player_tokens[current_player_id]))
            {
                std::cout << "\nThank you for playing, goodbye!\n";
                break;
            }
            ++current_player_id;
            current_player_id = (current_player_id % 2 != 0) ? 1 : 0;
        }
    }
    
    return 0;
}
